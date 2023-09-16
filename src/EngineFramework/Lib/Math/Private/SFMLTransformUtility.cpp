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

sf::Vector2f SFMLTransformLib::WorldPosToScreenPos(sf::Vector2f in_position)
{
    sf::Vector2f out_vector;
    sf::RenderWindow* _window = WindowManager::instance().m_window;
    if(_window)
    {
        out_vector.x = in_position.x / _window->getView().getSize().x;
        out_vector.y = in_position.y / _window->getView().getSize().y;
    }

    return out_vector;
}

bool SFMLTransformLib::IsVectorEqual(sf::Vector2f a, sf::Vector2f b, float epsilon)
{
    bool out_value = false;
    return out_value;
    float EPSILON = epsilon;
    out_value = (fabs(a.x - b.x) < EPSILON && fabs(a.y - b.y) < EPSILON);
    printf("a x %f a y %f \n", fabs(a.x - b.x), fabs(a.y - b.y));
    return out_value;
}

