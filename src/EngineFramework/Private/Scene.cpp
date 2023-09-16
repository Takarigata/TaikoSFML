#include "../Public/Scene.h"

Scene::Scene()
{
    InitScene();
    
    // window_ref = static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->GetWindowRef();
    window_ref = WindowManager::instance().m_window;
}

Scene::~Scene()
{
    CloseScene();

}

void Scene::InitScene()
{
    
}

void Scene::UnloadScene()
{

}

void Scene::CloseScene()
{

}

void Scene::UpdateScene()
{
    //printf("UPDATING SCENE \n");
    cnt++;

}

void Scene::RenderScene()
{
    //printf("RENDER PARENT \n");


    //BACKGROUND OBJ
    for(auto background_obj : background_layer)
    {
        window_ref->draw(*background_obj);
    }


    //Game OBJ
    for(auto game_obj : game_layer)
    {
        window_ref->draw(*game_obj);
    }

    //FOREGROUND OBJ
    for(auto foreground_obj : foreground_layer)
    {
        window_ref->draw(*foreground_obj);
    }

    //UI OBJ
    for(auto ui_obj : ui_layer)
    {
        window_ref->draw(*ui_obj);
    }
}
