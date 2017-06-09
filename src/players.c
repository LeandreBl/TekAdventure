/*
** players.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 20 10:00:28 2017 Léandre Blanchard
** Last update Thu May 11 11:11:44 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int		number_of_players(t_player *players)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (i < MAX_PLAYERS)
    {
      if (players[i].info->skin != -1)
	nb++;
      i++;
    }
  return (nb);
}
