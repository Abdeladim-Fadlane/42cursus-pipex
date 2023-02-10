# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:58:02 by afadlane          #+#    #+#              #
#    Updated: 2023/02/10 15:51:40 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = pipex
CFLAGS = -Wall -Werror -Wextra 



SRC = pipex.c ft_split.c libft_utils.c main.c

cc = gcc
OBJ = ${SRC:.c=.o}
OBJ2 = ${SRC2:.c=.o}

all :${NAME}

bonus : ${NAME2}

${NAME}: ${OBJ} 
	 	${cc} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
		rm -f ${OBJ} 

fclean : clean
		rm -f ${NAME}

nor:
	norminette

re : fclean all