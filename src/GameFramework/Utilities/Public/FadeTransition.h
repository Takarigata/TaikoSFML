#include <SFML/Graphics.hpp>
#include "MathLib.h"
#include <SFML/System/Clock.hpp>
//#include "WindowManager.h"
#include <cstdlib>
#include <SFML/System.hpp>
#include <iostream>

class FadeTransition
{
    public:

        FadeTransition(bool in_fade_out = true, float in_fade_time = 5, bool in_hold_fade = false);
        ~FadeTransition();

        void StartFadeTransition();
        bool UpdateTransition();
        int alpha_value;
        int target_value;

        bool fade_out;
        bool hold_fade;
        float fade_time;
        sf::Clock FadeClock;


    protected:

        sf::RectangleShape FadeBox;

};