/*
** assign_room.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 17:40:48 2017 Léandre Blanchard
** Last update Sun May 28 20:05:07 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int		assign_room(t_room *cur, int i, char *name)
{
  t_room	*to_link;

  to_link = cur;
  get_name(name);
  while (to_link != NULL && my_strcmp(name, to_link->name))
    to_link = to_link->next;
  cur->portals[i]->to = to_link;
  return (0);
}
