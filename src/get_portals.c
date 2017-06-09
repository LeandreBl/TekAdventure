/*
** get_portals.c for tekadvneture in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 14:49:46 2017 Léandre Blanchard
** Last update Sun May 28 19:57:57 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int     	nb_of(char **tab, char cmp)
{
  int		i;
  int		j;
  int		nb;

  i = 0;
  nb = 0;
  while (i < my_tablen(tab))
    {
      j = 0;
      while (j < my_strlen(tab[i]))
	{
	  if (tab[i][j] == cmp)
	    nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

static t_portal	*add_one(int x, int y)
{
  t_portal	*new;

  if ((new = malloc(sizeof(t_portal))) == NULL)
    return (NULL);
  new->entry.x = x;
  new->entry.y = y;
  new->exit.x = -1;
  new->exit.y = -1;
  new->to = NULL;
  return (new);
}
static int     	add_portals(t_room *cur)
{
  int		nb;
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  nb = nb_of(cur->room, 'x');
  if ((cur->portals = malloc(sizeof(t_portal *) * (nb + 2))) == NULL)
    return (-1);
  while (i < my_tablen(cur->dup))
    {
      j = 0;
      while (j < my_strlen(cur->dup[i]))
	{
	  if (cur->dup[i][j] == 'x')
	    cur->portals[k++] = add_one(j, i);
	  cur->portals[k] = NULL;
	  j++;
	}
      i++;
    }
  cur->portals[nb + 1] = NULL;
  return (0);
}

int		get_portals(char **tab, t_map *map)
{
  int		i;
  t_room	*cur;
  int		nb_room;

  i = 0;
  nb_room = 0;
  while (i < my_tablen(tab) && my_strncmp(tab[i], "##gates", 7) != 0)
    i++;
  i++;
  cur = map->first;
  while (nb_room < map->len)
    {
      add_portals(cur);
      cur = cur->next;
      nb_room++;
    }
  link_portals(tab, map, i);
  return (0);
}
