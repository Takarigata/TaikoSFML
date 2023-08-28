#pragma once
#include "../../Public/BaseSubsystem.h"
#include "../../../Public/Scene.h"

class SceneManager final : public BaseEngineSubSystem<SceneManager>
{

public:
    SceneManager(token) { std::cout << "constructed Test" << std::endl; }
    ~SceneManager() {  std::cout << "destructed Test" << std::endl; }

    void use() const { std::cout << "in use Test" << std::endl; };

    Scene* GetActiveScene();

    bool SetActiveScene(Scene* NewActiveScene);

protected :

    Scene* CurrentActiveScene;

};