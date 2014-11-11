#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Background.h"
#include "RigidSurface.h"
#include <iostream>

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
std::vector<VisibleGameObject *> Game::rigidBodyCoords;
GameObjectManager Game::_gameObjectManager;

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

	initObject(new PlayerCharacter, sf::Vector2f(SCREEN_WIDTH / 4, 600), "PlayerCharacter");

	Background * bg = new Background();

	RigidSurface * block = new RigidSurface();
	block->setPosition(SCREEN_WIDTH / 2, 600);

	RigidSurface * block2 = new RigidSurface();
	block2->setPosition(3*SCREEN_WIDTH / 4, 600);

	RigidSurface * floor1 = new RigidSurface();
	floor1->setPosition(100, 700);

	RigidSurface * floor2 = new RigidSurface();
	floor2->setPosition(SCREEN_WIDTH/3, 700);

	_gameObjectManager.add("Background", bg);
	_gameObjectManager.add("block", block);
	_gameObjectManager.add("block2", block2);
	_gameObjectManager.add("floor1", floor1);
	_gameObjectManager.add("floor2", floor2);

	rigidBodyCoords = findRigidBodies();

	_gameState = Game::ShowingSplash;

	while (!isExiting())
	{
		gameLoop();
	}

	_mainWindow.close();
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
			player->setPosition(player->getPosition().x, player->getPosition().y - 1);
			player->velocity.x = -player->velocity.x;
			player->grounded = true;
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
