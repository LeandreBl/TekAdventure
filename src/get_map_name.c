/*
** get_map_name.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 28 14:11:27 2017 Léandre Blanchard
** Last update Sun May 28 15:52:46 2017 Léandre Blanchard
*/

#include "tekadventure.h"

char		*get_map_name(char *line)
{
  char		*name;

  if (my_strncmp(line, "##map", 5) != 0)
    return (NULL);
  if ((name = my_calloc(my_strlen(line))) == NULL)
    return (NULL);
  my_strcpy(name, line + 6);
  while (name[0] == '"')
    shift_left(name, 1);
  while (end_with(name, "\"") == 0)
    shift_right(name, 1);
  return (name);
}
