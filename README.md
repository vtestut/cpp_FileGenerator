# cpp_FileGenerator

#### Generateur de fichier pour la piscine C++
&emsp;

Ce programme permet de générer des fichiers de code C++ de manière automatique.

Vous pouvez personnaliser vos templates en modifiant les fichiers dans 'model'

&emsp;
## ⚙️&emsp;Installation ( à 42 )
&emsp;
1.  Télécharger ou déplacer le repo dans le dossier /sgoinfre/goinfre/Perso/***\<VOTRE_LOGIN_42\>***

2. Ouvrir le fichier genfile.sh et modifier la variable SOURCES_PATH pour qu'elle pointe vers :

    - /sgoinfre/goinfre/Perso/***\<VOTRE_LOGIN_42\>***

4. En fonction de votre shell, exécuter la commande suivante : 
    - `nano ~/.zsrhc`
    - `nano ~/.bashrc`

5. A la fin du fichier, ajouter la ligne suivante pour configurer un alias :
    - `alias genfile='/sgoinfre/goinfre/Perso/<VOTRE_LOGIN_42>/cpp_FileGenerator/genfile.sh'`

6. Enregistrer et quitter l'éditeur avec ctrl+X, Y, Enter
   
7. Relancer un nouveau terminal ou exécuter la commande suivante :
    - `source ~/.zsrhc`

&emsp;
##  🛠️&emsp;Utilisation
&emsp;
Exécuter la commande `genfile` suivi du `fileName` suivi d'une des options suivantes :
- `c` :&emsp;&emsp;Crée un fichier .cpp.
- `h` :&emsp;&emsp;Crée un fichier .hpp **ET** un fichier .cpp.
- `m` :&emsp;&emsp;Crée un fichier main.cpp qui va \#include "\<fileName\>.hpp".
- `all` :&emsp;Crée les quatre types de fichiers (hpp, cpp, main et Makefile).
- &emsp;⚠️&emsp;&emsp;`genfile make` : Crée un Makefile. ( pas de \<fileName\>, 1 seul arugment )

Le programme ajuste automatiquement la première lettre du nom de fichier pour la mettre en majuscule si ce n'est pas déjà le cas.
&emsp;

&emsp;
## 💡&emsp;Exemple

Pour créer un fichier MaClasse, vous pouvez utiliser les commandes suivantes :

    genfile maClasse c : Crée un fichier MaClasse.cpp.
    genfile maClasse h : Crée des fichiers MaClasse.hpp et MaClasse.cpp.
    genfile maClasse m : Crée un fichier main.cpp incluant #include "MaClasse.hpp".
    genfile make : Crée un fichier Makefile.
    genfile maClasse all : Crée tous les fichiers pour la classe MaClasse.

## Happy coding 🚀

vtestut
