/*
** inblock.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 18:24:58 2017 Léandre Blanchard
** Last update Mon May 29 23:52:20 2017 Léandre Blanchard
*/

#include "tekadventure.h"

sfVector2i      	convert_pos(sfVector2f pos)
{
  sfVector2i		real;

  real.x = (float)(pos.x + (float)40) / (float)(108);
  real.y = (float)(pos.y + (float)10) / (float)(108) + 1;
  return (real);
}

static int	       	steps(char **tab, sfVector2f posf)
{
  char                  c;
  sfVector2i            pos;

  pos = convert_pos(posf);
  if (pos.y >= 0 && pos.y < my_tablen(tab)
      && pos.x >= 0 && pos.x < my_strlen(tab[pos.y]))
    {
      c = tab[pos.y][pos.x];
      if (c != 'x' && c != ' ' && c != '.')
	return (1);
    }
  return (0);
}

int			is_block(char **tab, sfVector2f posf)
{
  sfVector2f		right;

  right.x = posf.x + 60;
  right.y = posf.y;
  if (steps(tab, posf) || steps(tab, right))
    return (1);
  return (0);
}
