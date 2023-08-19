#pragma once
#include "WindowManager.h"
#include "SceneManager.h"
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"





using namespace std;
class GameSFML
{
    
public:
    GameSFML();
    ~GameSFML();

    void init(const char* title, int width, int height, bool fullscreen);


    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    void InitImGuiFont();

    void InitDebugTools();
    
private:
    int cnt = 0;
    
    bool isRunning;
    sf::RenderWindow* m_window;
    sf::CircleShape* shape;
    sf::Font* font;
    sf::Clock* m_deltaClock;
    map<sf::Drawable*, sf::RenderStates*> ObjectsToDraw;

    
    
};