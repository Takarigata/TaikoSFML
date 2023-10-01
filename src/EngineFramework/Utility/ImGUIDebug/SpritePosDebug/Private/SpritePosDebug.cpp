#include "../Public/SpritePosDebug.h"

SpritePosDebug::SpritePosDebug()
{

}

SpritePosDebug::~SpritePosDebug()
{

}


void SpritePosDebug::RenderDebugWindow()
{
    std::vector items{"a", "b", "c"};
    std::vector<std::string> sprite_name;
    for (auto curr_sprite : debug_sprite_list)
    {
        sprite_name.push_back(curr_sprite->component_name.c_str());
    }
    if (ImGui::Begin("SPRITE POS DEBUG"))
    {
        static ImGuiSliderFlags flags = ImGuiSliderFlags_AlwaysClamp;
        ImGui::DragFloat("Sprite X Screen Percent", &sprite_pos[0], 0.005f, -1.0f, 1.0f, "%.3f", flags);
        ImGui::DragFloat("Sprite Y Screen Percent", &sprite_pos[1], 0.005f, -1.0f, 1.0f, "%.3f", flags);

        if (ImGui::BeginCombo("combos", sprite_name[selectedIndex].c_str())) {
            for (int i = 0; i < sprite_name.size(); ++i) 
            {
                const bool isSelected = (selectedIndex == i);
                if (ImGui::Selectable(sprite_name[i].c_str(), isSelected)) 
                {
                    is_sprite_selected = true;
                    selectedIndex = i;
                    get_current_sprite_value();
                    printf("SELECTED  %d \n", i);
                }

                if (isSelected) {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }
    }
    ImGui::End();

    set_sprite_value();
}

void SpritePosDebug::get_current_sprite_value()
{
    if(selectedIndex != -1 && selectedIndex < debug_sprite_list.size())
    {
        sf::Vector2f sprite_screen_percentage = SFMLTransformLib::WorldPosToScreenPos(debug_sprite_list[selectedIndex]->GetSpriteRef_ptr()->getPosition());
        sprite_pos[0] = sprite_screen_percentage.x;
        sprite_pos[1] = sprite_screen_percentage.y;
    }
}

void SpritePosDebug::set_sprite_value()
{
    if(selectedIndex != -1 && selectedIndex < debug_sprite_list.size() && is_sprite_selected)
    {
        sf::Vector2f position = SFMLTransformLib::CalculateScreenPos(sprite_pos[0], sprite_pos[1]);
        sf::Sprite* ptr = debug_sprite_list[selectedIndex]->GetSpriteRef_ptr();
        ptr->setPosition(position);
    }
    
}