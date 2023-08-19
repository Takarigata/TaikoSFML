#pragma once
#include "Scene.h"


class SceneManagerSubSystem
{
    public:

        SceneManagerSubSystem();
        ~SceneManagerSubSystem();

        static SceneManagerSubSystem* GetInstance();

        static void Destroy();

        //Scene Getter and Setter

        Scene* GetActiveScene();

        bool SetActiveScene(Scene* NewActiveScene);

    protected:

        static SceneManagerSubSystem* m_instance;

        Scene* CurrentActiveScene;
};