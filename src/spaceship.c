/*
** spaceship.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May 29 19:43:43 2017 Léandre Blanchard
** Last update Mon May 29 22:22:04 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static void		reinit_vars(sfVector2f *pos,
				    float *speed,
				    sfVector2f *size,
				    int *amount)
{
  pos->x = 1280 + rand() % 900;
  pos->y = 520 - rand() % 320;
  size->x = 1 + rand() % 4;
  *size = XYF((float)1 / size->x, (float)1 / size->x);
  *speed = 3 * size->x;
  *amount = 1 / size->x + rand() % 2;
}

static sfVector2f	adapt_pos(t_window *window,
				  t_info *info,
				  sfVector2f pos,
				  float size)
{
  sfVector2i		drag;
  sfVector2f		real;

  real = pos;
  drag_mouse(window, &drag);
  real.x += drag.x - info->pos.x * size;
  real.y += drag.y + info->pos.y * size;
  return (real);
}

void			move_spaceship(t_window *window,
				       t_textures *sprites,
				       t_info *info)
{
  static sfVector2f	pos = {1280, 200};
  static float		speed = 1;
  static sfVector2f	size = {1, 1};
  static int		amount = 1;
  int			i;

  i = 0;
  if (pos.x > info->pos.x - 700)
    pos.x -= speed;
  if (pos.x <= info->pos.x -700)
    {
      reinit_vars(&pos, &speed, &size, &amount);
      pos.y -= info->pos.y;
      pos.x += info->pos.x;
    }
  while (i < amount)
    {
      put_sprite_resize(window, BG(5), adapt_pos(window,
				       info, XYF(pos.x + i * 50,
				       pos.y + i * 70), size.x), size);
      i++;
    }
}
