#ifndef ENUM
#define ENUM

/*
liste tous les �tat possibles
*/

enum numerals_t : char {
    Zero,
    One,
    Two,
    Three
};
enum EtatEnum
{
    //D�marrage
    DEMARRAGE,
    //Marche
    MARCHE,
    //Arret en cours
    ARRET,
    //arreter
    ARRETER,
    // A faire: gestion des erreur. Si probleme d'allumage ou manque de granul�s pendant la marche etc...
    ERREUR
};

/*
    corespondances des �tats pour l'affichage
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