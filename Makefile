# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 04:06:44 by jvigny            #+#    #+#              #
#    Updated: 2023/12/20 18:15:14 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT = client.c utils.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

SRC_SERVER = serveur.c list.c utils.c delete_list.c
OBJ_SERVER = ${SRC_SERVER:.c=.o}

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -g

all:	${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT}:	${OBJ_CLIENT}
	${CC} ${CFLAGS} -o ${NAME_CLIENT} ${OBJ_CLIENT}

${NAME_SERVER}:	${OBJ_SERVER}
	${CC} ${CFLAGS} -o ${NAME_SERVER} ${OBJ_SERVER}

clean:
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER}

fclean:	clean
	rm -f ${NAME_CLIENT} ${NAME_SERVER}

re:	fclean all

.PHONY: re fclean clean all


