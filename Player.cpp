#include "Player.h"

Player::Player(sf::Sprite& sp, sf::RenderWindow& app,
	std::string const& objecttypename) :GameObject(sp, app, objecttypename)
{}

void MoverX(Player& player,sf::Vector2f speed) {
	if (KeyPressing and KeyEvent(Left)) {
		player.newx -= speed.x;
	}
	if (KeyPressing and KeyEvent(Right)) {
		player.newx += speed.x;
	}
}

void MoverJump(Player& player) {
	if (KeyPressing and KeyEvent(Up)) {
		if (player.CollisionCheck() == player.IsLanding) {
			player.dy = -20.0f;
			player.newy += player.dy;
		}
	}
}

int Player::CollisionCheck() {
	if (newy >= App.getSize().y) { //  if not landing, JumpBaning 
		newy = (float)App.getSize().y;
		return IsLanding;
	}
	return IsTop;
}

void Player::Draw() {
	App.draw(sprite);
}

void Player::SetUp() {
	newx = sprite.getPosition().x;
	newy = sprite.getPosition().y;

	sf::IntRect size = sprite.getTextureRect();
	sprite.setOrigin((float)size.width / 2, (float)size.height);
}

void Player::Update() {
	newx = sprite.getPosition().x;
	newy = sprite.getPosition().y;

	Gravity();

	thread MoveThread(MoverJump, ref(*this));
	MoveThread.join();

	sprite.setPosition(newx, newy);

	Draw();
}