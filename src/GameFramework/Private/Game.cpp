#include "../Public/Game.h"
#include <algorithm>


GameSFML::GameSFML()
{}

GameSFML::~GameSFML()
{}

void GameSFML::init(const char* title, int width, int height, bool fullscreen)
{
    int flag = 4;
    if(fullscreen)
    {
        flag = 8;
    }
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, flag);
    m_window->setFramerateLimit(144);
    m_window->setVerticalSyncEnabled(true);
    static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->SetWindowRef(m_window);
    BaseScene = new MainMenuScene();
    BaseScene->InitScene();
    static_cast<SceneManagerSubSystem*>(SceneManagerSubSystem::GetInstance())->SetActiveScene(BaseScene);

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
    //static_cast<SceneManagerSubSystem*>(SceneManagerSubSystem::GetInstance())->GetActiveScene();
    Scene* CurrentScene = static_cast<SceneManagerSubSystem*>(SceneManagerSubSystem::GetInstance())->GetActiveScene();
    if(CurrentScene)
    {
        CurrentScene->UpdateScene();
    }
}

void GameSFML::render()
{
    m_window->clear();
    ImGui::SFML::Update(*m_window, m_deltaClock->restart());
    Scene* CurrentScene = static_cast<SceneManagerSubSystem*>(SceneManagerSubSystem::GetInstance())->GetActiveScene();
    CurrentScene->RenderScene();
    ImGui::ShowDemoWindow();
    ImGui::SFML::Render(*m_window);
    m_window->display();
}

void GameSFML::handleEvents()
{
    sf::Event event;
    if(m_window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(*m_window, event);
        if(event.type == sf::Event::Closed)
        {
            isRunning = false;
        }
    }
    
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
