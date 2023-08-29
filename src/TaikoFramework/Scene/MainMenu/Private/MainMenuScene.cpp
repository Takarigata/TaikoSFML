#include "../Public/MainMenuScene.h"

MainMenuScene::MainMenuScene() : test(AudioComponentSettings("Assets/SFX/don.ogg", false, 100, 0, 1))
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
    // FadeOut = new FadeTransition(false, 3, false);
}

void MainMenuScene::SetupMenuGFX()
{
    if(!BackgroundImage.loadFromFile("Assets/MainMenu/Background.png"))
    {

    }
    if(!testimage.loadFromFile("Assets/MainMenu/Entry_Bar.png"))
    {

    }
    if (!TitleMusic.openFromFile("Assets/MainMenu/Title.ogg"))
    {

    }
    TitleMusic.play();
    TitleMusic.setLoop(true);
    TitleMusic.setVolume(0);
    sf::RenderStates renderstate;
    testsprite = sf::Sprite();
    testsprite.setTexture(testimage);
    BackgroundSprite = sf::Sprite();
    BackgroundImage.setSmooth(true);
    BackgroundSprite.setTexture(BackgroundImage);
    sf::Vector2f targetSize(window_ref->getView().getSize().x, window_ref->getView().getSize().y);
    MySpriteComp = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/MainMenu/Entry_Bar.png");
    MySpriteComp->GetSpriteRef().setScale(2.0f, 2.0f);
    MySpriteComp->SetSpriteScale(sf::Vector2f(2, 2));
    
    printf("SETUP SCENE \n");
    SetupInput();
    BackgroundSprite.setScale(targetSize.x / BackgroundSprite.getLocalBounds().width, targetSize.y / BackgroundSprite.getLocalBounds().height);
    testsprite.setScale(targetSize.x / testsprite.getLocalBounds().width, targetSize.y / testsprite.getLocalBounds().height);
}

void MainMenuScene::SetupInput()
{
    input_component = new InputComponent();
    EventHandler::instance().AddToListening(input_component);
}

void MainMenuScene::RenderScene()
{
    window_ref->draw(BackgroundSprite);
    window_ref->draw(MySpriteComp->GetSpriteRef());

    Scene::RenderScene();
}

