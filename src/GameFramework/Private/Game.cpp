#include "../Public/Game.h"
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
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, flag);
    m_window->setFramerateLimit(framerate);
    m_window->setVerticalSyncEnabled(true);
    WindowManager::instance().SetWindowRef(m_window);
    BaseScene = new MainMenuScene();
    BaseScene->InitScene();
    SceneManager::instance().SetActiveScene(BaseScene);
    ImGui::SFML::Init(*m_window, false);
    InitImGuiFont();
    InitDebugTools();
    m_deltaClock = new sf::Clock();
    
    if(m_window)
    {
        isRunning = true;
    }
}

void GameSFML::InitImGuiFont()
{
    ImGuiIO& IO = ImGui::GetIO();
    IO.Fonts->Clear();
    IO.Fonts->AddFontFromFileTTF("Assets/Fonts/DFPKanteiryu-XB.ttf", 8.f, NULL, IO.Fonts->GetGlyphRangesJapanese());

    ImGui::SFML::UpdateFontTexture();
}

void GameSFML::InitDebugTools()
{

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
    ImGui::SFML::Update(*m_window, m_deltaClock->restart());
    Scene* CurrentScene = SceneManager::instance().GetActiveScene();
    if(CurrentScene)
        CurrentScene->RenderScene();
    ImGui::ShowDemoWindow();
    ImGui::SFML::Render(*m_window);
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
