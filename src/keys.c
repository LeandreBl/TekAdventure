/*
** keys.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 13 02:58:56 2017 Léandre Blanchard
** Last update Tue May 23 21:06:39 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int     get_lobby_keys(int *a)
{
  if (key_released(sfKeyRight))
    *a = (*a + 1) % 5;
  if (key_released(sfKeyLeft))
    *a = (*a - 1 >= 0) ? *a - 1 : 4;
  if (DRAG_)
    *a = 5;
  return (*a);
}
