#include "Pigs.h"
#include <iostream>

Pigs::Pigs()
{
  if (!square_pig_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Square/pig.png") ||
      !round_pig_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/pig.png"))
  {
    std::cout << "Birds did not load! \n";
  }
}

Pigs::~Pigs()
{

}

bool Pigs::getVisibility()
{
  return visible;
}

void Pigs::setVisibility(bool v)
{
  visible = v;
}

void Pigs::addTexture(Pig pig)
{
  if (pig == Pig::Round_pig)
  {
    sprite->setTexture(round_pig_texture);
  }

  else if (pig == Pig::Square_pig)
  {
    sprite->setTexture(square_pig_texture);
  }
}