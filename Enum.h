#ifndef ENUM
#define ENUM

/*
liste tous les état possibles
*/

enum numerals_t : char {
    Zero,
    One,
    Two,
    Three
};
enum EtatEnum
{
    //Démarrage
    DEMARRAGE,
    //Marche
    MARCHE,
    //Arret en cours
    ARRET,
    //arreter
    ARRETER,
    // A faire: gestion des erreur. Si probleme d'allumage ou manque de granulés pendant la marche etc...
    ERREUR
};

/*
    corespondances des états pour l'affichage
*/
struct {
private:
    String etats[4] = { "Demarrage","Marche","Arret","Arreter" };
public:
    String getEtat(int etat) {
        return etats[etat];
    }
} EtatString;





#endif