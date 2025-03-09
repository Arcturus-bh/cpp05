NAME = ex02

SRC = main.cpp \
	  src/Bureaucrat.cpp \
	  src/AForm.cpp \
	  src/ShrubberyCreationForm.cpp \
	  src/PresidentialPardonForm.cpp \
	  src/RobotomyRequestForm.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98 -I include/ -g -fsanitize=address

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@${CC} $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re