/*
** ingame.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Apr 14 18:21:48 2017 Léandre Blanchard
** Last update Sun May 28 18:07:11 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void		re_init_status(t_window *window, t_player *players)
{
  players[0].info->attack = 0;
  players[1].info->attack = 0;
  sfMusic_play(window->musics[0]);
  sfMusic_setVolume(window->musics[0], 40);
  sfMusic_setVolume(window->musics[1], 40);
}

int		first_lap(t_window *window, t_textures *textures, t_player *players)
{
  t_terrain	*terrain;

  re_init_status(window, players);
  if ((terrain = generate_terrain("map")) == NULL)
    return (-1);
  while (sfRenderWindow_isOpen(window->window)
	 && players[0].info->skin >= 0)
    {
      window_clear(window);
      close_win(window);
      display_ingame(window, players, textures, terrain);
      window_refresh(window);
    }
  sfMusic_stop(window->musics[0]);
  free_graph(&terrain->world);
  free_terrain(terrain);
  return (0);
}

int		ingame(t_window *window, t_textures *textures, t_player *players)
{
  if (players[0].info->area == 0)
    first_lap(window, textures, players);
  return (0);
}
