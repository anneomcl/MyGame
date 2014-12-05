#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerCharacter.h"
#include "GameObjectManager.h"
#include "RigidSurface_Mystery.h"


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
	static std::vector<RigidSurface_Mystery *> mystery_blocks;

private:

	/*
	* Restarts the game on a victory condition.
	*/
	static void start_victory();

	/*
	* Restarts the game on a loss condition.
	*/
	static void start_loss();

	/*
	* Restarts the game.
	*/
	static void start_again();

	/*
	* Creates all the blocks for the game.
	*/
	static void createLevelBlocks();

	/*
	* Resets the coins in the mystery blocks for restarting.
	*/
	static void reset_mystery_blocks();

	/*
	* Moves the camera with the player.
	*/
	static void handleCamera();

	/*
	* Creates the floor tiles for the game.
	*/
	static void createFloor();

	/*
	* Handles collisions with surfaces and blocks.
	*/
	static void handleSurfaces();

	/*
	* Initializes an object in the game and adds it to the object manager.
	*/
	static void initObject(VisibleGameObject * object, sf::Vector2f position, std::string name);

	/*
	* Finds all rigid bodies in the game and makes a vector of their coordinates.
	*/
	static std::vector<VisibleGameObject *> findRigidBodies();

	/*
	* Handles exiting when gameState is Exiting.
	*/
	static bool isExiting();

	/*
	* Handles the game in different states while constantly looping to poll for changes.
	*/
	static void gameLoop();

	/*
	* Shows the splash screen on the main window.
	*/
	static void showSplashScreen(std::string file);

	/*
	* Shows the main menu on the main window. Changes _gameState based on button pressed.
	*/
	static void showMenu();

	/*
	* Returns a bool indicating whether there is a victory condition or not.
	*/
	static bool isVictory();

	/*
	* Handles any movement on a rigid surface.
	*/
	static void handleSurfaceMovement();

	/*
	* Updates coins and lives if a player hits a mystery block.
	*/
	static void updatePlayerCoins(RigidSurface_Mystery * block);

	/*
	* Handles any updates necessary if a player hits a mystery block.
	*/
	static void handleHitBlock(RigidSurface_Mystery * block);

	/*
	* Displays the coin animation upon hitting the block.
	*/
	static void displayCoins();

	/*
	* Check if the player has touched the flagpole.
	*/
	static void checkVictory();

	/*
	* Denotes the current game state.
	*/
	enum GameState {
		Uninitialized, ShowingSplash, ShowingSplashVictory, ShowingSplashLoss, Paused,
		ShowingMenu, Playing, Exiting, Restart, Victory, Loss
	};

	static GameState _gameState; //The current game state
	static sf::RenderWindow _mainWindow; //The window the game is being displayed on
	static GameObjectManager _gameObjectManager; //The memory manager for all game objects
	static sf::View _view; //The current camera being used
	static float level_width; //The width of the entire level
	static float level_height; //The height of the entire level
	static bool game_victory; //A bool indicating whether the player has a victory condition or not
	static int coin_animation_frames; //The number of frames a coin will display before disappearing.
	static bool display_coin; //A bool indicating whether a coin should be displayed or hidden.
};
