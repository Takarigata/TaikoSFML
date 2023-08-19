#include "../Public/Scene.h"

Scene::Scene()
{
    InitScene();
    printf("PARENT \n");
}

Scene::~Scene()
{
    CloseScene();

}

void Scene::InitScene()
{
    // font = new sf::Font();
    // if(font)
    // {
    //     font->loadFromFile("Assets/Fonts/DFPKanteiryu-XB.ttf");
    // }

    // auto text = new sf::Text();
    // auto renderstate = new sf::RenderStates();
    // text->setFont(*font);
    // text->setString(L"Taiko no 太鼓の達人, アニメ, ひらがな base");
    // text->setCharacterSize(35);
    // text->setStyle(sf::Text::Bold);
    // text->setFillColor(sf::Color::Red);

    // shape = new sf::CircleShape(20.f);
    // ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(text, renderstate));
    // ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(shape, renderstate));
}

void Scene::UnloadScene()
{

}

void Scene::CloseScene()
{

}

void Scene::UpdateScene()
{
    printf("UPDATING SCENE \n");
    cnt++;
}

void Scene::RenderScene()
{
    std::vector<sf::Drawable*> key;
    std::vector<sf::RenderStates*> value;
    for(std::map<sf::Drawable*, sf::RenderStates*>::iterator it = ObjectsToDraw.begin(); it != ObjectsToDraw.end(); ++it) {
        key.push_back(it->first);
        value.push_back(it->second);
    }
    for(auto& ObjectToDraw : key)
    {
        if(WindowManagerSubSystem::GetInstance()->GetWindowRef())
            WindowManagerSubSystem::GetInstance()->GetWindowRef()->draw(*ObjectToDraw, *ObjectsToDraw[ObjectToDraw]);
        else
            printf("NO WINDOW REF \n");
    }
}