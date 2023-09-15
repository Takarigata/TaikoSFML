#pragma once
#include "Scene.h"
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

        TexturedSpriteComponent* game_background;

        TexturedSpriteComponent* footer_background;

        TexturedSpriteComponent* drum_base;

        TexturedSpriteComponent* don_sprite;

        TexturedSpriteComponent* ka_sprite;

};