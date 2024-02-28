# cpp_FileGenerator

#### Générerateur automatique de fichier pour la piscine C++
&emsp;


⚠️&emsp;Vous pouvez personnaliser vos templates en modifiant les fichiers dans le dossier `Templates`

&emsp;
## ⚙️&emsp;Installation ( à 42 )&emsp;⚙️
&emsp;
1.  Télécharger ou déplacer le repo dans le dossier /sgoinfre/goinfre/Perso/***\<VOTRE_LOGIN_42\>***

2. Ouvrir le fichier genfile.sh et modifier la variable MY_LOGIN avec votre login 42 

3. Exécuter la commande suivante :

       nano ~/.zsrhc

4. A la fin du fichier, ajouter la ligne suivante pour configurer un alias :

       alias genfile='/sgoinfre/goinfre/Perso/<VOTRE_LOGIN_42>/cpp_FileGenerator/genfile.sh'

5. Enregistrer et quitter avec ctrl+X, Y, Enter
   
6. Relancer un nouveau terminal ou exécuter la commande suivante :

       source ~/.zsrhc

&emsp;
##  🛠️&emsp;Utilisation&emsp;🛠️
&emsp;
Exécuter la commande `genfile` suivi du `fileName` suivi d'une des options suivantes :
- `c` :&emsp;&emsp;Crée un fichier .cpp.
- `h` :&emsp;&emsp;Crée un fichier .hpp **ET** un fichier .cpp.
- `m` :&emsp;&emsp;Crée un fichier main.cpp qui va \#include "\<fileName\>.hpp".
- `all` :&emsp;Crée les quatre types de fichiers (hpp, cpp, main et Makefile).
- &emsp;⚠️&emsp;&emsp;`genfile make` : Crée un Makefile. ( pas de \<fileName\>, 1 seul arugment )

Le programme passe la première lettre `fileName` en uppercase si ce n'est pas déjà le cas.
&emsp;

&emsp;
## 💡&emsp;Exemple&emsp;💡

Pour créer un fichier MaClasse, vous pouvez utiliser les commandes suivantes :

    genfile maClasse c : Crée un fichier MaClasse.cpp.
    genfile maClasse h : Crée des fichiers MaClasse.hpp et MaClasse.cpp.
    genfile maClasse m : Crée un fichier main.cpp incluant #include "MaClasse.hpp".
    genfile make : Crée un fichier Makefile.
    genfile maClasse all : Crée tous les fichiers pour la classe MaClasse.

## Happy coding 🚀

vtestut
