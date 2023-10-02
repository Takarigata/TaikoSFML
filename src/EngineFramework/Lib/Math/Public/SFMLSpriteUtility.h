#pragma once
#include <algorithm>
#include <math.h> 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class SFMLSpriteUtility
{
    public:
        SFMLSpriteUtility();
        ~SFMLSpriteUtility();

        static sf::IntRect get_sprite_inrect_by_xypos(int row = 0, int column = 0, int sprite_size_x = 64, int sprite_size_y = 64);


};