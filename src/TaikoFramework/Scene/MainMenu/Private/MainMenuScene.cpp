#include "../Public/MainMenuScene.h"

MainMenuScene::MainMenuScene() : test(AudioComponentSettings("Assets/SFX/don.ogg", false, 100, 0, 1))
{
    input_component  = new InputComponent();
    sine_wave = SineWaveGenerator(10);
    bpm_test = BPMSignalComponent();
    test_note = new TaikoNote(note_type::ka);
    hit_placement = new TaikoNote(note_type::hit);
    test_note->animated_textured_sprite_comp->SetSpriteOriginToCenter();
    test_note->animated_textured_sprite_comp->GetSpriteRef_ptr()->setPosition(window_ref->getView().getSize().x / 2, window_ref->getView().getSize().y / 2);

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
    background_sprite_comp = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/MainMenu/Background_grid.png");
    background_sprite_comp->GetSpriteTexture()->setSmooth(true);
    entry_bar_sprite = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/MainMenu/Entry_Bar.png");
    entry_bar_sprite->GetSpriteRef_ptr()->setScale(1, 1);
    animated_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    sf::FloatRect SpriteBound = background_sprite_comp->GetSpriteRef().getLocalBounds();
    background_sprite_comp->GetSpriteRef_ptr()->setScale(targetSize.x / SpriteBound.width, targetSize.y / SpriteBound.height);
    //----------------
    fade_component = new FadeComponent(false, 3, true);
    fade_component->Fade();
    animated_sprite_comp->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(130, 0, 130, 130));

    bpm_test.add_bpm_actor_listener(test_note);
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
    window_ref->draw(test_note->animated_textured_sprite_comp->GetSpriteRef());
    //window_ref->draw(hit_placement->animated_textured_sprite_comp->GetSpriteRef());

    
    float alpha = MathLib::Lerp(0, 255, MathLib::Clamp(sine_wave.GetSineValue()));
    
    entry_bar_sprite->GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, alpha));
    bpm_test.TickBPMComp();
    if(fade_component->is_fading)
    {
        fade_component->UpdateFade();
    }

    Scene::RenderScene();
}

