NAME	=	a.out
CXX		=	c++

FLAGS	=	-Wall
FLAGS	+=	-Wextra
FLAGS	+=	-Werror
FLAGS	+=	-std=c++98

SRCDIR	=	.
# HDRDIR	=	includes
OBJDIR	=	objs

SOURCES	=	$(wildcard $(SRCDIR)/*.cpp)
HEADERS =	$(wildcard $(SRCDIR)/*.hpp)
OBJECTS	=	$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

#****************************************************#
#*						RULES						*#
#****************************************************#

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
	@echo "make fclean : done"

re: fclean ${NAME}

.PHONY: all clean fclean re
