#include "../Public/MainMenuScene.h"


void MainMenuScene::InitScene()
{

    SceneName = "Main Menu ";

    SetupMenuGFX();
    

}

void MainMenuScene::StartTransition()
{
    FadeTransition Test = FadeTransition(true, 10);
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
    BackgroundSprite.setScale(targetSize.x / BackgroundSprite.getLocalBounds().width, targetSize.y / BackgroundSprite.getLocalBounds().height);
    FadeBox = sf::RectangleShape();
    FadeBox.setSize(sf::Vector2f(120, 50));
    FadeBox.setFillColor(sf::Color::Black);

    FadeBox.setScale(targetSize.x / FadeBox.getLocalBounds().width, targetSize.y / FadeBox.getLocalBounds().height);
    
    // sf::Thread thread(&MainMenuScene::StartTransition, this);
    // thread.launch();
    // StartTransition();
}

void MainMenuScene::RenderScene()
{
    window_ref->draw(BackgroundSprite);
    //window_ref->draw(FadeBox);
    
    Scene::RenderScene();
    //printf("ELAPSED TIME = %f \n", clock.getElapsedTime().asSeconds());

    
    //printf("Lerp  = %f \n", MathLib::Lerp(1, 0 , clock.getElapsedTime().asSeconds()));
    //printf("Map Range = %f \n", MathLib::MapRangeClamp(clock.getElapsedTime().asSeconds(), 10, 20, 23.5f, 250));
    //FadeBox.setFillColor(sf::Color(0, 0, 0, MathLib::Lerp(255, 0 , clock.getElapsedTime().asSeconds())));
}