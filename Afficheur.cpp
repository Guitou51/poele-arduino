#include "Afficheur.h"

Afficheur::Afficheur(DHT* dht)
{
    // A faire: mettre les pins en contantes dans le fichier pin.h
    lcd = new LiquidCrystal(9, 8, 7, 6, 5, 4);
    this->dht = dht;

    lcd->begin(16, 2);
    lcd->setCursor(0, 0);
    lcd->print("Initialisation");
}

void Afficheur::setup(unsigned long debutMarche)
{
    this->debutMarche = debutMarche;

    dht->begin();
}
void Afficheur::loop(EtatEnum etat, unsigned long ms)
{
    // limiter la mise a jour de l'affichage (une fois par seconde)
    if ((ms - lastDisplay) > 1000) {
        lastDisplay = ms;
        printStatus(etat, ms);
        printTemp();
    }
}

void Afficheur::printStatus(EtatEnum etat, unsigned long ms)
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

void Afficheur::displayTime(unsigned long ms)
{
    unsigned long milliseconds = ms - this->debutMarche;
    int seconds = milliseconds / 1000;
    milliseconds %= 1000;

    int minutes = seconds / 60;
    seconds %= 60;

    int hours = minutes / 60;
    minutes %= 60;

    char* time = "00:00:00";
    sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);

    lcd->print(time);
}

void Afficheur::printTemp()
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