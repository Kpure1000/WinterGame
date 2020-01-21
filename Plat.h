#pragma once
#include"GameObject.h"
class Plat : public GameObject
{
private:
public:

	Plat(sf::Sprite& sp, sf::RenderWindow& app, 
		std::string const& objecttypename);

public: //  Control

	virtual void MoverEvent(sf::Vector2f speed);

	virtual int CollisionCheck();

public: //  Game

	virtual void Draw();

	virtual void SetUp();

	virtual void Update();

};

