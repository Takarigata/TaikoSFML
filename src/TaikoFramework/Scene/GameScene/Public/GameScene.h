#pragma once
#include "Scene.h"
#include "../../../EngineFramework/Utility/ImGUIDebug/SpritePosDebug/Public/SpritePosDebug.h"
#include "../../../EngineFramework/SubSystem/DebugManager/Public/DebugManager.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"


class GameScene : public Scene
{
    public:
        GameScene();
        ~GameScene();

        void InitScene() override;

        void RenderScene() override;

        void SetupGFX();

    protected:

        TexturedSpriteComponent* player_background;

        TexturedSpriteComponent* player_frame;

        TexturedSpriteComponent* player_lane_background;

        TexturedSpriteComponent* player_lane_sub_background;

        TexturedSpriteComponent* game_background;

        TexturedSpriteComponent* header_background;

        TexturedSpriteComponent* footer_background;

        TexturedSpriteComponent* drum_base;

        TexturedSpriteComponent* don_sprite;

        TexturedSpriteComponent* ka_sprite;

        SpritePosDebug* sprite_debug;

};