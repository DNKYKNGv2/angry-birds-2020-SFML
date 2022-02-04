#ifndef ANGRYBIRDSSFML_PIGS_H
#define ANGRYBIRDSSFML_PIGS_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"


class Pigs : public GameObject
{
 public:

  Pigs();
  ~Pigs();

  bool getVisibility();
  void setVisibility(bool v);
  bool visible = true;

  enum Pig {Round_pig, Square_pig};

  sf::Texture round_pig_texture;
  sf::Texture square_pig_texture;

  void addTexture(Pig pig);

 private:

};

#endif // ANGRYBIRDSSFML_PIGS_H
