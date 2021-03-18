#include <string>
#ifndef PLAYER
#define PLAYER

class Player
{
private:
  std::string player_name{};
public:
  std::string get_name();
  Player(std::string name);
  ~Player();
};

std::string Player::get_name()
{
  return player_name;
}

Player::Player(std::string name)
{
  player_name = name;
}

Player::~Player(){}

#endif
