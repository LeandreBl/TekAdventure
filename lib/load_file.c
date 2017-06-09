/*
** get_file_tab.c for get_file_tab in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:27:51 2017 Léandre Blanchard
** Last update Thu May 25 19:32:45 2017 Léandre Blanchard
*/

#include <fcntl.h>
#include "my.h"

char            **load_file(const char *pathname)
{
  char          **tab;
  char          *input;
  int           size;
  int           fd;

  size = file_size(pathname);
  if ((fd = open(pathname, O_RDONLY)) == -1)
    return (NULL);
  if ((input = my_calloc(size + 2)) == NULL)
    return (NULL);
  if ((read(fd, input, size)) == -1)
    return (NULL);
  close(fd);
  if ((tab = my_str_to_wordtab(input, '\n')) == NULL)
    return (NULL);
  my_free(input);
  return (tab);
}

