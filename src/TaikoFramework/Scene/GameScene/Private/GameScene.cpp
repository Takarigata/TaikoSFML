#include "../Public/GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::InitScene()
{
    sprite_debug = new SpritePosDebug();
    DebugManager::instance().add_debug_window(sprite_debug);
    printf("INIT SCENE \n");
    player_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/1P_Background.png", "1P_Background");
    player_background->SetSpriteOriginToCenter();
    player_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.13f, 0.38f));

    player_frame = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Tower_Frame.png", "Tower_Frame");
    player_frame->SetSpriteOriginToCenter();
    player_frame->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.63f, 0.347f));

    player_lane_sub_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Lane/Background_Sub.png", "1P Player Lane Sub Background");
    player_lane_sub_background->SetSpriteOriginToCenter();
    player_lane_sub_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.63f, 0.472f));

    player_lane_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Lane/Background_Main.png", "1P Player Lane Background");
    player_lane_background->SetSpriteOriginToCenter();
    player_lane_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.63f, 0.36f));

    game_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Background/Down.png", "Down");
    game_background->SetSpriteOriginToCenter();
    game_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.5f, 0.72f));
    sf::Vector2f out_position = SFMLTransformLib::CalculateScreenPos(0.5f, 0.72f);
    game_background->GetSpriteRef_ptr()->setPosition(out_position);

    header_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Background/0/1P_Up_Clear.png", "Header Background");
    header_background->SetSpriteOriginToCenter();
    header_background->GetSpriteTexture()->setRepeated(true);
    header_background->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(0,0, 1920,1080));
    header_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.128f, 0.129f));

    footer_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Background/Footer.png", "Footer");
    footer_background->SetSpriteOriginToCenter();
    footer_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.5f, 0.97f));


    drum_base = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Base.png", "Base");
    drum_base->SetSpriteOriginToCenter();
    drum_base->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));

    don_sprite = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Don.png", "Don");
    don_sprite->SetSpriteOriginToCenter();
    don_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));
    don_sprite->GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, 0));

    ka_sprite = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Ka.png", "Ka");
    ka_sprite->SetSpriteOriginToCenter();
    ka_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));
    ka_sprite->GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, 0));

    //BACKGROUND SPRITE
    background_layer.push_back(header_background->GetSpriteRef_ptr());
    background_layer.push_back(player_background->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_background->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_sub_background->GetSpriteRef_ptr());
    background_layer.push_back(player_frame->GetSpriteRef_ptr());
    background_layer.push_back(game_background->GetSpriteRef_ptr());
    background_layer.push_back(footer_background->GetSpriteRef_ptr());

    //GAME SPRITE
    game_layer.push_back(drum_base->GetSpriteRef_ptr());
    game_layer.push_back(don_sprite->GetSpriteRef_ptr());
    game_layer.push_back(ka_sprite->GetSpriteRef_ptr());

    sprite_debug->debug_sprite_list.push_back(player_background);
    sprite_debug->debug_sprite_list.push_back(player_frame);
    sprite_debug->debug_sprite_list.push_back(game_background);
    sprite_debug->debug_sprite_list.push_back(footer_background);
    sprite_debug->debug_sprite_list.push_back(player_lane_background);
    sprite_debug->debug_sprite_list.push_back(player_lane_sub_background);
    sprite_debug->debug_sprite_list.push_back(header_background);
    sprite_debug->debug_sprite_list.push_back(drum_base);
    sprite_debug->debug_sprite_list.push_back(don_sprite);
    sprite_debug->debug_sprite_list.push_back(ka_sprite);
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