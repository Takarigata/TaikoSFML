#include "../Public/TexturedSprite.h"

TexturedSpriteComponent::TexturedSpriteComponent(){}

TexturedSpriteComponent::~TexturedSpriteComponent(){}

TexturedSpriteComponent::TexturedSpriteComponent(sf::Vector2f sprite_size, std::string texture_path)
{
    ConstructSprite(sprite_size, texture_path);
}

bool TexturedSpriteComponent::ConstructSprite(sf::Vector2f sprite_size, std::string texture_path)
{
    sprite_texture = sf::Texture();
    if(!sprite_texture.loadFromFile(texture_path))
    {
        printf("Texture %s failed to load", texture_path.c_str());
        return false;
    }
    sprite_obj = sf::Sprite();
    sprite_obj.setTexture(sprite_texture);
    sprite_texture.setSmooth(true);
    sprite_obj.setScale(sprite_size);
    return true;
}

void TexturedSpriteComponent::SetSpriteScale(sf::Vector2f new_scale)
{
    sprite_obj.setScale(new_scale);
}