#include "pch.h"
#include "GameComponent.h"
#include "GameComponentManager.h"

GameComponent::GameComponent(GameComponentIdentifier id, GameObjectIdentifier game_object_id, GameComponentFunctionalityIdentifier functionality_id)
	: m_id(id), m_parent_game_object_id(game_object_id), m_functionality_identifier(functionality_id)
{
}
