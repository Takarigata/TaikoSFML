﻿#include "../Public/Game.h"
#include <algorithm>


GameSFML::GameSFML()
{}

GameSFML::~GameSFML()
{}

void GameSFML::init(const char* title, int width, int height, bool fullscreen, int framerate)
{
    int flag = 4;
    if(fullscreen)
    {
        flag = 8;
    }
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, (sf::Style::Resize + sf::Style::Close));
    m_window->setFramerateLimit(framerate);
    m_window->setVerticalSyncEnabled(true);
    m_window->setKeyRepeatEnabled(false);
    WindowManager::instance().SetWindowRef(m_window);
    BaseScene = new GameScene();
    BaseScene->InitScene();
    SceneManager::instance().SetActiveScene(BaseScene);
    InitDebugTools();
    
    m_deltaClock = new sf::Clock();
    WindowManager::instance().SetGameClock(m_deltaClock);
    
    if(m_window)
    {
        isRunning = true;
    }
}


void GameSFML::InitDebugTools()
{
    DebugManager::instance().init_imgui();
}

void GameSFML::update()
{
    cnt++;
    Scene* CurrentScene = SceneManager::instance().GetActiveScene();
    if(CurrentScene)
    {
        CurrentScene->UpdateScene();
    }
}

void GameSFML::render()
{
    m_window->clear();
    Scene* CurrentScene = SceneManager::instance().GetActiveScene();
    if(CurrentScene)
        CurrentScene->RenderScene();
    DebugManager::instance().render_imgui();
    m_window->display();
}

void GameSFML::handleEvents()
{

}

void GameSFML::clean()
{
    ImGui::SFML::Shutdown();
    m_window->close();
}

bool GameSFML::running()
{

    return isRunning;
}

void GameSFML::SetGameRunningState(bool new_running_state)
{
    isRunning = new_running_state;
}
