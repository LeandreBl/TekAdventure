/*
** clic_to_move.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 18:34:53 2017 Léandre Blanchard
** Last update Tue May 30 00:30:52 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void			auto_jump(t_window *window,
				  t_info *info,
				  t_terrain *terrain,
				  sfVector2i mouse)
{
  static float          init;
  static float          speed;
  sfVector2f            feet;
  sfVector2f            head;

  feet = XYF(info->pos.x, info->pos.y - 20);
  head = XYF(info->pos.x, info->pos.y + 70);
  if (is_block(terrain->cur->dup, feet) && mouse.y > convert_pos(info->pos).y)
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

float			clic_to_move(t_window *window, t_info *info)
{
  static float    	clic = -1;
  static sfVector2i	drag;

  drag_mouse(window, &drag);
  if (MPR)
    clic = info->pos.x - W_2 - drag.x + window->mouse.x;
  if (info->pos.x < clic && clic >= 0)
    {
      info->pos.x += 2;
      info->dir = 0;
    }
  if (info->pos.x > clic && clic >= 0)
    {
      info->pos.x -= 2;
      info->dir = 8;
    }
  if (KP(sfKeyLeft) || KP(sfKeyRight)
      || KP(sfKeyUp) || info->pos.x == clic)
    clic = -1;
  return (clic);
}
