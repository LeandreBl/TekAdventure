/*
** fill_sockets.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Apr 25 12:37:32 2017 Léandre Blanchard
** Last update Fri Apr 28 18:38:53 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int		first_inactive_socket(t_player *players)
{
  int		i;

  i = 0;
  while (i < MAX_PLAYERS)
    {
      if (players[i].info->skin == -1)
	return (i);
      i++;
    }
  return (i);
}

int		fill_sockets_with_name(t_player *players, t_info *info)
{
  int		i;

  i = 0;
  if (info->skin < 0 || info->skin > MAX_PERS)
    return (-1);
  while (i < MAX_PLAYERS)
    {
      if (my_strcmp(players[i].info->name, info->name) == 0)
	{
	  if (i != 0)
	    re_fill_info(players[i].info, info->name, info->skin, info->weapon);
	  return (0);
	}
      i++;
    }
  i = first_inactive_socket(players);
  re_fill_info(players[i].info, info->name, info->skin, info->weapon);
  return (1);
}

int		nickname_already_taken(t_player *players, char *name)
{
  int		i;

  i = 0;
  while (i != MAX_PLAYERS)
    {
      if (my_strcmp(players[i].info->name, name) == 0
	  && players[i].info->skin != -1)
	return (-1);
      i++;
    }
  return (0);
}
