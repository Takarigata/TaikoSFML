#pragma once
#include "Scene.h"
#include "../../../EngineFramework/Utility/ImGUIDebug/SpritePosDebug/Public/SpritePosDebug.h"
#include "../../../EngineFramework/SubSystem/DebugManager/Public/DebugManager.h"
#include "../../../EngineFramework/Components/BPMSignalComponent/Public/BPMSignalComponent.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../EngineFramework/Components/AudioPlayer/Public/AudioComponent.h"
#include "TJAParser.h"
#include <vector>
#include "../../../TaikoFramework/Actor/Notes/Public/Note.h"
#include "../../../TaikoFramework/Components/DrumPart/Public/DrumPart.h"


class GameScene : public Scene
{
    public:
        GameScene();
        ~GameScene();

        void InitScene() override;

        void RenderScene() override;

        void SetupGFX();

        void InitTJAPlayer();

        void ParseNote();

    protected:

        TexturedSpriteComponent* player_background;

        TexturedSpriteComponent* player_frame;

        TexturedSpriteComponent* player_lane_background;

        TexturedSpriteComponent* player_lane_sub_background;

        TexturedSpriteComponent* game_background;

        TexturedSpriteComponent* header_background;

        TexturedSpriteComponent* footer_background;

        DrumPart* drum_base;

        DrumPart* left_don_sprite;

        DrumPart* right_don_sprite;

        DrumPart* left_ka_sprite;

        DrumPart* right_ka_sprite;

        TexturedSpriteComponent* note_hit;

        SpritePosDebug* sprite_debug;

        AudioComponent* music_player;

        AudioComponent* debug_hit_ka;

        AudioComponent* debug_hit_don;

        BPMSignalComponent bpm_comp;

        sf::Clock tja_clock;
        
        TaikoNote* test_note;

        std::vector<TaikoNote*> note_on_screen;

        sf::Vector2f note_start_pos;

        sf::Vector2f note_end_pos;

        int current_note = 0;

        int current_spawned_note = 0;

};