#include "../Public/MainMenuScene.h"

MainMenuScene::MainMenuScene() : test(AudioComponentSettings("Assets/SFX/don.ogg", false, 100, 0, 1))
{
    input_component  = new InputComponent();
    sine_wave = SineWaveGenerator(10);
    bpm_test = BPMSignalComponent();

}

void MainMenuScene::InitScene()
{
    SceneName = "Main Menu ";
    SetupMenuGFX();
    SetupInput();
    SetupMusic();

}

void MainMenuScene::StartTransition()
{
    // FadeOut = new FadeTransition(false, 3, false);
}

void MainMenuScene::SetupMusic()
{
    if (!TitleMusic.openFromFile("Assets/MainMenu/Title.ogg"))
    {

    }
    TitleMusic.play();
    TitleMusic.setLoop(true);
    TitleMusic.setVolume(0);
}

void MainMenuScene::SetupMenuGFX()
{
    
    sf::Vector2f targetSize(window_ref->getView().getSize().x, window_ref->getView().getSize().y);
    background_sprite_comp = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/MainMenu/Background.png");
    background_sprite_comp->GetSpriteTexture()->setSmooth(true);
    entry_bar_sprite = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/MainMenu/Entry_Bar.png");
    entry_bar_sprite->GetSpriteRef_ptr()->setScale(1, 1);
    sf::FloatRect SpriteBound = background_sprite_comp->GetSpriteRef().getLocalBounds();
    background_sprite_comp->GetSpriteRef_ptr()->setScale(targetSize.x / SpriteBound.width, targetSize.y / SpriteBound.height);
    //----------------
    fade_component = new FadeComponent(false, 3, true);
    fade_component->Fade();

    sine_wave.StartClock();
}

void MainMenuScene::SetupInput()
{
    input_component = new InputComponent();
    EventHandler::instance().AddToListening(input_component);
}

void MainMenuScene::RenderScene()
{
    window_ref->draw(background_sprite_comp->GetSpriteRef());
    window_ref->draw(entry_bar_sprite->GetSpriteRef());
    window_ref->draw(fade_component->fade_sprite);

    
    float alpha = MathLib::Lerp(0, 255, MathLib::Clamp(sine_wave.GetSineValue()));
    
    entry_bar_sprite->GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, alpha));
    bpm_test.TickBPMComp();
    if(fade_component->is_fading)
    {
        fade_component->UpdateFade();
    }

    Scene::RenderScene();
}

