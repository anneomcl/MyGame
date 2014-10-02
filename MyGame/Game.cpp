#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Background.h"

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;

void Game::start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Anne McLaughlin Demo");

	PlayerCharacter * player = new PlayerCharacter();
	player->setPosition(SCREEN_WIDTH/4, 650);

	Background * bg = new Background();

	_gameObjectManager.add("Background", bg);
	_gameObjectManager.add("PlayerCharacter", player);
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
			_gameObjectManager.updateAll();
			_gameObjectManager.drawAll(_mainWindow);
			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

			if ((currentEvent.type == sf::Event::KeyPressed) && (currentEvent.key.code == sf::Keyboard::Escape))
				showMenu();
			break;
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
