##
## Makefile for *** in /home/leandre/***
##
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
##
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Tue May 30 00:57:55 2017 Léandre Blanchard
##

NAME	= tekadventure

NAME2	= creator

CC	= gcc

LIB	= -L./lib -lmy -lc_graph_prog_full -L./lib/CSFML -l_my_csfml -lm

LIB2	= -L./lib -lmy

SRCS	= src/main.c			\
	  src/init.c			\
	  src/warp.c			\
	  src/fill_sprites.c		\
	  src/display_planets.c		\
	  src/parse_input.c		\
	  src/get_maps.c		\
	  src/dist.c			\
	  src/convert_mouse.c		\
	  src/clic_to_move.c		\
	  src/assign_room.c		\
	  src/free.c			\
	  src/spaceship.c		\
	  src/free_graph.c		\
	  src/get_portals.c		\
	  src/link_portals.c		\
	  src/get_map_name.c		\
	  src/create_backgrounds.c	\
	  src/inblock.c			\
	  src/generate_terrain.c	\
	  src/jump.c			\
	  src/lobby.c			\
	  src/sprite_character.c	\
	  src/drag_mouse.c		\
	  src/keys.c			\
	  src/menu.c			\
	  src/host.c			\
	  src/musics.c			\
	  src/moves.c			\
	  src/players.c			\
	  src/socket.c			\
	  src/join.c			\
	  src/get_ip_input.c		\
	  src/save_ip.c			\
	  src/receive.c			\
	  src/send.c			\
	  src/fill_sockets.c		\
	  src/debug.c			\
	  src/ingame.c			\
	  src/display_ingame.c

SRCS2	= creator_src/creator.c

OBJ	= $(SRCS:.c=.o)

OBJ2	= $(SRCS2:.c=.o)

RM	= rm -f

CFLAGS	+= -Wall -Wextra -Werror -I ./include

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	$(CC) $(OBJ2) -o $(NAME2) $(CFLAGS) $(LIB2)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
