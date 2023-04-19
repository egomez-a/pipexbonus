# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:37:38 by egomez-a          #+#    #+#              #
#    Updated: 2023/04/19 16:56:39 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pipex
SRCS_DIR	=	sources/
SRCSBON_DIR	=	sources_bonus/
OBJ_DIR		= 	obj/
OBJBON_DIR	=	objbonus/
INC_DIR		= 	include/
INCBON_DIR	=	include_bonus/

SRCS 		=	pipex.c \
				paths.c \
				ft_functions1.c \
				ft_functions2.c \
				ft_functions3.c \
				checkprogram.c \
				checkerrors.c \
				openfile.c \
				ft_split.c \

SRCSBON		= 	pipex_bonus.c \
				paths_bonus.c \
				checkerrors_bonus.c \
				openfile_bonus.c \
				ft_functions1_bonus.c \
				ft_functions2_bonus.c \
				ft_functions3_bonus.c \
				ft_split_bonus.c \
							
NOW			=	$(shell date +"%d-%m-%y %H:%M")

OBJS 		= 	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJSBON		=   $(addprefix $(OBJBON_DIR), $(SRCSBON:.c=.o))

CFLAGS 		= 	-Wall -Wextra -Werror -I$(INC_DIR)
CFLAGSBON	= 	-Wall -Wextra -Werror -I$(INCBON_DIR)
DEBUGGING	= 	#-g3 -fsanitize=address -O0
CC 			= 	gcc
RM 			= 	rm -rf			#-f es para evitar que borre si no hay nada que borrar
NORM		= 	/usr/bin/norminette

NONE		=	'\033[0m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[0;33m'
BLUE		=	'\033[0;34m'
PURPLE		=	'\033[0;35m'

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $(DEBUGGING) $< -o $@

$(OBJBON_DIR)%.o : $(SRCSBON_DIR)%.c
	@mkdir -p $(OBJBON_DIR)
	@$(CC) -c $(CFLAGSBON) $(DEBUGGING) $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(DEBUGGING) -o $(NAME) $(OBJS)
	@echo $(GREEN) "======== COMPILED  ==========" $(NONE)

clean:
		@echo $(YELLOW) "========== CLEAN ==========" $(NONE)
		$(RM) $(OBJ_DIR) 
		$(RM) $(OBJBON_DIR)
		$(RM) $(OBJS)
		$(RM) $(OBJSBON)
		@echo $(GREEN) "=========== DONE ===========" $(NONE)
		
fclean: clean
		@echo $(PURPLE) "========== FCLEAN ==========" $(NONE)
		$(RM) $(NAME)
		@echo $(GREEN) "=========== DONE ===========" $(NONE)

re: fclean all

git: fclean
	@echo $(BLUE) "===== PUSHING to GITHUB ===="  $(NONE)
	git add .
	git commit -m "Pipex - $(NOW)"
	git push origin master
	@echo $(GREEN)"=============== DONE ================"$(NONE)
	
norm: 
		$(NORM) $(SRC);

bonus: $(OBJSBON) 
	$(CC) $(CFLAGSBON) $(DEBUGGING) -o $(NAME) $(OBJSBON)
	@echo $(GREEN) "======== COMPILED BONUS ==========" $(NONE)

.PHONY: all, clean, fclean, re