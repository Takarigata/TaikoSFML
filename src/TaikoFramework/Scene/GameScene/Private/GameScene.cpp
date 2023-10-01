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

    note_start_pos = SFMLTransformLib::CalculateScreenPos(1, 0.360f);
    note_end_pos = SFMLTransformLib::CalculateScreenPos(0.305f, 0.360f);

    font = new sf::Font();
    font->loadFromFile("Assets/Fonts/DFPKanteiryu-XB.ttf");
    player_name = new sf::Text();
    player_name->setFont(*font);
    player_name->setString(L"チャロッテさん");
    player_name->setCharacterSize(30);
    player_name->setStyle(sf::Text::Bold);
    player_name->setOutlineColor(sf::Color::Black);
    player_name->setOutlineThickness(5);
    player_name->setFillColor(sf::Color::White);
    player_name->setPosition(SFMLTransformLib::CalculateScreenPos(0.020f, 0.275f));

    taiko_char = new BaseTaikoCharacter();

    player_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/1P_Background.png", "1P_Background");
    player_background->SetSpriteOriginToCenter();
    player_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.13f, 0.38f));

    note_hit = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Notes.png", "NoteHit");
    note_hit->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(0, 0, 130, 130));
    note_hit->SetSpriteOriginToCenter();
    note_hit->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.305f, 0.360f));

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


    drum_base = new DrumPart(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Base.png", "Base");
    drum_base->SetSpriteOriginToCenter();
    drum_base->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));

    left_don_sprite = new DrumPart(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Don.png", "LeftDon");
    left_don_sprite->SetSpriteOriginToCenter();
    left_don_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));
    left_don_sprite->setup_drum(true);

    right_don_sprite = new DrumPart(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Don.png", "RightDon");
    right_don_sprite->SetSpriteOriginToCenter();
    right_don_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.252f, 0.375f));
    right_don_sprite->setup_drum(false);

    left_ka_sprite = new DrumPart(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Ka.png", "LeftKa");
    left_ka_sprite->SetSpriteOriginToCenter();
    left_ka_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.375f));
    left_ka_sprite->setup_drum(true);

    right_ka_sprite = new DrumPart(sf::Vector2f(1.5f, 1.5f), "Assets/Game/Ka.png", "RightKa");
    right_ka_sprite->SetSpriteOriginToCenter();
    right_ka_sprite->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.252f, 0.375f));
    right_ka_sprite->setup_drum(false);
    //BACKGROUND SPRITE
    background_layer.push_back(header_background->GetSpriteRef_ptr());
    background_layer.push_back(player_background->GetSpriteRef_ptr());
    background_layer.push_back(taiko_char->taiko_sprite_comp->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_background->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_sub_background->GetSpriteRef_ptr());
    background_layer.push_back(player_frame->GetSpriteRef_ptr());
    background_layer.push_back(game_background->GetSpriteRef_ptr());
    background_layer.push_back(footer_background->GetSpriteRef_ptr());

    //GAME SPRITE
    game_layer.push_back(drum_base->GetSpriteRef_ptr());
    game_layer.push_back(left_don_sprite->GetSpriteRef_ptr());
    game_layer.push_back(left_ka_sprite->GetSpriteRef_ptr());
    game_layer.push_back(right_don_sprite->GetSpriteRef_ptr());
    game_layer.push_back(right_ka_sprite->GetSpriteRef_ptr());
    game_layer.push_back(note_hit->GetSpriteRef_ptr());


    sprite_debug->debug_sprite_list.push_back(taiko_char->taiko_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(player_background);
    sprite_debug->debug_sprite_list.push_back(player_frame);
    sprite_debug->debug_sprite_list.push_back(game_background);
    sprite_debug->debug_sprite_list.push_back(footer_background);
    sprite_debug->debug_sprite_list.push_back(player_lane_background);
    sprite_debug->debug_sprite_list.push_back(player_lane_sub_background);
    sprite_debug->debug_sprite_list.push_back(header_background);
    sprite_debug->debug_sprite_list.push_back(drum_base);
    sprite_debug->debug_sprite_list.push_back(left_don_sprite);
    sprite_debug->debug_sprite_list.push_back(left_ka_sprite);
    sprite_debug->debug_sprite_list.push_back(right_don_sprite);
    sprite_debug->debug_sprite_list.push_back(right_ka_sprite);
    sprite_debug->debug_sprite_list.push_back(note_hit);


    InitTJAPlayer();
}

