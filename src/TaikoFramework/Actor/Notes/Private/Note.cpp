#include "../Public/Note.h"

TaikoNote::TaikoNote()
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.0f, 1.0f);
    current_note_type = note_type::ka;
}

TaikoNote::TaikoNote(note_type in_note_type, bool debug_window)
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.0f, 1.0f);
    current_note_type = in_note_type;
    debug_imgui = debug_window;
    if(debug_window)
    {
        sf::RenderWindow* test = WindowManager::instance().m_window;
        ImGui::SFML::Init(*test, false);
        ImGuiIO& IO = ImGui::GetIO();
        IO.Fonts->Clear();
        IO.Fonts->AddFontFromFileTTF("Assets/Fonts/DFPKanteiryu-XB.ttf", 8.f, NULL, IO.Fonts->GetGlyphRangesJapanese());

        ImGui::SFML::UpdateFontTexture();
    }
}

void TaikoNote::bpm_tick(float elapsed_time)
{
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    animated_textured_sprite_comp->SetSpriteOriginToCenter();

    // if(mouth_open)
    // {
    //     animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    //     mouth_open = false;
    // }
    // else
    // {
    //     animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    //     mouth_open = true;
    // }
}

void TaikoNote::tick(float elapsed_time)
{
    //597 404
    if(debug_imgui)
    {
        sf::RenderWindow* test = WindowManager::instance().m_window;
        ImGui::SFML::Update(*test, WindowManager::instance()._clock->restart());
        //ImGui::ShowDemoWindow();
       if (ImGui::Begin("Sprite Debug Win"))
       {

            if(ImGui::SliderFloat2("Sprite pos", sprite_pos, 0, 1920))
            {
                printf("VALUE = %f %f \n", sprite_pos[0], sprite_pos[1]);
                animated_textured_sprite_comp->GetSpriteRef_ptr()->setPosition(sf::Vector2(sprite_pos[0], sprite_pos[1]));
            }
            
       }
        
        ImGui::End();
        ImGui::SFML::Render(*test);
    }
    
}

sf::IntRect TaikoNote::get_note_rec_value()
{
    mouth_open = !mouth_open;
    switch (current_note_type)
    {
    case note_type::ka:
        if(mouth_open)
            return sf::IntRect(260, 0, 130, 130);
        else
            return sf::IntRect(260, 130, 130, 130);
    case note_type::don:
        if(mouth_open)
            return sf::IntRect(130, 0, 130, 130);
        else
            return sf::IntRect(130, 130, 130, 130);
    case note_type::hit:
        return sf::IntRect(0, 0, 130, 130);
        break;
    
    default:
        break;
    }
    return sf::IntRect(0, 0, 130, 130);
}