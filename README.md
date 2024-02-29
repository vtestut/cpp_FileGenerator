# cpp_FileGenerator

#### Générerateur automatique de fichier pour la piscine C++
&emsp;


Vous pouvez personnaliser vos templates en modifiant les fichiers dans le dossier `Templates`

&emsp;
## ⚙️&emsp;Installation ( à 42 )&emsp;⚙️
&emsp;
1.  Télécharger ou déplacer le repo dans le dossier /sgoinfre/goinfre/Perso/***\<VOTRE_LOGIN_42\>***

2. Ouvrir `genfile.sh` et modifier la variable `MY_LOGIN` avec votre login 

3. Modifier zshrc ou bashrc :

       nano ~/.zshrc

&emsp;A la fin du fichier, ajouter votre login et copier l'alias :

       alias genfile='/sgoinfre/goinfre/Perso/<VOTRE_LOGIN_42>/cpp_FileGenerator/genfile.sh'
  
4. Quitter le terminal ou exécuter :

       source ~/.zshrc

&emsp;
##  🛠️&emsp;Utilisation&emsp;🛠️
&emsp;
Exécuter la commande `genfile` suivi du `fileName` suivi d'une des options suivantes :
- `c`&emsp;&emsp;:&emsp;&emsp;Crée un fichier .cpp.
- `h`&emsp;&emsp;:&emsp;&emsp;Crée un fichier .hpp **ET** un fichier .cpp.
- `m`&emsp;&emsp;:&emsp;&emsp;Crée un fichier main.cpp qui va \#include "\<fileName\>.hpp".
- `all`&emsp;:&emsp;&emsp;Crée les quatre types de fichiers (hpp, cpp, main et Makefile).
- `make` :&emsp;&emsp; Crée un Makefile. ( ⚠️ `genfile make` , sans `fileName` ⚠️ )

&emsp;

Le programme passe la première lettre `fileName` en uppercase si ce n'est pas déjà le cas.

&emsp;

⚠️&emsp;Attention, en appelant genfile avec avec un nom de `fileName` qui existe déjà, ca va écraser et remplacer sans vous avertir 

&emsp;&emsp;(par exemple, un Makefile).
&emsp;

&emsp;

## 💡&emsp;Exemple&emsp;💡

Pour créer un fichier MaClasse, vous pouvez utiliser les commandes suivantes :

    genfile maClasse c   : Crée un fichier MaClasse.cpp.
    genfile maClasse h   : Crée des fichiers MaClasse.hpp et MaClasse.cpp.
    genfile maClasse m   : Crée un fichier main.cpp incluant #include "MaClasse.hpp".
    genfile make         : Crée un fichier Makefile.
    genfile maClasse all : Crée tous les fichiers pour la classe MaClasse.

