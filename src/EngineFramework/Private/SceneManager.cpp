#include "../Public/SceneManager.h"

//Init Singleton
SceneManagerSubSystem* SceneManagerSubSystem::m_instance = nullptr;

Scene* SceneManagerSubSystem::GetActiveScene()
{
    return CurrentActiveScene;
}

bool SceneManagerSubSystem::SetActiveScene(Scene* NewActiveScene)
{
    if(NewActiveScene)
    {
        CurrentActiveScene = NewActiveScene;
        printf("Active Scene = %s", CurrentActiveScene->SceneName.c_str());
        return true;
    }

    return false;
}

SceneManagerSubSystem::SceneManagerSubSystem(){}

SceneManagerSubSystem::~SceneManagerSubSystem(){}