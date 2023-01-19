#ifndef AFFICHEUR
#define AFFICHEUR

#include <Arduino.h>
#include "DHT.h"
#include <LiquidCrystal.h>
#include "Enum.h"

/*
Gestion de l'affichage sur l'écran critaux liquide
*/
class Afficheur
{
private:
  // initialize the library with the numbers of the interface pins
  LiquidCrystal *lcd;
  unsigned long debutMarche;
  unsigned long lastDisplay = 0;
  EtatEnum lastEtat = ARRETER;
  DHT *dht;

  // afficher l'état
  void printStatus(EtatEnum etat, unsigned long ms) 
  {
      if (lastEtat != etat) {
          lastEtat = etat;
          lcd->clear();
      }

      lcd->setCursor(0, 0);
      lcd->print(EtatString.getEtat(etat));


      switch (etat)
      {
      case MARCHE:
          lcd->print(" ");
          displayTime(ms);
          break;
      case DEMARRAGE:
      case ARRET:
      case ARRETER:
          break;
      default:
          lcd->print("ERROR");
      }
  }
  //afficher le temps depuis le démarrage
  void displayTime(unsigned long ms)
  {
      auto milliseconds = ms - this->debutMarche;
      auto seconds = milliseconds / 1000;
      milliseconds %= 1000;

      auto minutes = seconds / 60;
      seconds %= 60;

      auto hours = minutes / 60;
      minutes %= 60;

      char* time = "00:00:00";
      sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);

      lcd->print(time);
  }
  // afficher la temperature
  void printTemp()
  {

      float t = dht->readTemperature();
      float h = dht->readHumidity();
      lcd->setCursor(0, 1);
      lcd->print(t);
      lcd->print((char)223);// afficher le °
      lcd->print("C, ");
      lcd->print(h);
      lcd->print("%");
  }

public:
  Afficheur(DHT* dht)
  {
      // A faire: mettre les pins en contantes dans le fichier pin.h
      lcd = new LiquidCrystal(9, 8, 7, 6, 5, 4);
      this->dht = dht;

      lcd->begin(16, 2);
      lcd->setCursor(0, 0);
      lcd->print("Initialisation");
  }
  void setup(unsigned long debutMarche)
  {
      this->debutMarche = debutMarche;

      dht->begin();
  }
  void loop(EtatEnum etat, unsigned long ms)
  {
      // limiter la mise a jour de l'affichage (une fois par seconde)
      if ((ms - lastDisplay) > 1000) {
          lastDisplay = ms;
          printStatus(etat, ms);
          printTemp();
      }
  }
};

#endif