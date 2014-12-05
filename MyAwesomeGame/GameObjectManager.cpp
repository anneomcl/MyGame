#include "GameObjectManager.h"
#include "Game.h"

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	std::for_each(gameObjects.begin(), gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject * obj)
{
	gameObjects.insert(std::pair<std::string, VisibleGameObject *>(name, obj));
}

void GameObjectManager::remove(std::string name)
{
	std::map<std::string, VisibleGameObject *>::iterator results = gameObjects.find(name);
	if (results != gameObjects.end())
	{
		delete results->second;
		gameObjects.erase(results);
	}
}

VisibleGameObject * GameObjectManager::get(std::string name) const
{
	std::map<std::string, VisibleGameObject *>::const_iterator results = gameObjects.find(name);
	if (results == gameObjects.end())
		return NULL;
	return results->second;
}

std::vector<VisibleGameObject *> GameObjectManager::getAllByType(const char * type) const
{
	std::vector<VisibleGameObject *> ret;

	std::map<std::string, VisibleGameObject *>::const_iterator it = gameObjects.begin();
	while (it != gameObjects.end())
	{
		if (std::string(it->second->getType()).find(std::string(type)) == 0)
		{
			ret.push_back(it->second);
		}

		it++;
	}

	return ret;
}

VisibleGameObject * GameObjectManager::getByType(const char * type) const
{
	VisibleGameObject * ret = NULL;

	std::map<std::string, VisibleGameObject *>::const_iterator it = gameObjects.begin();
	while (it != gameObjects.end())
	{
		if (std::string(it->second->getType()).find(std::string(type)) == 0)
		{
			ret = it->second;
		}

		it++;
	}

	return ret;
}

int GameObjectManager::getObjectCount() const
{
	return gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow &renderWindow)
{
	std::map<std::string, VisibleGameObject *>::const_iterator it = gameObjects.begin();
	while (it != gameObjects.end())
	{
		it->second->draw(renderWindow);
		it++;
	}
}

void GameObjectManager::updateAll()
{
	std::map < std::string, VisibleGameObject *>::const_iterator it = gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while (it != gameObjects.end())
	{
		it->second->update(timeDelta);
		it++;
	}
}