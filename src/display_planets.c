/*
** display_planets.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May 30 00:51:18 2017 Léandre Blanchard
** Last update Tue May 30 01:39:52 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void			display_planets(t_window *window,
					t_textures *sprites, t_info *info)
{
  sfVector2f		at;
  static int   		planet = -1;
  static int		prev = 0;

  if (prev != info->area || planet == -1)
    {
      prev = info->area;
      planet = rand() % 5;
    }
  at = XYF(NEG(info->pos.x / 40 - 300), info->pos.y / 50);
  put_sprite_resize(window, BG(16 + (planet + 4) % 5), at, XYF(0.1, 0.1));
  at = XYF(NEG(info->pos.x / 100 - 1000), H_2 - 200);
  put_sprite_resize(window, BG(16 + (planet + 2) % 5), at, XYF(2, 2));
  at = XYF(NEG(info->pos.x / 50 - W_2), H_2 - 200);
  put_sprite(window, BG(16 + (planet + 1) % 5), at);
  at = XYF(NEG(info->pos.x / 3 - 100), info->pos.y / 2);
  put_sprite_resize(window, BG(16 + planet), at, XYF(0.7, 0.7));
  at = XYF(NEG((int)(info->pos.x) / 10 - 1000), info->pos.y / 20);
  if (planet < 2)
    put_sprite(window, BG(PLAN_3), at);
}
