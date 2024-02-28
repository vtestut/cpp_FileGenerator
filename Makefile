NAME	= a.out
CXX		= c++

FLAGS	=	-Wall
FLAGS	+=	-Wextra
FLAGS	+=	-Werror
FLAGS	+=	-std=c++17

SRCDIR	= sources
OBJDIR	= objects

SRCS	= $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(SRCDIR)/*.hpp)
OBJS	= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

all: ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	$(CXX) $(FLAGS) ${OBJS} -o $@

clean:
	@rm -rf ${OBJDIR}		

fclean: clean
	@if [ -f ${NAME} ]; then rm ${NAME}; fi
	@if [ -d "output" ]; then rm -r output; fi
	@echo "fclean success"

re: fclean ${NAME}

.PHONY: all clean fclean re
