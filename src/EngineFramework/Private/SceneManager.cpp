#include "../Public/SceneManager.h"

//Init Singleton
SceneManagerSubSystem* SceneManagerSubSystem::m_instance = nullptr;

SceneManagerSubSystem* SceneManagerSubSystem::GetInstance()
{
    if(!m_instance)
    {
        m_instance = new SceneManagerSubSystem();
    }

    return m_instance;
}

void SceneManagerSubSystem::Destroy()
{
    delete m_instance;
    m_instance = 0;
}

Scene* SceneManagerSubSystem::GetActiveScene()
{
    return CurrentActiveScene;
}

bool SceneManagerSubSystem::SetActiveScene(Scene* NewActiveScene)
{
    if(NewActiveScene)
    {
        CurrentActiveScene = NewActiveScene;
        return true;
    }

    return false;
}

SceneManagerSubSystem::SceneManagerSubSystem(){}

SceneManagerSubSystem::~SceneManagerSubSystem(){}