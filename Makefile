# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 04:06:44 by jvigny            #+#    #+#              #
#    Updated: 2022/12/06 04:22:22 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT = client.c ft_strlen.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

SRC_SERVER = serveur.c
OBJ_SERVER = ${SRC_SERVER:.c=.o}

NAME = client
NAME1 = server

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

all:	${NAME} ${NAME1}

${NAME}:	${OBJ_CLIENT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ_CLIENT}

${NAME1}:	${OBJ_SERVER}
	${CC} ${CFLAGS} -o ${NAME1} ${OBJ_SERVER}

clean:
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER}

fclean:	clean
	rm -f ${NAME} ${NAME1}

re:	fclean all

.PHONY: re fclean clean


