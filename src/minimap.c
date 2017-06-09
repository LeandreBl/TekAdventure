/*
** minimap.c for mtekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 20:26:23 2017 Léandre Blanchard
** Last update Sat May 27 20:33:35 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int		put_mini_pixel(sfUint8 *pixels, int x, int y, t_minimap info)
{
  if (x < 0 || y < 0)
    return (-1);
  if (x > info.width || y > info.height)
    return (-1);
  pixels[(info.width * y + x) * 4 + 0] = info.color.r;
  pixels[(info.width * y + x) * 4 + 1] = info.color.g;
  pixels[(info.width * y + x) * 4 + 2] = info.color.b;
  pixels[(info.width * y + x) * 4 + 3] = info.color.a;
  return (0);
}

static int		put_players(t_player *players, t_terrain *terrain)
{
  int			i;
  sfVector2i		pos;
  t_minimap		info;

  i = 0;
  while (i != MAX_PLAYERS)
    {
      pos = convert_pos(players[i].info->pos);
      info.width = my_total_len(map);
      info.height = my_tablen(map);
      info.color = sfColor_fromRGBA(50 * i, 10 * i, 30 * i, 127);
      if (players[i].info->skin != -1)
	put_mini_pixel(
    }
}
