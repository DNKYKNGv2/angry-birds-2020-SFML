#ifndef ANGRYBIRDSSFML_GAMEOBJECT_H
#define ANGRYBIRDSSFML_GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  GameObject();
  GameObject(sf::Sprite* spr);
  ~GameObject();

  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

 protected:
  sf::Sprite* sprite = nullptr;
};

#endif // ANGRYBIRDSSFML_GAMEOBJECT_H
