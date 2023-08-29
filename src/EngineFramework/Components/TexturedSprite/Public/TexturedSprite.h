#pragma once
#include "../Public/BaseComponent.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class TexturedSpriteComponent : public BaseComponent
{
    public:
        
        TexturedSpriteComponent();
        TexturedSpriteComponent(sf::Vector2f sprite_size, std::string texture_path);
        ~TexturedSpriteComponent();

        bool ConstructSprite(sf::Vector2f sprite_size, std::string texture_path);

        sf::Texture GetSpriteTexture() { return sprite_texture; };

        sf::Sprite GetSpriteRef() { return sprite_obj; };

        void SetSpriteScale(sf::Vector2f new_scale);

        sf::Texture sprite_texture;

        sf::Sprite sprite_obj;


    protected : 

        


};