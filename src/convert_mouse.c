/*
** convert_mouse.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May 30 00:21:03 2017 Léandre Blanchard
** Last update Tue May 30 00:28:55 2017 Léandre Blanchard
*/

#include "tekadventure.h"

sfVector2i		convert_mouse(t_window *window, t_info *info)
{
  sfVector2i		mouse;
  sfVector2f		mousef;
  sfVector2i		drag;

  drag_mouse(window, &drag);
  mouse = pos_mouse(window);
  mouse.x -= drag.x;
  mouse.y -= drag.y;
  mousef.x = (float)mouse.x / (float)108;
  mousef.y = ((float)(H_ - 72) - (float)mouse.y) / (float)108 - 1;
  mousef.x += (info->pos.x + 80) / 108 - 6;
  mousef.y += (info->pos.y + 108) / 108;
  mouse = xy_vectori((int)mousef.x, (int)mousef.y);
  return (mouse);
}
