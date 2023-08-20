#pragma once
#include <stdio.h>
#include <iostream>

class BaseEngineSubsystem
{
    
public:
    BaseEngineSubsystem();
    ~BaseEngineSubsystem();

    static BaseEngineSubsystem* GetInstance();
    
    static void Destroy();

    void printSub();

    

    


protected:
    
    static BaseEngineSubsystem* m_instance;
    
    
};

//Init Singleton
inline BaseEngineSubsystem* BaseEngineSubsystem::m_instance = nullptr;


inline BaseEngineSubsystem* BaseEngineSubsystem::GetInstance()
{
    if(!m_instance)
    {
        m_instance = new BaseEngineSubsystem();
    }

    return m_instance;
}

inline void BaseEngineSubsystem::Destroy()
{
    delete m_instance;
    m_instance = 0;
}

inline void BaseEngineSubsystem::printSub()
{
    std::cout << "SUwUbSUwUtemActivated>w<" << std::endl;
}

inline BaseEngineSubsystem::BaseEngineSubsystem()
{}

inline BaseEngineSubsystem::~BaseEngineSubsystem()
{}


