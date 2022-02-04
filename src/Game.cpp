#include "Game.h"
#include <iostream>
#include <sstream>
#include <random>
#include <cmath>
#include <string>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));

  intro_menu = true;
  in_menu = false;
  in_game = false;
  game_won = false;
  game_lost = false;
  pause_menu = false;
  paused = false;
  level_select = false;
}

Game::~Game()
{

}

bool Game::init()
{
  //Text Font
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font did not load!\n";
  }

  if (!win_texture.loadFromFile("Data/Images/You Win.png"))
  {
    std::cout << "Win Logo did not load!\n";
  }
  win_image.setTexture(win_texture);
  win_image.setPosition(window.getSize().x / 2 - win_image.getGlobalBounds().width / 2,
                        window.getSize().y / 10 * 1 - win_image.getGlobalBounds().height / 2);
  win_image.setScale(1.5, 1.5);

  if (!lose_texture.loadFromFile("Data/Images/You Lose.png"))
  {
    std::cout << "Lose Logo did not load!\n";
  }
  lose_image.setTexture(lose_texture);
  lose_image.setPosition(window.getSize().x / 2 - lose_image.getGlobalBounds().width / 2,
                        window.getSize().y / 10 * 1 - lose_image.getGlobalBounds().height / 2);
  lose_image.setScale(1.5, 1.5);

  if (!blank_texture.loadFromFile("Data/Images/blank.png"))
  {
    std::cout << "Blank background did not load!\n";
  }
  blank_back.setTexture(blank_texture);

  //Buttons
  if (!play_texture.loadFromFile("Data/Images/Play.png"))
  {
    std::cout << "Play Button did not load!\n";
  }
  play_option.setTexture(play_texture);
  play_option.setColor(sf::Color(255, 255, 255, 255));
  play_option.setPosition(
    window.getSize().x / 6 * 2 - play_option.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 5 - play_option.getGlobalBounds().height / 2);

  if (!play2_texture.loadFromFile("Data/Images/Play.png"))
  {
    std::cout << "Play Button did not load!\n";
  }
  play2_option.setTexture(play_texture);
  play2_option.setColor(sf::Color(255, 255, 255, 255));
  play2_option.setScale(1.5, 1.5);
  play2_option.setPosition(
    window.getSize().x / 2 - play2_option.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 9 - play2_option.getGlobalBounds().height / 2);

  if (!quit_texture.loadFromFile("Data/Images/Quit.png"))
  {
    std::cout << "Quit Button did not load\n";
  }
  quit_option.setTexture(quit_texture);
  quit_option.setColor(sf::Color(255, 255, 255, 100));
  quit_option.setPosition(
    window.getSize().x / 6 * 4 - quit_option.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 5 - quit_option.getGlobalBounds().height / 2);

  //Slingshot
  if (!slingshot_texture.loadFromFile("Data/Images/Sling.png"))
  {
    std::cout << "Slingshot did not load!\n";
  }
  slingshot.setTexture(slingshot_texture);
  slingshot.setScale(0.03, 0.03);
  slingshot.setPosition(window.getSize().x / 10 * 1 - slingshot.getGlobalBounds().width / 2,
                        window.getSize().y / 10 * 7 - slingshot.getGlobalBounds().height / 2);

  //Intro Background
  if (!intro_texture.loadFromFile("Data/Images/Intro.png"))
  {
    std::cout << "Intro screen did not load!\n";
  }
  intro_back.setTexture(intro_texture);

  //Main_Menu Background
  if (!mainmenu_texture.loadFromFile("Data/Images/MainMenu.png"))
  {
    std::cout << "Main Menu screen did not load\n";
  }
  mainmenu_background.setTexture(mainmenu_texture);

  //Level Backgrounds
  if ((!level_1.loadFromFile("Data/Images/lvl1.png")) ||
    (!level_2.loadFromFile("Data/Images/lvl2.png")) ||
    (!level_3.loadFromFile("Data/Images/lvl3.png")))
  {
    std::cout << "Level Backgrounds did not load\n";
  }
  level_back.setTexture(level_1);


  if (!fade_texture.loadFromFile("Data/Images/fade.png"))
  {
    std::cout << "Fade texture did not load\n";
  }
  fade_texture.setRepeated(true);
  fade_back.setTexture(fade_texture);
  fade_back.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
  fade_back.setColor(sf::Color(10, 10, 10, 128));

  //Arrow
  if (!arrow_texture.loadFromFile("Data/Images/Arrow.png"))
  {
    std::cout << "Arrow did not load!\n";
  }
  left_arrow.setTexture(arrow_texture);
  left_arrow.setPosition(window.getSize().x / 10 * 1 - left_arrow.getGlobalBounds().width / 2,
                         window.getSize().y / 2 - left_arrow.getGlobalBounds().height / 2);

  right_arrow.setTexture(arrow_texture);
  right_arrow.setScale(-1, 1);
  right_arrow.setPosition(window.getSize().x / 10 * 9 + right_arrow.getGlobalBounds().width / 2,
                         window.getSize().y / 2 - right_arrow.getGlobalBounds().height / 2);

  //Text
  intro_text.setString("Press Space to continue");
  intro_text.setFont(font);
  intro_text.setCharacterSize(50);
  intro_text.setFillColor(sf::Color(255, 255, 255, 255));
  intro_text.setPosition (
    window.getSize().x / 2 - intro_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8) * 7 - intro_text.getGlobalBounds().height / 2);

  pause_text.setString("Paused");
  pause_text.setFont(font);
  pause_text.setCharacterSize(60);
  pause_text.setFillColor(sf::Color(255,255,255,255));
  pause_text.setPosition (
    window.getSize().x / 2 - pause_text.getGlobalBounds().width / 2,
    window.getSize().y / 8 - pause_text.getGlobalBounds().height / 2);

  resume_text.setString("Resume");
  resume_text.setFont(font);
  resume_text.setCharacterSize(40);
  resume_text.setFillColor(sf::Color(255,255,255,255));
  resume_text.setPosition (
    window.getSize().x / 2 - resume_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8 * 5) - resume_text.getGlobalBounds().height / 2);

  quit_text.setString("Quit");
  quit_text.setFont(font);
  quit_text.setCharacterSize(40);
  quit_text.setFillColor(sf::Color(255,255,255,100));
  quit_text.setPosition (
    window.getSize().x / 2 - quit_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8 * 6) - quit_text.getGlobalBounds().height / 2);

  std::stringstream ps;
  ps << player_score;
  std::string player_num = ps.str();
  player_score_str.setString("Score: " + player_num);
  player_score_str.setFont(font);
  player_score_str.setCharacterSize(25);
  player_score_str.setFillColor(sf::Color(255,255,255,255));
  player_score_str.setPosition(5, 5);

  std::stringstream hh;
  hh << highest_score;
  std::string high_num = hh.str();
  high_menu_text.setString("Highscore: " + high_num);
  high_menu_text.setFont(font);
  high_menu_text.setCharacterSize(40);
  high_menu_text.setFillColor(sf::Color(255,255,255,255));
  high_menu_text.setPosition(
    window.getSize().x / 2 - high_menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 8 * 5 - high_menu_text.getGlobalBounds().height / 2);


  birds = new Birds[5];
  for (int i = 0; i < 5; i++)
  {
    int randnum = int (rand() % 6);
    if (randnum == 0)
    {
      birds[i].addTexture(Birds::Bird::Chick);
    }

    else if (randnum == 1)
    {
      birds[i].addTexture(Birds::Bird::Chicken);
    }

    else if (randnum == 2)
    {
      birds[i].addTexture(Birds::Bird::Duck);
    }

    else if (randnum == 3)
    {
      birds[i].addTexture(Birds::Bird::Owl);
    }

    else if (randnum == 4)
    {
      birds[i].addTexture(Birds::Bird::Parrot);
    }

    else if (randnum == 5)
    {
      birds[i].addTexture(Birds::Bird::Penguin);
    }

    if (i == 4)
    {
      birds[i].setVisibility(true);
    }
    else
    {
      birds[i].setVisibility(false);
    }

    birds[i].getSprite()->setScale(0.4, 0.4);
    birds[i].getSprite()->setPosition(slingshot.getPosition().x + birds[i].getSprite()->getGlobalBounds().width / 2, slingshot.getPosition().y + birds[i].getSprite()->getGlobalBounds().height);
    init_position = {birds[i].getSprite()->getPosition().x, birds[i].getSprite()->getPosition().y};
  }

  pigs = new Pigs[3];
  for (int i = 0; i < 3; i++)
  {
    int randnum = int (rand() % 2);
    if (randnum == 0)
    {
      pigs[i].addTexture(Pigs::Pig::Round_pig);
    }
    else if (randnum == 1)
    {
      pigs[i].addTexture(Pigs::Pig::Square_pig);
    }

    pigs[i].setVisibility(true);
    pigs[i].getSprite()->setScale(0.4, 0.4);
    pigs[i].getSprite()->setPosition(rand() % ((window.getSize().x - int(pigs[i].getSprite()->getGlobalBounds().width)) - window.getSize().x / 2 + 1) + window.getSize().x / 2,
                                     rand() % ((window.getSize().y - int(pigs[i].getSprite()->getGlobalBounds().width)) - window.getSize().y / 2 + 1) + window.getSize().y / 2);

  }
  return true;
}

