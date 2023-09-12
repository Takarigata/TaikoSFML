#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "../../Public/BaseSubsystem.h"
#include "../../WindowManager/Public/WindowManager.h"
#include "../../../Utility/ImGUIDebug/Public/BaseImGUIWindow.h"
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"

class TestImGUIDebug : public BaseImGUIDebugWindow
{
    public:
        TestImGUIDebug(){};
        ~TestImGUIDebug(){};

        void RenderDebugWindow() override;

        float sprite_pos[2] = {0,0};
};


class DebugManager  : public BaseEngineSubSystem<DebugManager>
{
public:
    
    DebugManager(token);
    ~DebugManager() {}

    void use() const {};

    void init_imgui();

    void render_imgui();

    bool add_debug_window(BaseImGUIDebugWindow* in_debug_window);

    bool remove_debug_window(BaseImGUIDebugWindow* in_debug_window);

    std::vector<BaseImGUIDebugWindow*> debug_window;

};

