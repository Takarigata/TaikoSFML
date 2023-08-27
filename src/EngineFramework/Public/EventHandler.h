
#pragma once
#include <vector>
#include "BaseEngineSubsystem.h"
#include "WindowManager.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "../../GameFramework/Input/Public/InputComponent.h"





class GameSFML;
class EventHandler : public BaseEngineSubsystem
{
    public:

        EventHandler();
        ~EventHandler();

        void UpdateInputEvent(GameSFML* InGame);

        bool AddObjectToListenner(InputComponent* ObjToAdd);

        std::vector<InputComponent*> ListenedObject;

        void SendPressed();

        static EventHandler* GetInstance2();

        static EventHandler* m_instance2;

        

    protected:

        




};

inline EventHandler* EventHandler::m_instance2 = nullptr;

inline EventHandler* EventHandler::GetInstance2()
{
    if(!m_instance2)
    {
        m_instance2 = new EventHandler();
    }

    return m_instance2;
}