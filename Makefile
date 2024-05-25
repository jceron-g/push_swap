# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 10:34:28 by jceron-g          #+#    #+#              #
#    Updated: 2024/05/25 11:08:19 by jceron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
USER = jceron-g
CC = gcc -g
CFLAGS = -Wextra -Wall -Werror 
LIBFT = lib/libft
SRC_DIR = src/
OBJ_DIR = obj/
SRC_DIR_BONUS = src_bonus/

DEF_COLOR = \033[0;39m
MAGENTA   = \033[35;1m
YELLOW    = \033[33;1m
GREEN     = \033[32;1m
WHITE     = \033[37;1m
RESET     = \033[0m
GRAY 	  = \033[0;90m
BLUE      = \033[34;1m
CYAN      = \033[37;1m
RED		  = \033[31;1m

SRC_FILES = free main move_costs push reverse_rot rotate set_stack_up sort swap tools_sort tools_stack tools cost 
SRC_FILES_BONUS = create_and_parse_bonus push_bonus reverse_rot_bonus rotate_bonus swap_bonus tools_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft  -o $(NAME)
			@echo "$(GREEN)Compilation successful!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(BLUE)Compiling, please wait.: $(RESET) $(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			
bonus:		$(OBJ_BONUS)
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT) -lft -o $(NAME)
			@echo "$(MAGENTA)Bonus compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR_BONUS)%.c | $(OBJF)
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -frf $(OBJ_DIR)
			@make all clean -C $(LIBFT)
			@echo "$(RED)Cleaning libraries, please wait.$(RESET)"
			@echo "$(RED)Cleaning program executables, please wait.$(RESET)"

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@rm -rf $(OBJ_BONUS)
			@make fclean -C $(LIBFT)
			@echo "$(YELLOW)Cleaning libraries.$(RESET)"
			@echo "$(YELLOW)Cleaning program objects.$(RESET)"

re: fclean all
			@echo "$(MAGENTA)Program recompiled$(RESET)"

norm:
			@norminette $(SRC) $(LIBFT) $(SRC_BONUS)
						
.PHONY: all bonus clean fclean re norm