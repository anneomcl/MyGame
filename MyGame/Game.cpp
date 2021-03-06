#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Background.h"
#include "RigidSurface.h"
#include "RigidSurface_Floor.h"
#include "RigidSurface_Mystery.h"
#include "RigidSurface_Pipe.h"
#include "RigidSurface_Brick.h"
#include "Coin.h"
#include <iostream>

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
std::vector<VisibleGameObject *> Game::rigidBodyCoords;
GameObjectManager Game::_gameObjectManager;
sf::View Game::_view;
float Game::level_width;
float Game::level_height;
sf::Font * Game::font = new sf::Font();
sf::Text * Game::coinstring = new sf::Text();
bool Game::game_victory;
int Game::coin_animation_frames = 150;
bool Game::display_coin = false;
std::vector<RigidSurface_Mystery *> Game::mystery_blocks;


void Game::initObject(VisibleGameObject * object, sf::Vector2f position, std::string name)
{
	_gameObjectManager.add(name, object);
	object->setPosition(position.x, position.y);
	if ((name).find("mblock") == 0)
	{
		mystery_blocks.push_back((RigidSurface_Mystery *) object);
	}
}

void Game::start_again()
{
	PlayerCharacter * player = (PlayerCharacter *)_gameObjectManager.getByTypeSingle("PlayerCharacter");
	player->setPosition(500, 1000);
	player->grounded = true;
}

void Game::start_loss()
{
	if (_gameState != Uninitialized)
		return;

	game_victory = 0;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Anne McLaughlin Demo");
	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	_view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	PlayerCharacter * player = (PlayerCharacter *)_gameObjectManager.getByTypeSingle("PlayerCharacter");
	player->setPosition(500, 1000);
	player->coins = 0;
	player->lives = 0;
	player->grounded = true;


	reset_mystery_blocks();


	_gameState = Game::ShowingSplashLoss;

	while (!isExiting())
	{
		gameLoop();
	}
	_mainWindow.close();
}

void Game::start_victory(void)
{
	if (_gameState != Uninitialized)
		return;

	game_victory = 0;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Anne McLaughlin Demo");
	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	_view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	PlayerCharacter * player = (PlayerCharacter *) _gameObjectManager.getByTypeSingle("PlayerCharacter");
	player->setPosition(500, 1000);
	player->coins = 0;
	player->lives = 0;
	player->grounded = true;


	reset_mystery_blocks();

	/*Background * bg = new Background();
	level_width = bg->getSprite().getGlobalBounds().width;
	level_height = bg->getSprite().getGlobalBounds().height;

	createFloor();

	_gameObjectManager.add("Background", bg);

	createLevelBlocks();

	rigidBodyCoords = findRigidBodies();*/

	_gameState = Game::ShowingSplashVictory;

	while (!isExiting())
	{
		gameLoop();
	}
	_mainWindow.close();
}

void Game::reset_mystery_blocks()
{
	for (int i = 0; i < mystery_blocks.size(); i++)
	{
		mystery_blocks[i]->times_hit = 0;
	}
}

void Game::start(void)
{
	if (_gameState != Uninitialized)
		return;

	game_victory = 0;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Anne McLaughlin Demo");
	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	_view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	/*if (!font->loadFromFile("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/AGENTORANGE.TTF"))
	{
		std::cout << "error" << std::endl;
	}

	coinstring->setFont(*Game::font);
	coinstring->setString("Coins: ");
	coinstring->setCharacterSize(72);
	coinstring->setColor(sf::Color::Black);
	coinstring->setStyle(sf::Text::Regular);
	
	sf::FloatRect textRect = coinstring->getLocalBounds();

	coinstring->setOrigin(textRect.width / 2, textRect.height / 2);
	coinstring->setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));*/

	initObject(new PlayerCharacter, sf::Vector2f(/*SCREEN_WIDTH / 4*/ 9*SCREEN_WIDTH/10, 1000), "PlayerCharacter");

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
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200, 1350 - 500), "mblock5");
	for (int i = 0; i < 5; i++)
	{
		if (i%2 == 0)
			initObject(new RigidSurface_Brick, sf::Vector2f(level_width / 4 + 200 + 300 + i * 100, 1350 - 500 - 100), "block" + std::to_string(i));
	
		else
			initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200 + 300 + i * 100, 1350 - 500 - 100), "mblock" + std::to_string(i));

	}
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 200 + 300 + 300, 1350 - 500 - 300 - 100), "mblock6");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 800 + 400, 1000), "pipe1");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600, 1000), "pipe2");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600, 900), "pipe3");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 1000), "pipe4");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 900), "pipe5");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 600 + 300, 800), "pipe6");

	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 1000), "pipe7");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 900), "pipe8");
	initObject(new RigidSurface_Pipe, sf::Vector2f(level_width / 4 + 1200 + 900 + 500, 800), "pipe9");
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 2600 + 500, 600), "mblock7");

	initObject(new RigidSurface_Brick, sf::Vector2f(level_width / 4 + 3100 + 1000, 700), "block8");
	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 3100 + 1100, 700), "mblock9");
	initObject(new RigidSurface_Brick, sf::Vector2f(level_width / 4 + 3100 + 1200, 700), "block10");

	initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 4400 + 1100, 700), "mblock11");
	for (int i = 0; i < 12; i++)
	{
		if (i != 11)
			initObject(new RigidSurface_Brick, sf::Vector2f(level_width / 4 + 4400 + i * 100, 400), "block" + std::to_string(i+11));

		else
			initObject(new RigidSurface_Mystery, sf::Vector2f(level_width / 4 + 4400 + i * 100, 400), "mblock" + std::to_string(i + 11));

	}
	initObject(new RigidSurface_Brick, sf::Vector2f(7950, 1000), "block_victory");
}

