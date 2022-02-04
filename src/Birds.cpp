#include "Birds.h"
#include <iostream>

Birds::Birds()
{
  if (!Chick_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png") ||
    !Chicken_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png") ||
    !Duck_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png") ||
    !Owl_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png") ||
    !Parrot_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png") ||
    !Penguin_texture.loadFromFile("Data/Images/kenney_animalpackredux/PNG/Round/chick.png"))
  {
    std::cout << "Birds did not load! \n";
  }
}

Birds::~Birds()
{

}

bool Birds::getVisibility()
{
  return visible;
}

void Birds::setVisibility(bool v)
{
  visible = v;
}

void Birds::addTexture(Bird bird)
{
  if (bird == Bird::Chick)
  {
    sprite->setTexture(Chick_texture);
  }

  else if (bird == Bird::Chicken)
  {
    sprite->setTexture(Chicken_texture);
  }

  else if (bird == Bird::Duck)
  {
    sprite->setTexture(Duck_texture);
  }

  else if (bird == Bird::Owl)
  {
    sprite->setTexture(Owl_texture);
  }

  else if (bird == Bird::Parrot)
  {
    sprite->setTexture(Parrot_texture);
  }

  else if (bird == Bird::Penguin)
  {
    sprite->setTexture(Penguin_texture);
  }
}