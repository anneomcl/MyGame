#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string name, VisibleGameObject * obj);
	void remove(std::string name);
	int getObjectCount() const;
	VisibleGameObject * get(std::string name) const;
	std::vector<VisibleGameObject *> getByType(const char * type) const;

	void drawAll(sf::RenderWindow &renderWindow);
	void updateAll();

	std::map<std::string, VisibleGameObject *> _gameObjects;

private:
	sf::Clock clock;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject *> &p) const
		{
			delete p.second;
		}
	};

};