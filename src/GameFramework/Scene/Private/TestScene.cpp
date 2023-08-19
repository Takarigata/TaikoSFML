#include "../Public/TestScene.h"


// TestScene::TestScene() : Scene()
// {
//     printf("sd \n");
// }

void TestScene::InitScene()
{
    SceneName = "Test Scene 2 ";
    font = new sf::Font();
    if(font)
    {
        font->loadFromFile("Assets/Fonts/DFPKanteiryu-XB.ttf");
    }

    auto text = new sf::Text();
    auto renderstate = new sf::RenderStates();
    text->setFont(*font);
    text->setString(L"Scene Test");
    text->setCharacterSize(24);
    text->setStyle(sf::Text::Bold);
    text->setFillColor(sf::Color::Red);

    shape = new sf::CircleShape(50.f);
    shape->setFillColor(sf::Color::Blue);
    ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(text, renderstate));
    ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(shape, renderstate));
    printf("INIT SCENE");
}

void TestScene::UpdateScene()
{
    Scene::UpdateScene();
    //printf("UPDATING SCENE 2  \n");
    sine = std::sin((cnt *.01) *1);
    printf("SIN = %f \n", sine);
    shape->setScale(sine, sine);
    

}

void TestScene::RenderScene()
{
    //printf("RENDERING");
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