void Game::update(float dt)
{
  if (in_game)
  {
    for (int i = 0; i < 5; i++)
    {
      if (birds[i].getVisibility())
      {
        birds[i].getSprite()->move(
          birds[i].bird_direction.x * birds[i].bird_speed * dt,
          birds[i].bird_direction.y * birds[i].bird_speed * dt);

        if (birds[i].getSprite()->getPosition().x > window.getSize().x + birds[i].getSprite()->getGlobalBounds().width ||
            birds[i].getSprite()->getPosition().x < 0 - birds[i].getSprite()->getGlobalBounds().width ||
            birds[i].getSprite()->getPosition().y > window.getSize().y + birds[i].getSprite()->getGlobalBounds().height)
        {
          birds[i].bird_direction = {0, 0};
          birds[i].getSprite()->setPosition(0, window.getSize().y - birds[i].getSprite()->getGlobalBounds().height);
          birds[i].setVisibility(false);
          bird_counter = bird_counter - 1;
          birds[bird_counter].setVisibility(true);

          if ((pig_counter == 0) && (bird_counter > -1))
          {
            intro_menu = false;
            in_menu = false;
            in_game = false;
            game_won = true;
            game_lost = false;
            pause_menu = false;
            paused = false;
            level_select = false;
          }

          if ((pig_counter > 0) && (bird_counter <= -1))
          {
            intro_menu = false;
            in_menu = false;
            in_game = false;
            game_won = false;
            game_lost = true;
            pause_menu = false;
            paused = false;
            level_select = false;
          }
        }

        if (!birds[i].used_bird)
        {
          if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && birds[i].getSprite()->getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
          {
            birds[i].getSprite()->setPosition(sf::Mouse::getPosition().x - birds[i].getSprite()->getGlobalBounds().width / 2,
              sf::Mouse::getPosition().y - birds[i].getSprite()->getGlobalBounds().height / 2);
            bird_held = true;
          }
        }

        else if (birds[i].used_bird)
        {
          birds[i].bird_direction.y = birds[i].bird_direction.y + 0.981f;
          for (int j = 0; j < 3; j++)
          {
            if (birds[i].getSprite()->getGlobalBounds().intersects(pigs[j].getSprite()->getGlobalBounds()))
            {
              player_score = player_score + 100;
              std::stringstream ps;
              ps << player_score;
              std::string player_num = ps.str();
              player_score_str.setString("Score: " + player_num);
              birds[i].bird_direction = {0.f, 0.f};
              birds[i].getSprite()->setPosition(0,
                                                window.getSize().y - birds[i].getSprite()->getGlobalBounds().height);
              birds[i].setVisibility(false);
              bird_counter = bird_counter - 1;
              birds[bird_counter].setVisibility(true);

              pigs[j].setVisibility(false);
              pig_counter = pig_counter - 1;

              if ((pig_counter == 0) && (bird_counter > -1))
              {
                intro_menu = false;
                in_menu = false;
                in_game = false;
                game_won = true;
                game_lost = false;
                pause_menu = false;
                paused = false;
                level_select = false;
              }

              if ((pig_counter > 0) && (bird_counter <= -1))
              {
                intro_menu = false;
                in_menu = false;
                in_game = false;
                game_won = false;
                game_lost = true;
                pause_menu = false;
                paused = false;
                level_select = false;
              }
            }
          }
        }
      }
    }
  }
}

