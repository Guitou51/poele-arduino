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
  void printStatus(EtatEnum etat, unsigned long ms);
  //afficher le temps depuis le démarrage
  void displayTime(unsigned long ms);
  // afficher la temperature
  void printTemp();

public:
  Afficheur(DHT* dht);
  void setup(unsigned long debutMarche);
  void loop(EtatEnum etat, unsigned long ms);
};

#endif