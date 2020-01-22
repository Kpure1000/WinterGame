#pragma once
#include "GameObject.h"
#include"Setting.h"
class Player :
	public GameObject {
private:

public:

	Player(sf::Sprite& sp, sf::RenderWindow& app,
		std::string const& objecttypename);

public: //  Control

	friend void MoverX(Player& player, sf::Vector2f speed);

	friend void MoverJump(Player& player);

	virtual int CollisionCheck();

public: //  Game

	virtual void Draw();

	virtual void SetUp();

	virtual void Update();
};

