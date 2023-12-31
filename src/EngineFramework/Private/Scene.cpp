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
    for(auto actor : tickable_actor)
    {
        //WIP NEED TO IMPLEMENT GLOBAL CLOCK IN SUBSYSTEM AND COMPONENTS TICKS
        actor->tick(0);
    }
    cnt++;
}

void Scene::RenderScene()
{

    //BACKGROUND OBJ
    for(auto background_obj : background_layer)
    {
        if(background_obj != nullptr)
            window_ref->draw(*background_obj);
    }


    //Game OBJ
    for(auto game_obj : game_layer)
    {
        if(game_obj != nullptr)
            window_ref->draw(*game_obj);
    }

    //FOREGROUND OBJ
    for(auto foreground_obj : foreground_layer)
    {
        if(foreground_obj != nullptr)
            window_ref->draw(*foreground_obj);
    }

    //UI OBJ
    for(auto ui_obj : ui_layer)
    {
        if(ui_obj != nullptr)
            window_ref->draw(*ui_obj);
    }
}
