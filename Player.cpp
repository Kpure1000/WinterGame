#include "Player.h"

Player::Player(sf::Sprite& sp, sf::RenderWindow& app,
	std::string const& objecttypename) :GameObject(sp, app, objecttypename)
{}

void MoverX(Player& player,sf::Vector2f speed) {
	if (KeyPressing and KeyEvent(Left)) {
		player.newx -= speed.x;
	}
	else if (KeyPressing and KeyEvent(Right)) {
		player.newx += speed.x;
	}
}

void MoverJump(Player& player, sf::RenderWindow& App) {
	int Count_sum = 0;
	time_t StartTime = 0;
	time_t JumpTime = 0;
	while (App.isOpen()) {
		if (StartTime == 0) {
			StartTime = clock();
		}
		JumpTime = clock();
		if (JumpTime - StartTime >= 1000
			and KeyPressing and KeyEvent(Up)) {
			if (player.CollisionCheck() == player.IsLanding) {
				player.dy = -20.0f;
				player.newy += player.dy;
				Count_sum++; Count_sum %= INT_MAX;
				cout << "Debug: JumpEvent Checked: " << Count_sum << endl;
				StartTime = 0;
			}
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

	thread MoveXThread(MoverX, ref(*this), ref(MoveSpeed));
	MoveXThread.join();

	sprite.setPosition(newx, newy);

	Draw();
}