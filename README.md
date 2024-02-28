Generateur de fichier pour la piscine C++

Ce programme permet de générer des fichiers de code C++ de manière automatique, facilitant ainsi le processus de création de nouveaux fichiers lors de la piscine C++.
Installation

    Déplacer le repo dans le dossier personnel 42 : Copiez le dépôt dans le dossier /sgoinfre/goinfre/Perso/<votre login>.

    Modifier le fichier genfile.sh : Ouvrez le fichier genfile.sh et modifiez la variable SOURCES_PATH pour qu'elle pointe vers /sgoinfre/goinfre/Perso/<votre login>.

    Configurer l'alias : Ouvrez le fichier ~/.zshrc avec un éditeur de texte et ajoutez la ligne suivante à la fin du fichier :

    bash

alias genfile='/sgoinfre/goinfre/Perso/<votre login>/newClassGenerator/genfile.sh'

Appliquer les modifications : Enregistrez et quittez l'éditeur de texte, puis exécutez la commande suivante pour appliquer les modifications :

bash

    source ~/.zshrc

    Relancer le terminal : Fermez et relancez votre terminal pour prendre en compte les changements.

Utilisation

Pour utiliser le programme, lancez la commande genfile suivi du nom du fichier que vous souhaitez créer, suivi d'une des options suivantes :

    c : Crée un fichier .cpp.
    h : Crée un fichier .hpp et un fichier .cpp.
    m : Crée un fichier main.cpp incluant le fichier .hpp.
    genfile make : Crée un fichier Makefile.
    all : Crée les quatre types de fichiers (hpp, cpp, main.cpp, Makefile).

Le programme ajuste automatiquement la première lettre du nom de fichier pour la mettre en majuscule si ce n'est pas déjà le cas.
Exemple

Pour créer un fichier MaClasse, vous pouvez utiliser les commandes suivantes :

    genfile MaClasse c : Crée un fichier MaClasse.cpp.
    genfile MaClasse h : Crée des fichiers MaClasse.hpp et MaClasse.cpp.
    genfile MaClasse m : Crée un fichier main.cpp incluant #include "MaClasse.hpp".
    genfile make : Crée un fichier Makefile.
    genfile MaClasse all : Crée tous les fichiers pour la classe MaClasse.

N'hésitez pas à personnaliser ce README en ajoutant des informations supplémentaires ou en le modifiant selon vos besoins spécifiques.
