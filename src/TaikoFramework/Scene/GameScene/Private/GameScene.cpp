#include "../Public/GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::InitScene()
{
    
    InitSceneComp();
    InitTJAPlayer();

}


void GameScene::RenderScene()
{
    bpm_comp.TickBPMComp();
    left_don_sprite->tick(0);
    left_ka_sprite->tick(0);
    right_don_sprite->tick(0);
    right_ka_sprite->tick(0);
    taiko_char->tick(0);
    dancer_char->tick(0);
    dancer_char_2->tick(0);
    dancer_char_3->tick(0);
    puchi_char->tick(0);
    for (auto note : note_on_screen)
    {
        if(note != nullptr)
            note->tick(0);
    }
    Scene::RenderScene();
    //WIP NO ENCAPSULATION FOR sfml::Text
    window_ref->draw(*player_name);
    window_ref->draw(*combo_count_text);
    window_ref->draw(*combo_static_text);
    window_ref->draw(*song_name);
    ParseNote();
}

void GameScene::InitSceneComp()
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

    combo_count_text = new sf::Text();
    combo_count_text->setFont(*font);
    combo_count_text->setString(L"0");
    combo_count_text->setCharacterSize(50);
    combo_count_text->setStyle(sf::Text::Bold);
    combo_count_text->setOutlineColor(sf::Color::Black);
    combo_count_text->setOutlineThickness(5);
    combo_count_text->setFillColor(sf::Color::White);
    sf::FloatRect textRect = combo_count_text->getLocalBounds();
    combo_count_text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    combo_count_text->setPosition(SFMLTransformLib::CalculateScreenPos(0.205f, 0.34f));

    song_name = new sf::Text();
    song_name->setFont(*font);
    song_name->setString(TJAParser::instance().DebugMap->map_title.c_str());
    song_name->setCharacterSize(30);
    song_name->setStyle(sf::Text::Bold);
    song_name->setOutlineColor(sf::Color::Black);
    song_name->setOutlineThickness(5);
    song_name->setFillColor(sf::Color::White);
    song_name->setPosition(SFMLTransformLib::CalculateScreenPos(0.830f, 0.030f));

    combo_static_text = new sf::Text();
    combo_static_text->setFont(*font);
    combo_static_text->setString(L"combo");
    combo_static_text->setCharacterSize(17);
    combo_static_text->setStyle(sf::Text::Bold);
    combo_static_text->setOutlineColor(sf::Color::Black);
    combo_static_text->setOutlineThickness(2);
    combo_static_text->setFillColor(sf::Color::White);
    combo_static_text->setPosition(SFMLTransformLib::CalculateScreenPos(0.190f, 0.38f));

    taiko_char = new BaseTaikoCharacter();
    taiko_char->setup_character(1800, "Assets/Game/Characters/0/Normal/", sf::Vector2f(1.2f, 1.2f));
    taiko_char->taiko_sprite_comp->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(-0.030f, 0.060f));


    dancer_char = new BaseTaikoCharacter();
    dancer_char->setup_character(800, "Assets/5_Game/2_Dancer/1/", sf::Vector2(1.5f, 1.5f), "Dancer");
    dancer_char->taiko_sprite_comp->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.255, 0.430));
    dancer_char->max_sprite = 15;

    dancer_char_2 = new BaseTaikoCharacter();
    dancer_char_2->setup_character(800, "Assets/5_Game/2_Dancer/4/", sf::Vector2(1.5f, 1.5f), "Dancer2");
    dancer_char_2->taiko_sprite_comp->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.770, 0.430));
    dancer_char_2->max_sprite = 15;

    dancer_char_3 = new BaseTaikoCharacter();
    dancer_char_3->setup_character(800, "Assets/5_Game/2_Dancer/5/", sf::Vector2(1.5f, 1.5f), "Dancer3");
    dancer_char_3->taiko_sprite_comp->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.010f, 0.430f));
    dancer_char_3->max_sprite = 15;

    PuchiCharacterSettings puchi_setting = PuchiCharacterSettings();
    puchi_setting.puchi_start_row = 6;
    puchi_setting.puchi_start_collums = 1;
    puchi_setting.puch_scale = sf::Vector2f(.5f, .5f);
    puchi_setting.start_pos = SFMLTransformLib::CalculateScreenPos(0.090f, 0.050f);
    puchi_char = new BasePuchiCharacter();
    puchi_char->setup_character(puchi_setting);

    player_background = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/Game/1P_Background.png", "1P_Background");
    player_background->SetSpriteOriginToCenter();
    player_background->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.13f, 0.38f));

    player_score_frame = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/5_Game/6_Taiko/1P_Frame.png", "Frame");
    player_score_frame->SetSpriteOriginToCenter();
    player_score_frame->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.630f, 0.348f));

    sogn_genre_plate = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/5_Game/13_GENRE/Pops.png", "Song genre");
    sogn_genre_plate->SetSpriteOriginToCenter();
    sogn_genre_plate->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.895f, 0.090f));

    player_gauge_empty = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/5_Game/7_Gauge/1P_Base.png", "1P Gauge Empty");
    player_gauge_empty->SetSpriteOriginToCenter();
    player_gauge_empty->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.660f, 0.248f));

    player_gauge_full = new TexturedSpriteComponent(sf::Vector2f(1.5f, 1.5f), "Assets/5_Game/7_Gauge/1P.png", "1P Gauge");
    player_gauge_full->SetSpriteOriginToCenter();
    player_gauge_full->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.660f, 0.248f));

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

    diff_icon = new TexturedSpriteComponent(sf::Vector2f(1.3f, 1.3f), "Assets/5_Game/4_CourseSymbol/Hard_up.png", "Diff_Badge");
    diff_icon->SetSpriteOriginToCenter();
    diff_icon->GetSpriteRef_ptr()->setPosition(SFMLTransformLib::CalculateScreenPos(0.070f, 0.405f));

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
    background_layer.push_back(diff_icon->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_background->GetSpriteRef_ptr());
    background_layer.push_back(player_lane_sub_background->GetSpriteRef_ptr());
    background_layer.push_back(player_score_frame->GetSpriteRef_ptr());
    background_layer.push_back(player_frame->GetSpriteRef_ptr());
    background_layer.push_back(player_gauge_empty->GetSpriteRef_ptr());
    background_layer.push_back(game_background->GetSpriteRef_ptr());
    background_layer.push_back(footer_background->GetSpriteRef_ptr());
    background_layer.push_back(dancer_char->taiko_sprite_comp->GetSpriteRef_ptr());
    background_layer.push_back(dancer_char_2->taiko_sprite_comp->GetSpriteRef_ptr());
    background_layer.push_back(dancer_char_3->taiko_sprite_comp->GetSpriteRef_ptr());
    background_layer.push_back(puchi_char->puchi_sprite_comp->GetSpriteRef_ptr());
    background_layer.push_back(sogn_genre_plate->GetSpriteRef_ptr());

    //GAME SPRITE
    game_layer.push_back(drum_base->GetSpriteRef_ptr());
    game_layer.push_back(left_don_sprite->GetSpriteRef_ptr());
    game_layer.push_back(left_ka_sprite->GetSpriteRef_ptr());
    game_layer.push_back(right_don_sprite->GetSpriteRef_ptr());
    game_layer.push_back(right_ka_sprite->GetSpriteRef_ptr());
    game_layer.push_back(note_hit->GetSpriteRef_ptr());


    //WIP DEBBUG TOOLS 
    sprite_debug->debug_sprite_list.push_back(taiko_char->taiko_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(dancer_char->taiko_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(dancer_char_2->taiko_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(dancer_char_3->taiko_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(puchi_char->puchi_sprite_comp);
    sprite_debug->debug_sprite_list.push_back(player_background);
    sprite_debug->debug_sprite_list.push_back(diff_icon);
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
    sprite_debug->debug_sprite_list.push_back(sogn_genre_plate);
    sprite_debug->debug_sprite_list.push_back(player_score_frame);
    sprite_debug->debug_sprite_list.push_back(player_gauge_full);
    sprite_debug->debug_sprite_list.push_back(player_gauge_empty);

}

void GameScene::InitTJAPlayer()
{
    AudioComponentSettings Settings = AudioComponentSettings("Songs\\Test\\Zen Zen Zense\\Zen Zen Zense.ogg", false, 65, 0, 1);
    music_player = new AudioComponent(Settings);
    music_player->PlaySound();
    
    AudioComponentSettings SettingsDebugHitKa = AudioComponentSettings("Assets\\SFX\\ka.ogg", false, 60, 0, 1);
    debug_hit_ka = new AudioComponent(SettingsDebugHitKa);

    AudioComponentSettings SettingsDebugHitDon = AudioComponentSettings("Assets\\SFX\\don.ogg", false, 70, 0, 1);
    debug_hit_don = new AudioComponent(SettingsDebugHitDon);
    tja_clock = sf::Clock();

    TJAMap* map = TJAParser::instance().DebugMap;
    bpm_comp = BPMSignalComponent(map->bpm);
    

}


void GameScene::ParseNote()
{
    int current_time = tja_clock.getElapsedTime().asMilliseconds() - 240;

    if(current_note < TJAParser::instance().DebugMap->current_note_vector.size())
    {
        if(current_time >= (int) TJAParser::instance().DebugMap->current_note_vector[current_note].note_time)
        {
            
            printf("HIT NOTE NO = %d CURRENT TIME = %d, Current NOTE TIME = %d \n",   TJAParser::instance().DebugMap->current_note_vector[current_note].note_count, current_time, (int) TJAParser::instance().DebugMap->current_note_vector[current_note].note_time);
            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::ka)
            {
                debug_hit_ka->PlaySound();
                left_ka_sprite->DrumPressed();
            }

            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::big_ka)
            {
                debug_hit_ka->PlaySound();
                left_ka_sprite->DrumPressed();
                right_ka_sprite->DrumPressed();
            }

            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::don)
            {
                debug_hit_don->PlaySound();
                right_don_sprite->DrumPressed();
            }

            if(TJAParser::instance().DebugMap->current_note_vector[current_note].current_note_type == note_type::big_don)
            {
                debug_hit_don->PlaySound();
                right_don_sprite->DrumPressed();
                left_don_sprite->DrumPressed();
            }

            current_note++;
            combo_count_text->setString(std::to_string(current_note));
            sf::FloatRect textRect = combo_count_text->getLocalBounds();
            combo_count_text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        }
    }

    if(current_spawned_note < TJAParser::instance().DebugMap->current_note_vector.size())
    {
        float scrollspeed = 1.0f;
        float current_note_time = (int) TJAParser::instance().DebugMap->current_note_vector[current_spawned_note].note_time - (1000 * scrollspeed);
        if(current_time >= current_note_time)
        {
            TaikoNote* Tmp_Note = new TaikoNote(TJAParser::instance().DebugMap->current_note_vector[current_spawned_note].current_note_type, note_start_pos,  note_end_pos, 1 * scrollspeed);
            note_on_screen.push_back(Tmp_Note);
            game_layer.push_back(Tmp_Note->animated_textured_sprite_comp->GetSpriteRef_ptr());
            bpm_comp.add_bpm_actor_listener(Tmp_Note);
            current_spawned_note++;
        }
    }
}