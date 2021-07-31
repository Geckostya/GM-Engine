// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

#include "GameComponent.h"
#include "GameComponentManager.h"
#include "GameObject.h"
#include "GameSystem.h"

#include <iostream>

GameComponentFunctionalityIdentifier id = 0;

class TestGameComponent : public GameComponent
{
public:
    TestGameComponent(
        GameComponentIdentifier id,
        GameObjectIdentifier game_object_id,
        GameComponentFunctionalityIdentifier functionality_id,
        int i, int j, int k)
        : GameComponent(id, game_object_id, functionality_id)
    {}
};

class TestGameComponent2 : public GameComponent
{
public:
    TestGameComponent2(
        GameComponentIdentifier id,
        GameObjectIdentifier game_object_id,
        GameComponentFunctionalityIdentifier functionality_id,
        int i)
        : GameComponent(id, game_object_id, functionality_id)
    {}
};

class TestGameComponent3 : public GameComponent
{
public:
    TestGameComponent3(
        GameComponentIdentifier id,
        GameObjectIdentifier game_object_id,
        GameComponentFunctionalityIdentifier functionality_id)
        : GameComponent(id, game_object_id, functionality_id)
    {}
};

class TestGameObject : public GameObject
{
public:
    TestGameObject()
    {
        attach_component(g_game_component_manager.add_component<TestGameComponent>(get_id(), id, 1, 1, 1));
        attach_component(g_game_component_manager.add_component<TestGameComponent2>(get_id(), id, 1));
        attach_component(g_game_component_manager.add_component<TestGameComponent3>(get_id(), id));
    }
};

class TestGameSystem : public GameSystem
{
public:
    TestGameSystem()
    {
        auto & map = g_game_component_manager.get_components_functionality();
        auto it = map.find(0);
        for (auto& [id, component] : g_game_component_manager.get_components_by_type<TestGameComponent3>(it->second)) {
            std::cout << component.get_id();
        }
    }
};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    TestGameObject game_object;
    TestGameSystem game_system;
    //GameObject game_object;
    //game_object.attach_component(g_game_component_manager.add_component<GameComponent>(game_object.get_id(), id));

    return TRUE;
}

