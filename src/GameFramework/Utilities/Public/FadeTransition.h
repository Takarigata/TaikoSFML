#include <SFML/Graphics.hpp>
#include "MathLib.h"
#include <SFML/System/Clock.hpp>
#include "WindowManager.h"
#include <cstdlib>
#include <SFML/System.hpp>
#include <iostream>

class FadeTransition
{
    public:

        FadeTransition(bool in_fade_out = true, float in_fade_time = 5);
        ~FadeTransition();

        void StartFadeTransition();

        bool fade_out;
        float fade_time;


    protected:

        sf::RectangleShape FadeBox;

};