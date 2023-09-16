#pragma once
#include <iostream>
#include <vector>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "../../Public/BaseImGUIWindow.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "SFMLTransformUtility.h"

class SpritePosDebug : public BaseImGUIDebugWindow
{
    public:
        SpritePosDebug();
        ~SpritePosDebug();

        void RenderDebugWindow() override;

        float sprite_pos[2] = {0,0};

        std::vector<TexturedSpriteComponent*> debug_sprite_list;

        void set_sprite_value();

        void get_current_sprite_value();

        int selectedIndex = 0;

        bool is_sprite_selected = false;





};