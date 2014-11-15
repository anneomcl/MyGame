#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Background.h"
#include "RigidSurface.h"
#include "RigidSurface_Floor.h"
#include "RigidSurface_Mystery.h"
#include "RigidSurface_Pipe.h"
#include <iostream>

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
std::vector<VisibleGameObject *> Game::rigidBodyCoords;
GameObjectManager Game::_gameObjectManager;
sf::View Game::_view;
float Game::level_width;
float Game::level_height;
sf::Font Game::font;
sf::Text Game::coins;


void Game::initObject(VisibleGameObject * object, sf::Vector2f position, std::string name)
{
	_gameObjectManager.add(name, object);
	object->setPosition(position.x, position.y);
}


void Game::start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Anne McLaughlin Demo");
	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	_view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	//font.loadFromFile("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/gameFont.ttf");


	//coins.setFont(Game::font);
	//coins.setString("Coins: ");
	//coins.setCharacterSize(24);
	//coins.setColor(sf::Color::Black);
	//_mainWindow.draw(coins);

	initObject(new PlayerCharacter, sf::Vector2f(SCREEN_WIDTH / 4, 1000), "PlayerCharacter");

	Background * bg = new Background();
	level_width = bg->getSprite().getGlobalBounds().width;
	level_height = bg->getSprite().getGlobalBounds().height;

	createFloor();

	_gameObjectManager.add("Background", bg);

	createLevelBlocks();

	rigidBodyCoords = findRigidBodies();

	_gameState = Game::ShowingSplash;

	while (!isExiting())
	{
		gameLoop();
	}

	_mainWindow.close();
}

void Game::createLevelBlocks()
{
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200, 1350 - 500), "block5");
	for (int i = 0; i < 5; i++)
	{
		initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200 + 300 + i * 100, 1350 - 500 - 100), "block" + std::to_string(i));
	}
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200 + 300 + 300, 1350 - 500 - 300 - 100), "block6");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 800 + 400, 1000), "pipe1");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600, 1000), "pipe2");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600, 900), "pipe3");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 1000), "pipe4");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 900), "pipe5");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 800), "pipe6");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 1000), "pipe7");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 900), "pipe8");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 800), "pipe9");
	//RigidSurface_Floor * pit = (RigidSurface_Floor *)_gameObjectManager.get("block56");
	//delete pit;
}

void Game::createFloor()
{
	for (int i = 0; i < level_width / 100 + 1; i++)
	{
		initObject(new RigidSurface_Floor, sf::Vector2f(i * 100 + 50, 1100), "floor" + std::to_string(i));
	}

	printf("%d", _gameObjectManager.get("floor1")->getSprite().getPosition().y);
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::showSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::showMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		{
			_gameState = Game::Exiting;
			break;
		}

	case MainMenu::Play:
		{
			_gameState = Game::Playing;
			break;
		}
	}
}

void Game::handleSurfaces()
{
	PlayerCharacter * player = (PlayerCharacter *)_gameObjectManager.get("PlayerCharacter");
	for (int i = 0; i < rigidBodyCoords.size(); ++i)
	{
		if (player->getSprite().getGlobalBounds().intersects(rigidBodyCoords[i]->getSprite().getGlobalBounds()))
		{
			if (rigidBodyCoords[i]->getType() == "RigidSurface_Mystery")
			{
				//To:Do: fall, don't fly
				RigidSurface_Mystery * block = (RigidSurface_Mystery *) rigidBodyCoords[i];
				if (block->times_hit < 3)
				{
					player->coins++;
					block->times_hit++;
				}
				else
				{
					//block is dead
				}

				player->velocity.x = -player->velocity.x;
				if (player->velocity.y < 0)
				{
					player->velocity.y = -2* player->velocity.y;
				}

				if (player->velocity.y > 0)
				{
					player->setPosition(player->getPosition().x, player->getPosition().y - 1);
					player->grounded = true;
				}
			}

			else
			{
				if (player->velocity.y > 0)
				{
					player->setPosition(player->getPosition().x, player->getPosition().y - 1);
					//player->velocity.x = -player->velocity.x;
					//TO-DO: Distinguish between bumping horizontally and landing vertically on blocks.
					//TO-DO: Make kitty stop floating
					player->grounded = true;
				}
				else
				{
					player->velocity.x = -player->velocity.x;
				}
				
			}
		}
	}
}

void Game::gameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState)
	{
		case Game::ShowingMenu:
		{
			showMenu();
			break;
		}

		case Game::ShowingSplash:
		{
			showSplashScreen();
			break;
		}

		case Game::Playing:
		{
			rigidBodyCoords = findRigidBodies();
			_gameObjectManager.updateAll();
			_gameObjectManager.drawAll(_mainWindow);

			handleSurfaces();

			handleCamera();

			_mainWindow.setView(_view);
			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

			if ((currentEvent.type == sf::Event::KeyPressed) && (currentEvent.key.code == sf::Keyboard::Escape))
				showMenu();
			if ((currentEvent.type == sf::Event::KeyPressed) && (currentEvent.key.code == sf::Keyboard::R))
				_gameState = Game::Restart;
			break;
		}

		case Game::Restart:
		{
			//start();
		}
	}
}

sf::RenderWindow& Game::getWindow()
{
	return _mainWindow;
}

void Game::handleCamera()
{
	PlayerCharacter * player = (PlayerCharacter *)_gameObjectManager.get("PlayerCharacter");

	float pos_x = player->getPosition().x + 10 - (SCREEN_WIDTH / 2);
	float pos_y = player->getPosition().y + 10 - (SCREEN_HEIGHT / 2);

	if (pos_x < 0)
	{
		pos_x = 0;
	}

	if (pos_y < 0)
	{
		pos_y = 0;
	}

	_view.reset(sf::FloatRect(pos_x, pos_y, SCREEN_WIDTH, SCREEN_HEIGHT));
}

const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

std::vector<VisibleGameObject *> Game::findRigidBodies()
{
	std::string type = "RigidSurface";
	std::vector<VisibleGameObject *> surfaces_vector = _gameObjectManager.getByType("RigidSurface");
	return surfaces_vector;
}
