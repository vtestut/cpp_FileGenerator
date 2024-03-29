NAME	= a.out
CXX		= c++

FLAGS	=	-Wall
FLAGS	+=	-Wextra
FLAGS	+=	-Werror
FLAGS	+=	-std=c++17

SRCDIR	= sources
OBJDIR	= objects

SOURCES	= $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(SRCDIR)/*.hpp)
OBJECTS	= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(FLAGS) -c $< -o $@

${NAME}: ${OBJECTS}
	$(CXX) $(FLAGS) ${OBJECTS} -o $@

clean:
	@rm -rf ${OBJDIR}		

fclean: clean
	@if [ -f ${NAME} ]; then rm ${NAME}; fi
	@if [ -d "output" ]; then rm -r output; fi
	@echo "make fclean : done"

re: fclean ${NAME}

.PHONY: all clean fclean re

#***************************************************#
#*				AUTOMATIC VARIABLES					#
#***************************************************#

#*	$@ :	Le nom du fichier cible de la règle
#			Par exemple, dans la règle prog: main.o util.o, $@ serait prog
# 
#*	$< :	Le nom du premier prérequis de la règle
#			Par exemple, dans la règle prog: main.o util.o, $< serait main.o
# 
#*	$^ :	La liste de tous les prérequis de la règle
#			Par exemple, dans la règle prog: main.o util.o, $^ serait main.o util.o
# 
#*	$* :	Le nom du fichier sans son suffixe
#			Par exemple, dans la règle prog.o: prog.c, $* serait prog
# 
#* 	$? :	La liste de tous les prérequis qui sont plus récents que la cible.
#			Par exemple, si main.o a été modifié plus récemment que prog, alors dans la règle prog: main.o util.o, $? serait main.o
# 
#*	$+ :	Cette variable est similaire à $^, mais elle inclut les dépendances avec les duplicatas préservés.
#			Utile pour utiliser plusieurs fois la même dépendance pour une règle
# 
#*	$% :	Lorsque la cible est une archive (fichier .a), cette variable représente le nom du membre de l'archive.
#			Par exemple, dans la règle lib.a(lib.o): lib.o, $% serait lib.o
#
#*	$| :	Cette variable contient la liste des prérequis d'ordre.
#			Les prérequis d'ordre sont ceux qui apparaissent après une barre verticale | dans une règle.
#			Ils sont utilisés pour spécifier des prérequis qui ne sont pas nécessairement mis à jour, mais qui, s'ils sont modifiés, 
#			doivent forcer la mise à jour de la cible.
# 
#* $(@D) et $(<D) :	Ces variables représentent respectivement le répertoire de la cible et le répertoire du premier prérequis.
#					Par exemple, si la cible est dir/file, alors $(@D) serait dir
# 
#* $(@F) et $(<F) : Ces variables représentent respectivement le nom du fichier de la cible et le nom du 
#*					fichier du premier prérequis, sans le répertoire. 
#					Par exemple, si la cible est dir/file, alors $(@F) serait file.