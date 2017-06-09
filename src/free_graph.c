/*
** free_graph.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 18:00:23 2017 Léandre Blanchard
** Last update Sun May 28 19:17:36 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void		free_portals(t_portal **portals)
{
  int		i;

  i = 0;
  if (portals != NULL)
    {
      while (portals[i] != NULL)
	my_free(portals[i++]);
      my_free(portals);
    }
}

void		free_room(t_room *room)
{
  if (room != NULL)
    {
      free_tab(room->room);
      free_tab(room->dup);
      my_free(room->name);
      free_portals(room->portals);
    }
}

void		free_graph(t_map *map)
{
  t_room	*cur;
  t_room	*to_free;

  cur = map->first;
  while (cur->next != NULL)
    {
      to_free = cur;
      cur = cur->next;
      free_room(to_free);
    }
}
