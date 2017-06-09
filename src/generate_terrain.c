/*
** generate_terrain.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:30:31 2017 Léandre Blanchard
** Last update Sun May 28 20:03:48 2017 Léandre Blanchard
*/

#include "tekadventure.h"

t_terrain       *generate_terrain(const char *pathname)
{
  t_terrain     *terrain;

  if ((terrain = malloc(sizeof(t_terrain))) == NULL)
    return (NULL);
  if ((terrain->map = load_file(pathname)) == NULL)
    return (NULL);
  recup_map(terrain->map, &terrain->world);
  free_tab(terrain->map);
  terrain->cur = terrain->world.first;
  terrain->map = terrain->cur->room;
  return (terrain);
}
