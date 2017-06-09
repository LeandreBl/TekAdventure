/*
** moves.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 24 16:44:59 2017 Léandre Blanchard
** Last update Sun May 28 18:59:01 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int		right_left(t_info *info,
				   float speed)
{
  if (KP(sfKeyLeft))
    info->dir = 8;
  if (KP(sfKeyRight))
    info->dir = 0;
  if (info->dir == 0)
    info->pos.x += speed;
  if (info->dir == 8)
    info->pos.x -= speed;
  if (info->pos.x < 0)
    info->pos.x = 0;
  return (0);
}

static void		speed_value(float *speed)
{
  if (KP(sfKeyLeft) || KP(sfKeyRight))
    {
      if (*speed * ACCELERATION > MAX_SPEED)
	*speed = MAX_SPEED;
      else if (*speed < 0.15)
	*speed = 0.15;
      else
	*speed = *speed * ACCELERATION;
    }
  else
    *speed = *speed / DECELERATION;
  if (*speed < 0.1)
    *speed = 0;
}

void			replace_pos(t_info *info,
				    sfVector2f *prev,
				    t_terrain *terrain)
{
  if (is_block(terrain->cur->dup, info->pos))
    info->pos = *prev;
}

float			moves(t_window *window,
			      t_info *info,
			      t_terrain *terrain)
{
  static float		speed;
  sfVector2f	       	prev;
  static sfVector2f    	save = { 1, 1 };

  speed_value(&speed);
  prev = info->pos;
  right_left(info, speed);
  replace_pos(info, &prev, terrain);
  prev = info->pos;
  jump(window, info, terrain);
  replace_pos(info, &prev, terrain);
  if (warp(window, info, terrain))
    {
      sfMusic_play(window->musics[1]);
      save = info->pos;
    }
  if (info->pos.y < -200)
    info->pos = save;
  return (speed);
}
