#include "../Public/SFMLTransformUtility.h"

SFMLTransformLib::SFMLTransformLib(){}

SFMLTransformLib::~SFMLTransformLib(){}

sf::Vector2f SFMLTransformLib::CalculateScreenPos(float width_percent, float height_percent)
{
    sf::Vector2f out_vector;
    sf::RenderWindow* _window = WindowManager::instance().m_window;
    if(_window)
    {
        out_vector.x = _window->getView().getSize().x * width_percent;
        out_vector.y = _window->getView().getSize().y * height_percent;
    }

    return out_vector;
}

