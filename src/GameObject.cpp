#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
  sprite = new sf::Sprite;
}

GameObject::~GameObject()
{

}

bool GameObject::initialiseSprite(sf::Texture &texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout << filename << "failed to load!\n";
  }

  sprite->setTexture(texture);
  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}
