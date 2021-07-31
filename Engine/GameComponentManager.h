#pragma once

#include "GameComponent.h"

#include <memory>
#include <typeindex>
#include <unordered_map>

class GameComponentManager
{
public:
	friend class GameComponent;

	template<class GAME_COMPONENT, class... Args>  //Type is child of GameComponent
	GAME_COMPONENT & add_component(Args&& ... args)
	{
		GameComponentIdentifier id = counter++;
		std::pair pair = reinterpret_cast<Container<GAME_COMPONENT>*>(m_components[std::type_index(typeid(GAME_COMPONENT))].get())->try_emplace(id, id, args...);
		auto & game_component = (*pair.first).second;
		m_components_functionality.emplace(game_component.get_functionality_identifier(), std::type_index(typeid(GAME_COMPONENT)));
		return game_component;
	}

	template<class GAME_COMPONENT> //Type is child of GameComponent
	const std::unordered_map<GameComponentIdentifier, GAME_COMPONENT> & get_components_by_type()
	{
		return *(reinterpret_cast<Container<GAME_COMPONENT>*>(m_components[std::type_index(typeid(GAME_COMPONENT))].get()));
	}

	template<class GAME_COMPONENT> //Type is child of GameComponent
	const std::unordered_map<GameComponentIdentifier, GAME_COMPONENT>& get_components_by_type(const std::type_index & type_index)
	{
		return *(reinterpret_cast<Container<GAME_COMPONENT>*>(m_components[type_index].get()));
	}

	const std::unordered_map<GameComponentFunctionalityIdentifier, std::type_index> & get_components_functionality()
	{
		return m_components_functionality;
	}

private:
	class IContainer
	{
	};

	template<class TYPE> //Type is child of GameComponent
	class Container : public std::unordered_map<GameComponentIdentifier, TYPE>, public IContainer
	{
	};

	/* 
	 * GameComponent storage
	 * stores GameComponents in separated storages by type to effectivly iterate over GameComponents with the same type
	 */
	std::unordered_map<std::type_index, std::unique_ptr<IContainer>> m_components;

	/*
	 * GameComponent by functionality storage
	 */
	std::unordered_map<GameComponentFunctionalityIdentifier, std::type_index> m_components_functionality;
};

static GameComponentManager g_game_component_manager;