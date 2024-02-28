NAME	= a.out
CPP		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++17
SRCDIR	= sources
OBJDIR	= objects
SRCS	= $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(SRCDIR)/*.hpp)
OBJS	= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

all: ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CPP) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	$(CPP) $(FLAGS) ${OBJS} -o $@

clean:
	@rm -rf ${OBJDIR}		

fclean: clean
	@if [ -f ${NAME} ]; then rm ${NAME}; fi
	@if [ -d "output" ]; then rm -r output; fi
	@echo "fclean success"

re: fclean ${NAME}

.PHONY: all clean fclean re