void Game::render()
{
  if (intro_menu)
  {
    window.draw(intro_back);
    window.draw(intro_text);
  }

  else if (in_menu)
  {
    window.draw(mainmenu_background);
    window.draw(play_option);
    window.draw(quit_option);
  }

  else if (level_select)
  {
    window.draw(mainmenu_background);
    window.draw(level_back);
    level_back.setScale(0.4, 0.4);
    level_back.setPosition(
      window.getSize().x / 2 - level_back.getGlobalBounds().width / 2,
      window.getSize().y / 2 - level_back.getGlobalBounds().height / 2);
    window.draw(left_arrow);
    window.draw(right_arrow);
    window.draw(play2_option);
  }

  else if (pause_menu)
  {
    window.draw(level_back);
    window.draw(player_score_str);
    window.draw(slingshot);
    for (int i = 0; i < 5; i++)
    {
      if (birds[i].getVisibility())
      {
        window.draw(*(birds[i].getSprite()));
      }
    }

    for (int i = 0; i < 3; i++)
    {
      if (pigs[i].getVisibility())
      {
        window.draw(*(pigs[i].getSprite()));
      }
    }

    window.draw(fade_back);
    window.draw(pause_text);
    window.draw(resume_text);
    window.draw(quit_text);
  }

  else if (game_won)
  {
    window.draw(blank_back);
    player_score_str.setCharacterSize(70);
    player_score_str.setPosition(window.getSize().x / 2 - player_score_str.getGlobalBounds().width / 2,
                                 window.getSize().y / 8 * 3 - player_score_str.getGlobalBounds().height / 2);
    window.draw(player_score_str);
    if (player_score > highest_score)
    {
      highest_score = player_score;
    }
    std::stringstream hh;
    hh << highest_score;
    std::string high_num = hh.str();
    high_menu_text.setString("Highscore: " + high_num);
    high_menu_text.setPosition(
      window.getSize().x / 2 - high_menu_text.getGlobalBounds().width / 2,
      window.getSize().y / 8 * 4 - high_menu_text.getGlobalBounds().height / 2);
    window.draw(high_menu_text);
    window.draw(intro_text);
    window.draw(win_image);
  }

  else if (game_lost)
  {
    window.draw(blank_back);
    player_score_str.setCharacterSize(70);
    player_score_str.setPosition(window.getSize().x / 2 - player_score_str.getGlobalBounds().width / 2,
                                 window.getSize().y / 8 * 3 - player_score_str.getGlobalBounds().height / 2);
    window.draw(player_score_str);
    if (player_score > highest_score)
    {
      highest_score = player_score;
    }
    std::stringstream hh;
    hh << highest_score;
    std::string high_num = hh.str();
    high_menu_text.setString("Highscore: " + high_num);
    high_menu_text.setPosition(
      window.getSize().x / 2 - high_menu_text.getGlobalBounds().width / 2,
      window.getSize().y / 8 * 4 - high_menu_text.getGlobalBounds().height / 2);
    window.draw(high_menu_text);
    window.draw(intro_text);
    window.draw(lose_image);
  }

  else if (in_game)
  {
    window.draw(level_back);
    player_score_str.setCharacterSize(25);
    player_score_str.setPosition(5,
                                 5);
    window.draw(player_score_str);

    if (current_level_selected == 1)
    {
      slingshot.setPosition(window.getSize().x / 10 * 1 - slingshot.getGlobalBounds().width / 2,
                            window.getSize().y / 10 * 7.5 - slingshot.getGlobalBounds().height / 2);
    }
    else if (current_level_selected == 2)
    {
      slingshot.setPosition(window.getSize().x / 10 * 1 - slingshot.getGlobalBounds().width / 2,
                            window.getSize().y / 10 * 7.1 - slingshot.getGlobalBounds().height / 2);
    }
    else if (current_level_selected == 3)
    {
      slingshot.setPosition(window.getSize().x / 10 * 1 - slingshot.getGlobalBounds().width / 2,
                            window.getSize().y / 10 * 7.3 - slingshot.getGlobalBounds().height / 2);
    }
    window.draw(slingshot);

    for (int i = 0; i < 5; i++)
    {
      if (birds[i].getVisibility())
      {
        window.draw(*(birds[i].getSprite()));
      }
    }

    for (int i = 0; i < 3; i++)
    {
      if (pigs[i].getVisibility())
      {
        window.draw(*(pigs[i].getSprite()));
      }
    }
  }
}

