#include "../Public/GameScene.h"

GameScene::GameScene()
{
    InitScene();
}

GameScene::~GameScene()
{

}

void GameScene::InitScene()
{
    player_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/1P_Background.png");
    player_background->SetSpriteOriginToCenter();
    player_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.13f, 0.38f));

    player_frame = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Tower_Frame.png");
    player_frame->SetSpriteOriginToCenter();
    player_frame->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.62f, 0.38f));

    game_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Background/Down.png");
    game_background->SetSpriteOriginToCenter();
    game_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.5f, 0.72f));

    footer_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Background/Footer.png");
    footer_background->SetSpriteOriginToCenter();
    footer_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.5f, 0.97f));


    drum_base = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Base.png");

    don_sprite = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Don.png");

    ka_sprite = new TexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Ka.png");

    background_layer.push_back(player_background->GetSpriteRef());
    background_layer.push_back(player_frame->GetSpriteRef());
    background_layer.push_back(game_background->GetSpriteRef());
    background_layer.push_back(footer_background->GetSpriteRef());
    // obj_to_render.push_back(player_background->GetSpriteRef());
    // obj_to_render.push_back(player_frame->GetSpriteRef());
    // obj_to_render.push_back(don_sprite->GetSpriteRef());
    // obj_to_render.push_back(ka_sprite->GetSpriteRef());
}

void GameScene::RenderScene()
{
    sf::RectangleShape rect_shape(sf::Vector2f(5000, 5000));
    rect_shape.setFillColor(sf::Color::White);
    window_ref->draw(rect_shape);
    Scene::RenderScene();
}

void GameScene::SetupGFX()
{

}