/*
** musics.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 24 19:36:57 2017 Léandre Blanchard
** Last update Sat May 27 19:01:52 2017 Léandre Blanchard
*/

#include "tekadventure.h"

sfMusic			**create_musics(void)
{
  sfMusic		**musics;
  int			i;

  i = 0;
  if ((musics = malloc(sizeof(sfMusic *) * 4)) == NULL)
    return (NULL);
  musics[0] = sfMusic_createFromFile("musics/megalovania.wav");
  musics[1] = sfMusic_createFromFile("musics/portal.wav");
  musics[2] = sfMusic_createFromFile("musics/jump.wav");
  musics[3] = NULL;
  while (i != 3)
    if (musics[i++] == NULL)
      return (NULL);
  return (musics);
}
