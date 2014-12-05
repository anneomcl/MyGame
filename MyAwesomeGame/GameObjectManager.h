#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:

	/*
	* Constructor for GameObjectManager
	*/
	GameObjectManager();

	/*
	* Destructor for Game Object Manager
	*/
	~GameObjectManager();

	/*
	* Adds a new object to the manager.
	*/
	void add(std::string name, VisibleGameObject * obj);

	/*
	* Removes an object from the manager.
	*/
	void remove(std::string name);

	/*
	* Gets the total number of objects in the manager.
	*/
	int getObjectCount() const;

	/*
	* Gets an object based on its unique name.
	*/
	VisibleGameObject * get(std::string name) const;

	/*
	* Gets the first object with a certain type.
	* Useful for types with one unique object.
	*/
	VisibleGameObject * getByType(const char * type) const;

	/*
	* Gets all objects of a certain type in a vector.
	*/
	std::vector<VisibleGameObject *> getAllByType(const char * type) const;


	/*
	* Draws all objects in the manager.
	*/
	void drawAll(sf::RenderWindow &renderWindow);

	/*
	* Updates all objects in the manager for each new frame.
	*/
	void updateAll();

	/*
	* The map containing all game objects.
	*/
	std::map<std::string, VisibleGameObject *> gameObjects;

private:

	/*
	* The clock that calculates the time delta for each frame.
	*/
	sf::Clock clock;

	/*
	* The deallocator that frees all memory in the manager when the destructor is called.
	*/
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject *> &p) const
		{
			delete p.second;
		}
	};

};