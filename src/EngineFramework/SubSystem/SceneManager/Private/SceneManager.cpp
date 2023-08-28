#include "../Public/SceneManager.h"


Scene* SceneManager::GetActiveScene()
{
    return CurrentActiveScene;
}


bool SceneManager::SetActiveScene(Scene* NewActiveScene)
{
    if(NewActiveScene)
    {
        CurrentActiveScene = NewActiveScene;
        printf("Active Scene = %s \n", CurrentActiveScene->SceneName.c_str());
        return true;
    }

    return false;
}