void GameScene::RenderScene()
{
    bpm_comp.TickBPMComp();
    // if(test_note)
    // {
    //     //test_note->bpm_tick(0);
    //     test_note->tick(0);
    // }

    left_don_sprite->tick(0);
    left_ka_sprite->tick(0);
    right_don_sprite->tick(0);
    right_ka_sprite->tick(0);
    taiko_char->tick(0);
    for (auto note : note_on_screen)
    {
        if(note != nullptr)
            note->tick(0);
    }
    sf::RectangleShape rect_shape(sf::Vector2f(5000, 5000));
    rect_shape.setFillColor(sf::Color::White);
    window_ref->draw(rect_shape);
    Scene::RenderScene();
    window_ref->draw(*player_name);
    ParseNote();
}

void GameScene::SetupGFX()
{

}

void GameScene::InitTJAPlayer()
{
    AudioComponentSettings Settings = AudioComponentSettings("E:\\DEV\\TJADB\\ESE\\01 Pop\\Zen Zen Zense\\Zen Zen Zense.ogg", false, 15, 0, 1);
    // AudioComponentSettings Settings = AudioComponentSettings("E:\\DEV\\TJADB\\ESE\\01 Pop\\oddloop\\oddloop.ogg", false, 10, 0, 1);
    music_player = new AudioComponent(Settings);
    music_player->PlaySound();
    
    AudioComponentSettings SettingsDebugHitKa = AudioComponentSettings("Assets\\SFX\\ka.ogg", false, 25, 0, 1);
    debug_hit_ka = new AudioComponent(SettingsDebugHitKa);

    AudioComponentSettings SettingsDebugHitDon = AudioComponentSettings("Assets\\SFX\\don.ogg", false, 25, 0, 1);
    debug_hit_don = new AudioComponent(SettingsDebugHitDon);
    tja_clock = sf::Clock();

    bpm_comp = BPMSignalComponent(TJAParser::instance().DebugMap->bpm);
    

}


void GameScene::ParseNote()
{
    int current_time = tja_clock.getElapsedTime().asMilliseconds() - 240;

    if(current_time > 0 && !is_playing)
    {
        
        is_playing = true;
    }
    // int current_time = tja_clock.getElapsedTime().asMilliseconds() + 0;
    //printf("current time = %d \n ", current_time);
    //AUTO PLAY
    if(current_note < TJAParser::instance().DebugMap->current_note_vector.size())
    {
        if(current_time >= (int) TJAParser::instance().DebugMap->current_note_vector[current_note].note_time)
        {
            
            printf("HIT NOTE NO = %d CURRENT TIME = %d, Current NOTE TIME = %d \n",   TJAParser::instance().DebugMap->current_note_vector[current_note].note_count, current_time, (int) TJAParser::instance().DebugMap->current_note_vector[current_note].note_time);
            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::ka || TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::big_ka)
            {
                debug_hit_ka->PlaySound();
                left_ka_sprite->DrumPressed();
            }

            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::don || TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::big_don)
            {
                debug_hit_don->PlaySound();
                right_don_sprite->DrumPressed();
            }
            current_note++;
        }
    }

    if(current_spawned_note < TJAParser::instance().DebugMap->current_note_vector.size())
    {
        float scrollspeed = 1.0f;
        float current_note_time = (int) TJAParser::instance().DebugMap->current_note_vector[current_spawned_note].note_time - (1000 * scrollspeed);
        if(current_time >= current_note_time)
        {
            //printf("HIT NOTE NO = %d CURRENT TIME = %d, Current NOTE TIME = %d \n",   TJAParser::instance().DebugMap->current_note_vector[current_spawned_note].note_count, current_time, (int) current_note_time);
            TaikoNote* Tmp_Note = new TaikoNote(TJAParser::instance().DebugMap->current_note_vector[current_spawned_note].current_note_type, note_start_pos,  note_end_pos, 1 * scrollspeed);
            note_on_screen.push_back(Tmp_Note);
            game_layer.push_back(Tmp_Note->animated_textured_sprite_comp->GetSpriteRef_ptr());
            bpm_comp.add_bpm_actor_listener(Tmp_Note);
            current_spawned_note++;
        }
    }
}