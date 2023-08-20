#pragma once
#include "Scene.h"
#include "BaseEngineSubsystem.h"


class SceneManagerSubSystem : public BaseEngineSubsystem
{
    public:

        SceneManagerSubSystem();
        ~SceneManagerSubSystem();

        Scene* GetActiveScene();

        bool SetActiveScene(Scene* NewActiveScene);

        Scene* ActiveTqt;

    protected:

        static SceneManagerSubSystem* m_instance;

        Scene* CurrentActiveScene;
};