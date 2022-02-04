#ifndef ANGRYBIRDSSFML_BIRDS_H
#define ANGRYBIRDSSFML_BIRDS_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Birds : public GameObject
{
 public:
  Birds();
  ~Birds();

  bool getVisibility();
  void setVisibility(bool v);
  bool visible = true;

  enum Bird {Chick, Chicken, Duck, Owl, Parrot, Penguin};

  sf::Texture Chick_texture;
  sf::Texture Chicken_texture;
  sf::Texture Duck_texture;
  sf::Texture Owl_texture;
  sf::Texture Parrot_texture;
  sf::Texture Penguin_texture;

  void addTexture(Bird bird);

  Vector2 bird_direction = {0, 0};

  int bird_speed = 3;

  bool used_bird = false;

 private:
};

#endif // ANGRYBIRDSSFML_BIRDS_H
