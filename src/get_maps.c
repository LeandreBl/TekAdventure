/*
** get_maps.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 13:57:16 2017 Léandre Blanchard
** Last update Sun May 28 15:51:27 2017 Léandre Blanchard
*/

#include "tekadventure.h"

char		**get_room(char **tab, int i)
{
  char		**room;

  room = NULL;
  while (i < my_tablen(tab) && tab[i][0] != '#')
    room = tab_append(room, my_strdup(tab[i++]));
  return (room);
}

t_room		*add_room(void)
{
  t_room	*room;

  if ((room = malloc(sizeof(t_room))) == NULL)
    return (NULL);
  return (room);
}

int		fill_room(char **tab, int i, t_room *cur)
{
  if ((cur->room = get_room(tab, i + 1)) == NULL)
    return (-1);
  if ((cur->name = get_map_name(tab[i])) == NULL)
    return (-1);
  if ((cur->next = add_room()) == NULL)
    return (-1);
  if ((cur->dup = tabdup(cur->room)) == NULL)
    return (-1);
  return (0);
}

int		get_maps(char **tab, t_map *map)
{
  t_room	*cur;
  int		i;

  i = 0;
  map->len = 0;
  if ((map->first = add_room()) == NULL)
    return (-1);
  cur = map->first;
  while (i < my_tablen(tab))
    {
      while (i < my_tablen(tab) &&
	     my_strncmp(tab[i], "##map ", 6) != 0)
	i++;
      if (fill_room(tab, i, cur) == -1)
	return (-1);
      revtab(cur->dup);
      cur = cur->next;
      cur->next = NULL;
      map->len++;
      i++;
    }
  return (0);
}
