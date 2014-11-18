#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerCharacter.h"
#include "GameObjectManager.h"


class Game
{

public:
	/*
	* Starts the game.
	*/
	static void start();
	static sf::RenderWindow& getWindow();
	const static sf::Event& GetInput();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	static std::vector<VisibleGameObject *> rigidBodyCoords;

private:

	static void createLevelBlocks();

	static void handleCamera();

	static void createFloor();

	static void handleSurfaces();

	static void initObject(VisibleGameObject * object, sf::Vector2f position, std::string name);

	static std::vector<VisibleGameObject *> findRigidBodies();

	/*
	* Handles exiting when _gameState is Exiting.
	*/
	static bool isExiting();

	/*
	* Handles the game in different states while constantly looping to poll for changes.
	*/
	static void gameLoop();

	/*
	* Shows the splash screen on the main window.
	*/
	static void showSplashScreen();

	/*
	* Shows the main menu on the main window. Changes _gameState based on button pressed.
	*/
	static void showMenu();

	static void showVictoryScreen();

	static bool isVictory();

	/*
	* Denotes the current game state.
	*/
	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting, Restart, Victory
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
	static sf::View _view;
	static float level_width;
	static float level_height;
	static bool game_victory;
	static sf::Font font;
	static sf::Text coins;
};
