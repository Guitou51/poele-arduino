# poele-arduino

Gestion d'un poele a granulé

## Modifier les delais d'allumage

Ouvrir le fichier 'EtatDemarrage.h'. Modifier le constante DELAI_ALLIMENTATION_PELLET et DELAI_CHAUFFE_BOUGIE.

## Modifier le rapport cyclique de la vis

*Periode* = temps totale ON + OFF</br>
*Rapport* = temps ON / temps OFF

si periode est 1000 ms et rapport est 0.2 alors temps ON = 200ms et temps OFF = 800ms

Modifier la periode dans 'Vis.s' modifer la valeur de PERIODE_VIS;

Modifier le rapport en marche dans le fichier 'EtatMarche.h' fonction onEnter.


## Modifier le delai d'arret

Dans le fichier 'EtatArret.h', modifer la valeur de DELAI_ARRET