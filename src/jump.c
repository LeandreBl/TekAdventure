/*
** jump.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 26 18:47:28 2017 Léandre Blanchard
** Last update Sun May 28 14:32:52 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void			regul_speed(float *speed)
{
  if (*speed > 1)
    *speed = *speed / GRAVITY;
  else if (*speed < 1 && *speed > 0)
    *speed = -0.5;
  else
    *speed = *speed * GRAVITY;
}

void                    jump(t_window *window,
			     t_info *info,
			     t_terrain *terrain)
{
  static float		init;
  static float		speed;
  sfVector2f		feet;
  sfVector2f		head;

  feet = XYF(info->pos.x, info->pos.y - 20);
  head = XYF(info->pos.x, info->pos.y + 70);
  if (KP(sfKeyUp) && is_block(terrain->cur->dup, feet))
    {
      init = feet.y;
      speed = 9;
      sfMusic_play(window->musics[2]);
    }
  if (feet.y >= init)
    {
      if ((is_block(terrain->cur->dup, head)
	   || is_block(terrain->cur->dup, feet)) && init != feet.y)
	speed = 0;
      info->pos.y += speed;
      regul_speed(&speed);
    }
  if (!is_block(terrain->cur->dup, feet))
    info->pos.y -= 1.5;
}
