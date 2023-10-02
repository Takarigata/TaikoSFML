#include "../Public/SFMLSpriteUtility.h"

SFMLSpriteUtility::SFMLSpriteUtility(){}

SFMLSpriteUtility::~SFMLSpriteUtility(){}

sf::IntRect SFMLSpriteUtility::get_sprite_inrect_by_xypos(int row, int column, int sprite_size_x, int sprite_size_y)
{
    sf::IntRect res = sf::IntRect(row * sprite_size_x, column * sprite_size_y , sprite_size_x, sprite_size_y);
    return res;
}