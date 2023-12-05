NAME		=	easyfind

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic-errors

#directories
SRC_DIR					=	src/
OBJ_DIR					=	obj/
INC_DIR					=	include/
CURRENT_PATH			=	$(shell pwd)
CURRENT_DIRECTORY_NAME	=	$(shell basename $(CURRENT_PATH))
CURRENT_DIRECTORY		:=	./$(CURRENT_DIRECTORY_NAME)

#controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)
	@printf "\n"
	@printf "$(GREEN)                  EEEEEEEEEEEEEEEEEEEEEE\n$(RESET)"
	@printf "$(GREEN)      <<<<<<<     E::::::::::::::::::::E                      >>>>>>>      \n$(RESET)"
	@printf "$(GREEN)     <:::::<      E::::::::::::::::::::E                       >:::::>     \n$(RESET)"
	@printf "$(GREEN)    <:::::<       EE::::::EEEEEEEEE::::E                        >:::::>    \n$(RESET)"
	@printf "$(GREEN)   <:::::<          E:::::E       EEEEEEzzzzzzzzzzzzzzzzz        >:::::>   \n$(RESET)"
	@printf "$(GREEN)  <:::::<           E:::::E             z:::::::::::::::z         >:::::>  \n$(RESET)"
	@printf "$(GREEN) <:::::<            E::::::EEEEEEEEEE   z::::::::::::::z           >:::::> \n$(RESET)"
	@printf "$(GREEN)<:::::<             E:::::::::::::::E   zzzzzzzz::::::z             >:::::>\n$(RESET)"
	@printf "$(GREEN) <:::::<            E:::::::::::::::E         z::::::z             >:::::> \n$(RESET)"
	@printf "$(GREEN)  <:::::<           E::::::EEEEEEEEEE        z::::::z             >:::::>  \n$(RESET)"
	@printf "$(GREEN)   <:::::<          E:::::E                 z::::::z             >:::::>   \n$(RESET)"
	@printf "$(GREEN)    <:::::<         E:::::E       EEEEEE   z::::::z             >:::::>    \n$(RESET)"
	@printf "$(GREEN)     <:::::<      EE::::::EEEEEEEE:::::E  z::::::zzzzzzzz      >:::::>     \n$(RESET)"
	@printf "$(GREEN)      <<<<<<<     E::::::::::::::::::::E z::::::::::::::z     >>>>>>>      \n$(RESET)"
	@printf "$(GREEN)                  E::::::::::::::::::::Ez:::::::::::::::z                  \n$(RESET)"
	@printf "$(GREEN)                  EEEEEEEEEEEEEEEEEEEEEEzzzzzzzzzzzzzzzzz                  \n$(RESET)"
	@printf "\n"

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from $(CURRENT_DIRECTORY)...$(RESET)"; else \
	echo "No objects to remove from $(CURRENT_DIRECTORY)."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(RED)$(NAME)$(BLUE) binary from $(CURRENT_DIRECTORY)$(RESET)"; else \
	echo "No Executable to remove from $(CURRENT_DIRECTORY)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re