#pragma once

#include "GameComponent.h"
#include "GameComponentIdentifier.h"
#include "GameObjectIdentifier.h"

#include <vector>

class GameObject
{
public:
	void attach_component(const GameComponent & component);

	GameObjectIdentifier get_id()
	{
		return m_id;
	}

private:
	GameObjectIdentifier m_id;

	std::vector<GameComponentIdentifier> m_components;
};