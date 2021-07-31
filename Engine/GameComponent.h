#pragma once

#include "GameComponentIdentifier.h"
#include "GameObjectIdentifier.h"

// class GameComponentManager;

class GameComponent
{
public:
	// friend class GameComponentManager;

	/* Access only from GameComponentManager */
	GameComponent(GameComponentIdentifier id, GameObjectIdentifier game_object_id, GameComponentFunctionalityIdentifier functionality_id);

	GameComponentIdentifier get_id()
	{
		return m_id;
	}

	GameComponentIdentifier get_id() const
	{
		return m_id;
	}

	GameComponentFunctionalityIdentifier get_functionality_identifier()
	{
		return m_functionality_identifier;
	}
	
	GameComponentFunctionalityIdentifier get_functionality_identifier() const
	{
		return m_functionality_identifier;
	}

private:
	/* Unique identifier of game component */
	GameComponentIdentifier m_id;

	GameObjectIdentifier m_parent_game_object_id;

	/*
	 * Unique identifier of game component functionality
	 * This identifier will be used by systems to iterate over game components
	 *
	 * For example, mesh component should have one identifier,
	 * sphere mesh component should have the same identifer,
	 * but physics component should have another identifier
	 */
	GameComponentFunctionalityIdentifier m_functionality_identifier;
};

static GameComponentIdentifier counter = 0;