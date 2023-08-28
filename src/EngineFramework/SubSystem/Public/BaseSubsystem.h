#pragma once
#include <string>
#include <stdio.h>
#include <memory>
#include <iostream>

template<typename T>
class BaseEngineSubSystem {
public:
    static T& instance();

    BaseEngineSubSystem(const BaseEngineSubSystem&) = delete;
    BaseEngineSubSystem& operator= (const BaseEngineSubSystem) = delete;
    

protected:
    struct token {};
    BaseEngineSubSystem() {}
};



template<typename T>
T& BaseEngineSubSystem<T>::instance()
{
    static const std::unique_ptr<T> instance{new T{token{}}};
    return *instance;
}