void Game::createFloor()
{
	for (int i = 0; i < level_width / 100 + 1; i++)
	{
		if (i != 56 && i != 57 && i != 66 && i != 67 && i != 68)
		{
			initObject(new RigidSurface_Floor, sf::Vector2f(i * 100 + 50, 1100), "floor" + std::to_string(i));
		}
	}
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

bool Game::isVictory()
{
	return game_victory;
}

void Game::showSplashScreen(std::string file)
{
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow, file);
	_gameState = Game::ShowingMenu;
}

void Game::showVictoryScreen()
{
	/*SplashScreen victory;
	victory.show(_mainWindow, "C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/Victory.png");*/
	_gameState = Game::Exiting;
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
	RigidSurface_Brick * v_block = (RigidSurface_Brick *)_gameObjectManager.get("block_victory");

	if (player->getSprite().getGlobalBounds().intersects(v_block->getSprite().getGlobalBounds()))
	{
		game_victory = 1;
	}

	if (display_coin)
	{
		coin_animation_frames--;
		if (coin_animation_frames <= 0)
		{
			display_coin = false;
			Coin * coin = (Coin *) _gameObjectManager.getByTypeSingle("Coin");
			coin->isVisible = false;
			coin_animation_frames = 150;
		}
	}

	for (int i = 0; i < rigidBodyCoords.size(); ++i)
	{
		if (player->getSprite().getGlobalBounds().intersects(rigidBodyCoords[i]->getSprite().getGlobalBounds()))
		{
			if (rigidBodyCoords[i]->getType() == "RigidSurface_Mystery")
			{
				RigidSurface_Mystery * block = (RigidSurface_Mystery *) rigidBodyCoords[i];
				if (block->times_hit < 3)
				{
					display_coin = true;
					Coin * new_coin = new Coin();
					initObject(new_coin,
						sf::Vector2f(rigidBodyCoords[i]->getSprite().getGlobalBounds().left, rigidBodyCoords[i]->getSprite().getGlobalBounds().top - 100)
						, "coin" + std::to_string(player->coins));
					player->coins++;
					block->times_hit++;
					std::cout << "Coins: "  << player->coins << std::endl;
					std::cout << "Lives: " << player->lives << std::endl;
					if (player->coins % 10 == 0)
					{
						player->lives++;
					}
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
			showSplashScreen("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/MyGameScreen.png");
			break;
		}

		case Game::ShowingSplashVictory:
		{
			showSplashScreen("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/Victory.png");
			break;
		}

		case Game::ShowingSplashLoss:
		{
			showSplashScreen("C:/Users/Anne/Documents/Visual Studio 2013/Projects/MyGame/Graphics/Loss.png");
			break;
		}

		case Game::Playing:
		{
			rigidBodyCoords = findRigidBodies();
			_gameObjectManager.updateAll();
			//_mainWindow.draw(*coinstring);
			_gameObjectManager.drawAll(_mainWindow);


			PlayerCharacter * player = (PlayerCharacter *)_gameObjectManager.get("PlayerCharacter");

			if (player->getPosition().y > 2000)
			{
				if (player->lives > 0)
				{
					player->lives--;
					start_again();
				}

				else
				{
					_gameState = Loss;
					start_loss();
					break;
				}
			}

			handleSurfaces();

			handleCamera();

			_mainWindow.setView(_view);

			_mainWindow.display();


			if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

			if ((currentEvent.type == sf::Event::KeyPressed) && (currentEvent.key.code == sf::Keyboard::Escape))
				showMenu();

			if(game_victory != 0)
			{
				_gameState = Game::Victory;
			}

			break;
		}

		case Game::Victory:
		{
			_gameState = Game::Uninitialized;
			start_victory();
			break;
		}

		case Game::Loss:
		{
			_gameState = Game::Uninitialized;
			start_loss();
			break;
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
