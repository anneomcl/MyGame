#include "GameObjectManager.h"
#include "Game.h"

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject * obj)
{
	_gameObjects.insert(std::pair<std::string, VisibleGameObject *>(name, obj));
}

void GameObjectManager::remove(std::string name)
{
	std::map<std::string, VisibleGameObject *>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject * GameObjectManager::get(std::string name) const
{
	std::map<std::string, VisibleGameObject *>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;
}

std::vector<VisibleGameObject *> GameObjectManager::getByType(const char * type) const
{
	std::vector<VisibleGameObject *> ret;

	std::map<std::string, VisibleGameObject *>::const_iterator it = _gameObjects.begin();
	while (it != _gameObjects.end())
	{
		//if (/*strcmp(it->second->getType(),(type)) == 0*/ 
		if (std::string (it->second->getType()).find(std::string(type)) == 0)
		{
			ret.push_back(it->second);
		}

		it++;
	}
	
	return ret;
}

int GameObjectManager::getObjectCount() const
{
	return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow &renderWindow)
{
	std::map<std::string, VisibleGameObject *>::const_iterator it = _gameObjects.begin();
	while (it != _gameObjects.end())
	{
		it->second->draw(renderWindow);
		it++;
	}
}

void GameObjectManager::updateAll()
{
	std::map < std::string, VisibleGameObject *>::const_iterator it = _gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while (it != _gameObjects.end())
	{
		it->second->update(timeDelta);
		it++;
	}
}