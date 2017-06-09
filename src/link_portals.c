/*
** link_portals.c for tekadventure.h in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 15:56:11 2017 Léandre Blanchard
** Last update Sun May 28 20:04:46 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int			get_name(char *line)
{
  while (line[0] == '"')
    shift_left(line, 1);
  while (end_with(line, "\"") == 0)
    shift_right(line, 1);
  return (0);
}

static sfVector2i	link_entry(char *line, t_room *cur)
{
  sfVector2i		entry;
  char			**div;

  epur_str(line);
  if ((div = my_str_to_wordtab(line, ' ')) == NULL)
    return (XYI(-1, -1));
  get_name(div[0]);
  while (cur != NULL && my_strcmp(cur->name, div[0]))
    cur = cur->next;
  if (cur == NULL)
    return (XYI(-1, -1));
  entry.y = my_getnbr(div[1] + 1);
  entry.x = my_getnbr(div[2]);
  free_tab(div);
  return (entry);
}

static sfVector2i	link_exit(char *line, t_room *cur)
{
  sfVector2i		exi;
  char			**div;

  epur_str(line);
  if ((div = my_str_to_wordtab(line, ' ')) == NULL)
    return (XYI(0, 0));
  get_name(div[0]);
  while (cur != NULL && my_strcmp(cur->name, div[0]))
    cur = cur->next;
  if (cur == NULL)
    return (XYI(0, 0));
  exi.y = my_getnbr(div[1] + 1);
  exi.x = my_getnbr(div[2]);
  free_tab(div);
  return (exi);
}

static int		link_pos(sfVector2i entry, sfVector2i exi,
			 t_room *cur, char **both)
{
  int			i;
  char			**div;

  i = 0;
  if (entry.x == -1)
    return (-1);
  if ((div = my_str_to_wordtab(both[0], ' ')) == NULL)
    return (-1);
  get_name(div[0]);
  while (cur != NULL && my_strcmp(div[0], cur->name))
    cur = cur->next;
  while (cur->portals[i] != NULL
	 && (entry.x != cur->portals[i]->entry.x
	     || entry.y != cur->portals[i]->entry.y))
    i++;
  if (cur->portals[i] == NULL)
    i--;
  cur->portals[i]->exit = exi;
  free_tab(div);
  if ((div = my_str_to_wordtab(both[1], ' ')) == NULL)
    return (-1);
  assign_room(cur, i, div[0]);
  free_tab(div);
  return (0);
}

int			link_portals(char **tab, t_map *map, int i)
{
  char			**both;
  sfVector2i		entry;
  sfVector2i		exi;

  while (i < my_tablen(tab) && tab[i][0] != '#')
    {
      if ((both = my_str_to_wordtab(tab[i], '-')) == NULL)
	return (-1);
      entry = link_entry(both[0], map->first);
      exi = link_exit(both[1], map->first);
      link_pos(entry, exi, map->first, both);
      free_tab(both);
      i++;
    }
  return (0);
}
