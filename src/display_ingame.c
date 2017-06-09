/*
** display_ingame.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 11 10:29:29 2017 Léandre Blanchard
** Last update Tue May 30 01:28:43 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int			bloc_to_display(char c)
{
  if (c == 'o')
    return (13);
  else if (c == 'x')
    return (14);
  else if (c == 's')
    return (15);
  return (0);
}

static void    		display_map(t_window *window, sfVector2f pos,
			    t_textures *sprites, t_terrain *terrain)
{
  int			i;
  int			j;
  int			len;
  sfVector2f		real;
  sfVector2i		drag;

  i = 0;
  drag_mouse(window, &drag);
  len = my_tablen(terrain->map) - 6;
  while (terrain->map[i] != NULL)
    {
      j = 0;
      while (terrain->map[i][j] != 0)
	{
	  real.x = W_2 - 54 + j * 108 - pos.x + drag.x;
	  real.y = (i - len) * 108 + pos.y + drag.y;
	  if (terrain->map[i][j] != ' ' && terrain->map[i][j] != '.')
	    put_sprite(window, BG(bloc_to_display(terrain->map[i][j])), real);
	  j++;
	}
      i++;
    }
}

void			display_ingame(t_window *window, t_player *players,
			       t_textures *sprites, t_terrain *terrain)
{
  int			pos;

  put_sprite(window, BG(PLAN_2), XYF(0, 0));
  display_planets(window, sprites, players[0].info);
  move_spaceship(window, sprites, players[0].info);
  pos = (int)(players[0].info->pos.x) % 1280;
  put_sprite(window, BG(PLAN_1), XYF(-pos, players[0].info->pos.y));
  put_sprite(window, BG(PLAN_1), XYF(1280 - pos, players[0].info->pos.y));
  display_map(window, players[0].info->pos, sprites, terrain);
  display_ally(window, sprites, players);
  display_me(window, players, sprites, terrain);
}

void			display_me(t_window *window, t_player *players,
			   t_textures *textures, t_terrain *terrain)
{
  float			speed;
  int			nb;
  sfVector2i		drag;
  float			clic;
  sfVector2f   		prev;

  prev = players[0].info->pos;
  clic = clic_to_move(window, players[0].info);
  replace_pos(players[0].info, &prev, terrain);
  if (clic >= 0)
    auto_jump(window, players[0].info, terrain,
	      convert_mouse(window, players[0].info));
  prev = players[0].info->pos;
  replace_pos(players[0].info, &prev, terrain);
  speed = moves(window, players[0].info, terrain);
  drag_mouse(window, &drag);
  if (speed != 0 || clic >= 0)
    nb = (int)players[0].info->dir + (((int)players[0].info->pos.x / 40) % 8);
  else if (players[0].info->dir == 8)
    nb = 17;
  else
    nb = 16;
  put_sprite(window, textures->sprites[(int)players[0].info->skin]
     [nb], xy_vectorf(W_2 - 54 + drag.x, H_ - 300 + drag.y));
}

void			display_ally(t_window *window,
			     t_textures *sprites, t_player *players)
{
  int			i;
  sfVector2f		disp;
  sfVector2i		drag;

  drag_mouse(window, &drag);
  i = 1;
  while (i < MAX_PLAYERS)
    {
      disp.x = W_2 - 54 + (players[i].info->pos.x - players[0].info->pos.x);
      disp.y = H_ - 300 + (players[0].info->pos.y - players[i].info->pos.y);
      disp.x += drag.x;
      disp.y += drag.y;
      if (players[i].info->skin >= 0
	  && players[i].info->area == players[0].info->area)
	{
	  put_sprite(window, sprites->sprites[(int)players[i].info->skin]
	   [(int)players[i].info->dir + (((int)players[i].info->pos.x / 40) % 8)],
	   disp);
	  put_word(players[i].info->name,
		   XYF(disp.x + 10, disp.y - 10), window, sfWhite);
	}
      i++;
    }
}
