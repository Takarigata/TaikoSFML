#include "../Public/DebugManager.h"


DebugManager::DebugManager(token) : BaseEngineSubSystem<DebugManager>()
{

}
void DebugManager::init_imgui()
{
    ImGui::SFML::Init(*WindowManager::instance().m_window, false);
    ImGuiIO& IO = ImGui::GetIO();
    IO.Fonts->Clear();
    IO.Fonts->AddFontFromFileTTF("Assets/Fonts/DFPKanteiryu-XB.ttf", 8.f, NULL, IO.Fonts->GetGlyphRangesJapanese());
    ImGui::SFML::UpdateFontTexture();
}

void DebugManager::render_imgui()
{
    //printf("Render \n");
    ImGui::SFML::Update(*WindowManager::instance().m_window, WindowManager::instance()._clock->restart());
    ImGui::ShowDemoWindow();
    for(auto current_debug_window : debug_window)
    {
        current_debug_window->RenderDebugWindow();
    }
    ImGui::SFML::Render(*WindowManager::instance().m_window);

}

bool DebugManager::add_debug_window(BaseImGUIDebugWindow* in_debug_window)
{
    if(!in_debug_window)
        return false;
    debug_window.push_back(in_debug_window);
    return true;
}

bool DebugManager::remove_debug_window(BaseImGUIDebugWindow* in_debug_window)
{
    if(!in_debug_window)
        return false;

    auto it = std::find(debug_window.begin(), debug_window.end(), in_debug_window);
    if(it != debug_window.end())
    {
        int index = std::distance(debug_window.begin(), it);
        debug_window.erase(debug_window.begin() + index);
    }

    return false;
}

void TestImGUIDebug::RenderDebugWindow()
{
     if (ImGui::Begin(" SPRITE"))
       {
            if(ImGui::SliderFloat2("Sprite pos", sprite_pos, 0, 1920))
            {
                printf("VALUE = %f %f \n", sprite_pos[0], sprite_pos[1]);
            }
       }
        
        ImGui::End();
}