void Game::keyPressed(sf::Event event)
{
  if (in_menu &&
      (event.key.code == sf::Keyboard::Left) ||
      (event.key.code == sf::Keyboard::Right) ||
      (event.key.code == sf::Keyboard::A) ||
      (event.key.code == sf::Keyboard::D))
  {
    if (!level_select)
    {
      play_selected = !play_selected;
      if (play_selected)
      {
        play_option.setColor(sf::Color(255, 255, 255, 255));
        quit_option.setColor(sf::Color(255, 255, 255, 100));
      }

      else
      {
        play_option.setColor(sf::Color(255, 255, 255, 100));
        quit_option.setColor(sf::Color(255, 255, 255, 255));
      }
    }
  }

  if (level_select)
  {
    if ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::A))
    {
      if (current_level_selected == 1)
      {
        current_level_selected = 3;
        level_selector(current_level_selected);
      }
      else
      {
        current_level_selected = current_level_selected - 1;
        level_selector(current_level_selected);
      }
    }

    else if ((event.key.code == sf::Keyboard::Right) || (event.key.code == sf::Keyboard::D))
    {
      if (current_level_selected == 3)
      {
        current_level_selected = 1;
        level_selector(current_level_selected);
      }
      else
      {
        current_level_selected = current_level_selected + 1;
        level_selector(current_level_selected);
      }
    }
  }

  if ((paused) && (pause_menu) &&
      (event.key.code == sf::Keyboard::Up) ||
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::W) ||
      (event.key.code == sf::Keyboard::S))
  {
    resume_selected = !resume_selected;
    if (resume_selected)
    {
      resume_text.setFillColor(sf::Color(255,255,255,255));
      quit_text.setFillColor(sf::Color(255,255,255,100));

    }
    else
    {
      resume_text.setFillColor(sf::Color(255,255,255,100));
      quit_text.setFillColor(sf::Color(255,255,255,255));
    }

  }

  if (event.key.code == sf::Keyboard::Enter)
  {
    if ((in_menu) && (play_selected))
    {
      in_menu = false;
      level_select = true;

    }
    else if ((in_menu) && (!play_selected))
    {
      window.close();
    }

    else if (level_select)
    {
      intro_menu = false;
      in_menu = false;
      in_game = true;
      game_won = false;
      game_lost = false;
      pause_menu = false;
      paused = false;
      level_select = false;
      level_back.setScale(1, 1);
      level_back.setPosition(0, 0);
    }

    else if ((paused) && (resume_selected) && (pause_menu))
    {
      paused = false;
      pause_menu = false;
      in_game = true;
    }

    else if ((paused) && (!resume_selected) && (pause_menu))
    {
      paused = false;
      pause_menu = false;
      in_menu = true;
      in_game = false;
      reset();
    }
  }

  if (event.key.code == sf::Keyboard::Space)
  {
    if (intro_menu)
    {
      in_menu         = true;
      intro_menu      = false;
      game_won        = false;
      game_lost       = false;
      pause_menu      = false;
    }

    if (game_won)
    {
      intro_menu = false;
      in_menu = true;
      in_game = false;
      game_won = false;
      game_lost = false;
      pause_menu = false;
      paused = false;
      reset();
    }

    if (game_lost)
    {
      intro_menu = false;
      in_menu = true;
      in_game = false;
      game_won = false;
      game_lost = false;
      pause_menu = false;
      paused = false;
      reset();
    }
  }

  if (event.key.code == sf::Keyboard::Escape)
  {
    if (in_game)
    {
      paused = !paused;

      if (paused)
      {
        in_menu         = false;
        intro_menu      = false;
        game_won        = false;
        game_lost       = false;
        pause_menu      = true;
        in_game         = true;
      }
      else if (!paused)
      {
        in_menu         = false;
        intro_menu      = false;
        game_won        = false;
        game_lost       = false;
        pause_menu      = false;
        in_game         = true;
      }
    }

    if (level_select)
    {
      in_menu = true;
      level_select = false;
    }
  }
}

