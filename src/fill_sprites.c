/*
** fill_sprites.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 17:21:43 2017 Léandre Blanchard
** Last update Sun May 28 17:51:35 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int		fill_sprites(t_sprite **sprites, const char *pathname)
{
  sfTexture	*texture;
  sfVector2i	a;
  int		x;

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
			      (sfIntRect){a.x, a.y, 100, 100});
      a.x += 100;
      if (a.x == 400)
	{
	  a.x = 0;
	  a.y = (a.y + 100) % 400;
	}
      x++;
    }
  return (0);
}

int		fill_weapon(t_sprite **sprites, const char *pathname)
{
  sfTexture	*texture;
  int		x;

  x = 0;
  if ((texture = sfTexture_createFromFile(pathname, NULL)) == NULL)
    return (-1);
  while (sprites[x] != NULL)
    {
      sprites[x]->texture = texture;
      sprites[x]->sprite = sfSprite_create();
      sfSprite_setTexture(sprites[x]->sprite, texture, sfTrue);
      sfSprite_setTextureRect(sprites[x]->sprite,
			      (sfIntRect){x * 100, 0, 100, 100});
      x++;
    }
  return (0);
}

t_sprite		***weapon_sprites(void)
{
  t_sprite		***weap;
  char			*s;
  int			i;

  if ((s = my_strdup("sprites/weapon0.png")) == NULL)
    return (NULL);
  i = 0;
  if ((weap = malloc(sizeof(t_sprite **) * 4)) == NULL)
    return (NULL);
  weap[3] = NULL;
  while (i != 3)
    {
      if ((weap[i] = create_sprites(6)) == NULL)
	return (NULL);
      s[14] = i + 48;
      if (!fill_weapon(weap[i], s))
	my_printf("%sLoading sprites : %s%s%s\n", BOLDCYAN, BOLDGREEN, s, RESET);
      else
	return (NULL);
      i++;
    }
  my_free(s);
  return (weap);
}

t_sprite                ***all_sprites(int nb)
{
  t_sprite              ***sprites;
  char                  *s;
  int                   i;

  i = 0;
  if ((s = my_strdup("sprites/pers0.png")) == NULL)
    return (NULL);
  if ((sprites = malloc(sizeof(t_sprite **) * (nb + 2))) == NULL)
    return (NULL);
  while (i != nb)
    {
      s[12] = i + 48;
      sprites[i] = create_sprites(16);
      if (!fill_sprites(sprites[i], s))
	my_printf("%sLoading sprites : %s%s%s\n", BOLDCYAN, BOLDGREEN, s, RESET);
      else
	return (NULL);
      i++;
    }
  sprites[nb] = create_sprites(18);
  if (special_sprite(sprites[nb], "sprites/pilgrim.png"))
   my_printf("%sLoading sprites : %sClaudius%s\n", BOLDCYAN, BOLDGREEN, RESET);
  sprites[nb + 1] = NULL;
  my_free(s);
  return (sprites);
}
