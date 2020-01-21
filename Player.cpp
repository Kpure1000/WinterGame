#include "Player.h"

Player::Player(sf::Sprite& sp, sf::RenderWindow& app, std::string const& objecttypename)
	:GameObject(sp, app, objecttypename)
{

}

void Player::MoverEvent(sf::Vector2f speed)
{
	if (KeyPressing and KeyEvent(Left))
	{
		newx -= speed.x;
	}
	if (KeyPressing and KeyEvent(Right))
	{
		newx += speed.x;
	}
	if (KeyPressing and KeyEvent(Space))
	{
		if (CollisionCheck() == IsLanding)
		{
			dy = -18.0f;
			newy += dy;
		}
	}
}

int Player::CollisionCheck()
{
	//if not landing, JumpBaning
	if (newy >= App.getSize().y)
	{
		newy = App.getSize().y;
		return IsLanding;
	}
	return IsTop;
}

void Player::Draw()
{
	App.draw(sprite);
}

void Player::SetUp()
{
	newx = sprite.getPosition().x,
		newy = sprite.getPosition().y;

	sf::IntRect size = sprite.getTextureRect();
	sprite.setOrigin((float)size.width / 2, (float)size.height);
}

void Player::Update()
{
	newx = sprite.getPosition().x,
		newy = sprite.getPosition().y;
	Gravity();
	MoverEvent(MoveSpeed);
	sprite.setPosition(newx, newy);

	Draw();
}