#include "Scene.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include "../../GameFramework/Utilities/Public/FadeTransition.h"
#include <cmath>
#include "MathLib.h"


class MainMenuScene : public Scene
{
    public:
        
        void InitScene() override;

        void SetupMenuGFX();

        void RenderScene() override;

        sf::Texture BackgroundImage;

        sf::Music TitleMusic;

        sf::Clock clock;

        sf::RectangleShape FadeBox;

        sf::Sprite BackgroundSprite;

        FadeTransition* FadeOut;

        void StartTransition();

};