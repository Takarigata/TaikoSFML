#pragma once
#include "WindowManager.h"
#include "SceneManager.h"
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "imgui.h"
#include "../Scene/Public/TestScene.h"
#include "../Scene/Public/TestScene2.h"
#include "../../TaikoFramework/Scene/MainMenu/Public/MainMenuScene.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"





using namespace std;
class GameSFML
{
    
public:
    GameSFML();
    ~GameSFML();

    void init(const char* title, int width, int height, bool fullscreen, int framerate);


    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    void InitImGuiFont();

    void InitDebugTools();

    void SetGameRunningState(bool new_running_state);
    
private:
    int cnt = 0;
    
    bool isRunning;
    sf::RenderWindow* m_window;
    sf::CircleShape* shape;
    sf::Font* font;
    sf::Clock* m_deltaClock;
    map<sf::Drawable*, sf::RenderStates*> ObjectsToDraw;

    Scene* BaseScene;

    // EventHandler* EventHandlerInst;

    
    
};