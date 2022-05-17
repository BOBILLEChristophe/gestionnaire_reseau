# Gestionnaire de réseau

Ce projet est une étude de gestionnaire de réseau fonctionnant avec DCC (et en particulier DCC++).

Il est prévu pour fonctionner sur un bus CAN. C’est par ce bus que transitent en effet toutes les informations de capteurs et les ordres envoyés aux aiguilles en particulier. Chaque zone disposant de son propre satellite (https://www.locoduino.org/spip.php?article243).

Il a pour objectif de commander la signalisation en fonction de l’occupation des zones et du sens de roulage des trains.

Il doit permettre également de commander les locomotives en fonction de l’état du réseau : occupation des zones suivantes (en fonction du sens) zone +1, zone +2, le sens pour aborder les aiguilles (Talon, pied droit ou pied dévié) et bien sûr la position des aiguilles (droites ou déviées).

Bien que cela ne soit pas l’objectif visé, la commande automatique des trains sera facile à implémenter.



