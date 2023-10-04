#pragma once
#include "../Public/BaseComponent.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class TexturedSpriteComponent : public BaseComponent
{
    public:
        
        TexturedSpriteComponent();
        TexturedSpriteComponent(sf::Vector2f sprite_size, std::string texture_path, std::string in_comp_name = "Texture Sprite Comp");
        ~TexturedSpriteComponent();

        void tick(float elapsed_time) override;

        bool ConstructSprite(sf::Vector2f sprite_size, std::string texture_path);

        sf::Texture* GetSpriteTexture() { return sprite_texture; };

        sf::Sprite* GetSpriteRef_ptr() { return sprite_obj; };
        
        sf::Sprite GetSpriteRef() { return *sprite_obj; };

        void SetSpriteScale(sf::Vector2f new_scale);

        void SetSpriteOriginToCenter();

        sf::Texture* sprite_texture;

        sf::Sprite* sprite_obj;

        
};