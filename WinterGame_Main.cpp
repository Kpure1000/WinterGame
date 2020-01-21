#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
//
#include"Plat.h"
#include"Player.h"
using namespace sf;
using namespace std;

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#define CannotResize  (sf::Style::Titlebar |  sf::Style::Close)

int main()
{
	const float AppW = 900, AppH = 900;
	RenderWindow App(VideoMode((unsigned int)AppW, (unsigned int)AppH), "WinterGame", CannotResize);
	App.setFramerateLimit(120);

	sf::View Player_ca;
	App.setView(Player_ca);

	vector<GameObject>Plats;
	

	AssetManager SourceManager;

	sf::Sprite Plat1_sp(AssetManager::GetTexture(PlatForm));

	sf::Sprite Player1_sp(AssetManager::GetTexture(Player_f));
	
	GameObject* Object_Player1;

	Player Player1(Player1_sp, App, "Platyer1");
	Player1.SetGravity(true);
	Player1.SetScale({ 5,5 });
	Player1.SetPosition({ AppW / 2,0 });

	Plat Plat1(Plat1_sp, App, "Plat1");
	Plat1.SetGravity(false);
	Plat1.SetScale({ 30,30 });
	Plat1.SetPosition({ AppW / 2, AppH });

	Plat1.SetUp();
	Player1.SetUp();

	while (App.isOpen())
	{
		Event ev;
		while (App.pollEvent(ev))
		{
			if (ev.type == Event::Closed or ev.key.code == Keyboard::Key::Escape)
			{
				App.close();
			}
		}

		App.clear(Color(0, 0, 0, 0));

		Object_Player1 = &Player1;

		Object_Player1->Update();

		Player_ca.setCenter(Object_Player1->GetPosition());

		Object_Player1 = &Plat1;

		Object_Player1->Update();

		App.setView(Player_ca);

		App.display();

	}
	return 0;
}