void Game::mouseMove(sf::Event event)
{
  if (in_menu)
  {
    if ((play_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (!play_selected))
    {
      play_selected = true;
      play_option.setColor(sf::Color(255, 255, 255, 255));
      quit_option.setColor(sf::Color(255, 255, 255, 100));
    }

    else if ((quit_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (play_selected))
    {
      play_selected = false;
      play_option.setColor(sf::Color(255, 255, 255, 100));
      quit_option.setColor(sf::Color(255, 255, 255, 255));
    }
  }

  if ((paused) && (pause_menu))
  {
    if ((resume_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (!resume_selected))
    {
      resume_selected = true;
      resume_text.setFillColor(sf::Color(255,255,255,255));

      quit_text.setFillColor(sf::Color(255,255,255,100));
    }

    else if ((quit_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (resume_selected))
    {
      resume_selected = false;
      resume_text.setFillColor(sf::Color(255,255,255,100));

      quit_text.setFillColor(sf::Color(255,255,255,255));
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  if (in_menu)
  {
    if ((play_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (play_selected))
    {
      in_menu = false;
      level_select = true;
    }

    else if ((quit_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (!play_selected))
    {
      window.close();
    }
  }

  if (level_select)
  {
    if (left_arrow.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
    {
      if (current_level_selected == 1)
      {
        current_level_selected = 3;
        level_selector(current_level_selected);
      }
      else
      {
        current_level_selected = current_level_selected - 1;
        level_selector(current_level_selected);
      }
    }

    else if (right_arrow.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
    {
      if (current_level_selected == 3)
      {
        current_level_selected = 1;
        level_selector(current_level_selected);
      }
      else
      {
        current_level_selected = current_level_selected + 1;
        level_selector(current_level_selected);
      }
    }

    else if (play2_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
    {
      intro_menu = false;
      in_menu = false;
      in_game = true;
      game_won = false;
      game_lost = false;
      pause_menu = false;
      paused = false;
      level_select = false;
      level_back.setScale(1, 1);
      level_back.setPosition(0, 0);
    }
  }

  if ((paused) && (pause_menu))
  {
    if ((resume_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (resume_selected))
    {
      paused = false;
      pause_menu = false;
      in_game = true;
    }

    else if ((quit_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (!resume_selected))
    {
      paused = false;
      pause_menu = false;
      in_menu = true;
      in_game = false;
      reset();
    }
  }
}

void Game::mouseReleased(sf::Event event)
{
  for (int i = 0; i < 5; i++)
  {
    if (birds[i].getVisibility())
    {
      if (!birds[i].used_bird)
      {
        if (bird_held)
        {
          bird_held = false;
          birds[i].bird_direction.x =
            init_position.x - birds[i].getSprite()->getPosition().x;
          birds[i].bird_direction.y =
            init_position.y - birds[i].getSprite()->getPosition().y;
          birds[i].used_bird = true;
        }
      }
    }
  }
}

void Game::keyReleased(sf::Event event)
{

}

void Game::level_selector(int level_selected)
{
  switch (level_selected)
  {
    case 1:
    {
      level_back.setTexture(level_1);
      break;
    }

    case 2:
    {
      level_back.setTexture(level_2);
      break;
    }

    case 3:
    {
      level_back.setTexture(level_3);
      break;
    }

    default:
    {
      std::cout << "Didn't work (Level Selector)\n";
      break;
    }

  }
}

void Game::reset()
{
  player_score = 0;
  std::stringstream ps;
  ps << player_score;
  std::string player_num = ps.str();
  player_score_str.setString("Score: " + player_num);

  for (int i = 0; i < 5; i++)
  {
    birds[i].bird_direction = {0, 0};
    birds[i].getSprite()->setPosition(slingshot.getPosition().x + birds[i].getSprite()->getGlobalBounds().width / 2, slingshot.getPosition().y + birds[i].getSprite()->getGlobalBounds().height / 2);
    birds[i].used_bird = false;
    if (i == 4)
    {
      birds[i].setVisibility(true);
    }
    else
    {
      birds[i].setVisibility(false);
    }
  }

  bird_counter = 4;

  for (int j = 0; j < 3; j++)
  {
    pigs[j].setVisibility(true);
    pigs[j].getSprite()->setPosition(rand() % ((window.getSize().x - int(pigs[j].getSprite()->getGlobalBounds().width)) - window.getSize().x / 2 + 1) + window.getSize().x / 2,
                                     rand() % ((window.getSize().y - int(pigs[j].getSprite()->getGlobalBounds().width)) - window.getSize().y / 2 + 1) + window.getSize().y / 2);
  }

  pig_counter = 3;
}