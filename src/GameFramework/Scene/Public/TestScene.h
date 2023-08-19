#include "Scene.h"
#include <iostream>
#include <cmath>

class TestScene : public Scene
{
    public:

        // TestScene();
        // ~TestScene();

        void InitScene() override;

        void UpdateScene() override;

        void RenderScene() override;

        float sine;

};