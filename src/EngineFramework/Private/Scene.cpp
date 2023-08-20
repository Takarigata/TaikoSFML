#include "../Public/Scene.h"

Scene::Scene()
{
    InitScene();
    window_ref = static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->GetWindowRef();
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
    // std::vector<sf::Drawable> key;
    // std::vector<sf::RenderStates> value;
    // for(std::map<sf::Drawable, sf::RenderStates>::iterator it = ObjectsToDraw.begin(); it != ObjectsToDraw.end(); ++it) {
    //     key.push_back(it->first);
    //     value.push_back(it->second);
    // }
    // for(auto& ObjectToDraw : key)
    // {
    //     if(window_ref)
    //         window_ref->draw(ObjectToDraw, ObjectsToDraw[ObjectToDraw]);
    //     else
    //         printf("NO WINDOW REF \n");
    // }
}