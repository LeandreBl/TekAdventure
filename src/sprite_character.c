/*
** sprite_character.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 26 18:43:45 2017 Léandre Blanchard
** Last update Fri May 26 18:44:13 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int      add_stands(t_sprite **sprites, int x)
{
  if ((sprites[x - 2] = create_sprite("sprites/stand.png")) == NULL ||
      ((sprites[x - 1] = create_sprite("sprites/stand_1.png"))) == NULL)
    return (-1);
  return (0);
}

int             special_sprite(t_sprite **sprites, const char *pathname)
{
  sfTexture     *texture;
  sfVector2i    a;
  int           x;

  x = 0;
  my_printf(BOLDRED);
  if ((texture = sfTexture_createFromFile(pathname, NULL)) == NULL)
    return (-1);
  a = xy_vectori(0, 0);
  while (sprites[x] != NULL)
    {
      sprites[x]->texture = texture;
      sprites[x]->sprite = sfSprite_create();
      sfSprite_setTexture(sprites[x]->sprite, texture, sfTrue);
      sfSprite_setTextureRect(sprites[x]->sprite,
			      (sfIntRect){a.x, a.y, 108, 140});
      a.x += 108;
      if (a.x == 108 * 8)
	{
	  a.x = 0;
	  a.y = (a.y + 140);
	}
      x++;
    }
  return (add_stands(sprites, x));
}
