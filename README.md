# cpp_FileGenerator

#### Générerateur automatique de fichier pour la piscine C++
&emsp;


Vous pouvez personnaliser vos fichiers dans le dossier `templates` 

&emsp;
## ⚙️&emsp;Installation ( à 42 )&emsp;⚙️
&emsp;
1. Télécharger ou déplacer le repo dans le dossier `/sgoinfre/goinfre/Perso/<login>` :

       cp -r cpp_FileGenerator /sgoinfre/goinfre/Perso/<login>
   

3. Ouvrir `genfile.sh` et modifier `MY_LOGIN`
   

5. Modifier zshrc ou bashrc :

       nano ~/.zshrc

&emsp;A la fin du fichier, ajouter votre login et copier l'alias :&emsp;&emsp;*ctrl+X, Y, Entrer pour save*

       alias genfile='/sgoinfre/goinfre/Perso/<LOGIN>/cpp_FileGenerator/genfile.sh'
  
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

Le programme passe la première lettre de `fileName` en uppercase si ce n'est pas déjà le cas.
&emsp;

⚠️&emsp;En appelant genfile avec avec un nom de `fileName` qui existe déjà, ca va écraser et remplacer sans vous avertir


    genfile maClasse c    crée MaClasse.cpp
    genfile maClasse h    crée des fichiers MaClasse.hpp et MaClasse.cpp
    genfile maClasse m    crée un fichier main.cpp qui #include "MaClasse.hpp"
    genfile make          crée un Makefile

