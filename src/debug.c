/*
** debug.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Apr 25 12:57:18 2017 Léandre Blanchard
** Last update Tue Apr 25 13:00:21 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void		display_players_datas(t_player *players)
{
  int		i;

  i = 0;
  while (i != MAX_PLAYERS)
    {
      if (players[i].info->skin != -1)
	my_printf("at [%d] Name : %s, skin : %d\n", i,
		  players[i].info->name,
		  players[i].info->skin);
      i++;
    }
}
