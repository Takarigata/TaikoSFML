#pragma once
#include <stdio.h>
#include <iostream>

class Scene
{
    public:
        Scene();
        ~Scene();

        bool IsSceneLoaded = true;

        void InitScene();
        void UpdateScene();
        void CloseScene();
        void UnloadScene();
};