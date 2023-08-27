#include "../Public/MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
    input_component  = new InputComponent();
}

void MainMenuScene::InitScene()
{

    SceneName = "Main Menu ";

    SetupMenuGFX();
    

}

void MainMenuScene::StartTransition()
{
    FadeOut = new FadeTransition(false, 3, false);
}

void MainMenuScene::SetupMenuGFX()
{
    if(!BackgroundImage.loadFromFile("Assets/MainMenu/Background.png"))
    {

    }
    if (!TitleMusic.openFromFile("Assets/MainMenu/Title.ogg"))
    {

    }
    TitleMusic.play();
    TitleMusic.setLoop(true);
    TitleMusic.setVolume(0);
    sf::RenderStates renderstate;
    BackgroundSprite = sf::Sprite();
    BackgroundSprite.setTexture(BackgroundImage);
    sf::Vector2f targetSize(window_ref->getView().getSize().x, window_ref->getView().getSize().y);
    
    printf("SETUP SCENE \n");
    eh_ref = EventHandler::GetInstance2();
    eh_ref->AddObjectToListenner(input_component);
    BackgroundSprite.setScale(targetSize.x / BackgroundSprite.getLocalBounds().width, targetSize.y / BackgroundSprite.getLocalBounds().height);
    // FadeBox = sf::RectangleShape();
    // FadeBox.setSize(sf::Vector2f(120, 50));
    // FadeBox.setFillColor(sf::Color::Black);

    // FadeBox.setScale(targetSize.x / FadeBox.getLocalBounds().width, targetSize.y / FadeBox.getLocalBounds().height);
    // StartTransition();
}

void MainMenuScene::RenderScene()
{
    window_ref->draw(BackgroundSprite);
    // if(FadeOut)
    // {
    //     if(FadeOut->UpdateTransition())
    //     {
    //         FadeOut = nullptr;
    //     }

    // }
    Scene::RenderScene();
}

