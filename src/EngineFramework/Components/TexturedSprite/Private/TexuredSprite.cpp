#include "../Public/TexturedSprite.h"

TexturedSpriteComponent::TexturedSpriteComponent(){}

TexturedSpriteComponent::~TexturedSpriteComponent(){}

TexturedSpriteComponent::TexturedSpriteComponent(sf::Vector2f sprite_size, std::string texture_path, std::string in_comp_name)
{
    ConstructSprite(sprite_size, texture_path);
    component_name = in_comp_name;
}

bool TexturedSpriteComponent::ConstructSprite(sf::Vector2f sprite_size, std::string texture_path)
{
    sprite_texture = new sf::Texture();
    if(!sprite_texture->loadFromFile(texture_path))
    {
        printf("Texture %s failed to load", texture_path.c_str());
        return false;
    }
    sprite_obj = new sf::Sprite();
    sprite_obj->setTexture(*sprite_texture);
    sprite_texture->setSmooth(true);
    sprite_obj->setScale(sprite_size);
    
    return true;
}

void TexturedSpriteComponent::SetSpriteOriginToCenter()
{
    sprite_obj->setOrigin(sf::Vector2f(sprite_obj->getLocalBounds().width / 2, sprite_obj->getLocalBounds().height / 2));
}

void TexturedSpriteComponent::SetSpriteScale(sf::Vector2f new_scale)
{
    sprite_obj->setScale(new_scale);
}

void TexturedSpriteComponent::tick(float elapsed_time)
{
    
}