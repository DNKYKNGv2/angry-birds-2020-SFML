
#ifndef ANGRYBIRDS_GAME_H
#define ANGRYBIRDS_GAME_H

#include "Birds.h"
#include "Pigs.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void mouseMove(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void mouseReleased(sf::Event event);
  void reset();

  sf::Font font;
  sf::Text intro_text;
  sf::Text pause_text;
  sf::Text high_menu_text;
  sf::Text player_score_str;
  sf::Text play_again_text;
  sf::Text resume_text;
  sf::Text quit_text;

  sf::Sprite intro_back;
  sf::Texture intro_texture;

  sf::Sprite mainmenu_background;
  sf::Texture mainmenu_texture;

  sf::Sprite win_image;
  sf::Texture win_texture;

  sf::Sprite lose_image;
  sf::Texture lose_texture;

  sf::Sprite blank_back;
  sf::Texture blank_texture;

  sf::Sprite play_option;
  sf::Texture play_texture;

  sf::Sprite play2_option;
  sf::Texture play2_texture;

  sf::Sprite quit_option;
  sf::Texture quit_texture;

  sf::Sprite fade_back;
  sf::Texture fade_texture;

  sf::Sprite level_back;
  sf::Texture level_1;
  sf::Texture level_2;
  sf::Texture level_3;

  sf::Sprite left_arrow;
  sf::Sprite right_arrow;
  sf::Texture arrow_texture;

  sf::Sprite slingshot;
  sf::Texture slingshot_texture;

  Birds* birds;
  int bird_counter = 4;
  Vector2 init_position = {0, 0};
  Vector2 bird_flight = {0, 0};

  Pigs* pigs;
  int pig_counter = 3;

  int player_score = 0;
  int highest_score = 0;

  bool in_menu;
  bool intro_menu;
  bool game_won;
  bool game_lost;
  bool pause_menu;
  bool in_game;
  bool play_selected = true;
  bool paused = false;
  bool resume_selected = true;
  bool level_select;

  bool bird_held = false;

  enum levels {level1, level2, level3};
  void level_selector(int level_selected);
  int current_level_selected = 1;

 private:
  sf::RenderWindow& window;

};

#endif // ANGRYBIRDS_GAME_H
