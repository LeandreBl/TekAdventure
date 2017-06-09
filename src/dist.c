/*
** dist.c for tekadventure.h in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May 29 22:22:55 2017 Léandre Blanchard
** Last update Mon May 29 23:53:49 2017 Léandre Blanchard
*/

#include "tekadventure.h"

float		dist(sfVector2i from, sfVector2i to)
{
  return (sqrt(((from.x - to.x) * (from.x - to.x))
	       + ((from.y - to.y) * (from.y - to.y))));
}
