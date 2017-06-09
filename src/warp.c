/*
** warp.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 26 12:23:56 2017 Léandre Blanchard
** Last update Tue May 30 01:27:36 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int	is_portal(sfVector2i pos, char **tab, sfVector2f player)
{
  sfVector2i	real;

  real = convert_pos(player);
  if (pos.y >= 0 && pos.y < my_tablen(tab)
      && pos.x >= 0 && pos.x < my_strlen(tab[pos.y]))
    if (tab[pos.y][pos.x] == 'x' && dist(pos, real) <= 1)
      return (1);
  return (0);
}

static int	portal_no(t_room *cur, sfVector2i portal_pos)
{
  int		i;

  i = 0;
  while ((cur->portals[i]->entry.x != portal_pos.x
	  || cur->portals[i]->entry.y != portal_pos.y)
	 && cur->portals[i] != NULL)
    i++;
  return (i);
}

static void	update(t_info *info, t_terrain *terrain, sfVector2i mouse)
{
  int		no;
  t_room	*cur;

  no = portal_no(terrain->cur, mouse);
  if (terrain->cur->portals[no] != NULL
      && terrain->cur->portals[no]->to != NULL)
    {
      info->pos = XYF(108, 0);
      cur = terrain->cur->portals[no]->to;
      if (cur != NULL)
	{
	  terrain->cur = terrain->cur->portals[no]->to;
	  terrain->map = terrain->cur->room;
	  no = 0;
	  cur = terrain->world.first;
	  while (cur != terrain->cur)
	    {
	      cur = cur->next;
	      no++;
	    }
	  info->area++;
	}
    }
}

static void	display_world_name(t_window *window, char *name, int *a)
{
  if (*a <= 1000)
    {
      put_word(name, XYF(W_2, H_2), window, sfRed);
      *a = *a + 1;
    }
}

int		warp(t_window *window, t_info *info, t_terrain *terrain)
{
  static int	a;
  sfVector2i	mouse;

  mouse = convert_mouse(window, info);
  if (is_portal(mouse, terrain->cur->dup, info->pos) && MP)
    {
      while (MP);
      update(info, terrain, mouse);
      a = 0;
      return (1);
    }
  display_world_name(window, terrain->cur->name, &a);
  return (0);
}
