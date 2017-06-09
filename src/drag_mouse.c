/*
** drag_mouse.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 19:45:26 2017 Léandre Blanchard
** Last update Sat May 27 22:36:59 2017 Léandre Blanchard
*/

#include "tekadventure.h"

sfVector2i              drag_mouse(t_window *window, sfVector2i *pos)
{
  static sfVector2i	drag;

  if (MP && (KP(sfKeyLControl) || KP(sfKeyRControl)))
    {
      drag.x = window->mouse.x - W_2;
      drag.y = window->mouse.y - H_2;
    }
  else if (KP(sfKeyR))
    drag = xy_vectori(0, 0);
  *pos = drag;
  return (drag);
}

