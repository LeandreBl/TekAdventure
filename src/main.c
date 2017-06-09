/*
** main.c for scroller in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:50:47 2017 Léandre Blanchard
** Last update Mon May 29 20:08:40 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int      already_created(t_info *info)
{
  int           fd;
  t_info        temp;

  if ((fd = open("player.dat", O_RDONLY)) == -1)
    return (-1);
  if (read(fd, &temp, sizeof(t_info)) < 0)
    {
      my_printf(CORRUPTED_, BOLDRED, BOLDCYAN, RESET);
      return (-1);
    }
  my_strcpy(info->name, temp.name);
  info->skin = temp.skin;
  my_printf("\n");
  BOX_;
  my_printf(FOUND_, BOLDYELLOW, BOLDCYAN,
	    info->name, BOLDYELLOW, BOLDCYAN, info->skin, RESET);
  BOX_;
  my_printf("\n\n");
  close(fd);
  return (0);
}

int		main_menu(t_window *window, t_textures *sprites, t_player *players)
{
  int		todo;

  todo = host_join(window, players[0].info, sprites);
  if (todo == HOST)
    return (host(window, sprites, players));
  if (todo == JOIN)
    return (join(window, sprites, players));
  return (0);
}

int		main(void)
{
  t_window     	*window;
  t_textures	*sprites;
  t_player	*players;

  srand(time(NULL));
  if ((window = init_window(720, 16.0 / 9.0, "Tek Adventure")) == NULL)
    return (-1);
  if ((window->font = my_strdup("fonts/arial.ttf")) == NULL)
    return (-1);
  if ((sprites = generate_all_sprites()) == NULL)
    return (-1);
  if ((players = init_players()) == NULL)
    return (-1);
  if ((window->musics = create_musics()) == NULL)
    return (-1);
  if (already_created(players[0].info) != 0)
    lobby(window, players[0].info, sprites);
  main_menu(window, sprites, players);
  free_players(players);
  free_window(window);
  free_textures(sprites);
  return (0);
}
