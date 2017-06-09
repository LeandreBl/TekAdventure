/*
** free.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 20:56:40 2017 Léandre Blanchard
** Last update Sun May 28 18:06:09 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void		free_terrain(t_terrain *terrain)
{
  if (terrain != NULL)
    {
      my_free(terrain);
    }
}

void		free_players(t_player *players)
{
  int		i;

  i = 0;
  if (players != NULL)
    {
      while (i != MAX_PLAYERS)
	{
	  if (players[i].socket != NULL)
	    sfTcpSocket_destroy(players[i].socket);
	  if (players[i].info != NULL)
	    my_free(players[i].info);
	  i++;
	}
      my_free(players);
    }
}

void		free_textures(t_textures *sprites)
{
  if (sprites != NULL)
    {
      free_all_sprites(sprites->sprites);
      free_sprites(sprites->backgrounds);
      free_all_sprites(sprites->weapons);
      my_free(sprites);
    }
}

void		free_all_sprites(t_sprite ***sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	{
	  free_sprites_only(sprites[i]);
	  i++;
	}
      my_free(sprites);
    }
}
