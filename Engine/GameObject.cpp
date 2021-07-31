#include "pch.h"
#include "GameObject.h"

void GameObject::attach_component(const GameComponent& component)
{
	m_components.push_back(component.get_id());
}
