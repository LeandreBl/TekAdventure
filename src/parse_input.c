/*
** parse_input.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 13:55:20 2017 Léandre Blanchard
** Last update Sun May 28 15:57:27 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int			recup_map(char **tab, t_map *map)
{
  get_maps(tab, map);
  get_portals(tab, map);
  return (0);
}
