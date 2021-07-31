// Engine.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "Engine.h"


// Пример экспортированной переменной
ENGINE_API int nEngine=0;

// Пример экспортированной функции.
ENGINE_API int fnEngine(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CEngine::CEngine()
{
    return;
}
