#pragma once
#include "../../Public/BaseSubsystem.h"
#include "../../../Public/Scene.h"

class SceneManager final : public BaseEngineSubSystem<SceneManager>
{

public:
    SceneManager(token) {}
    ~SceneManager() {}

    void use() const {};

    Scene* GetActiveScene();

    bool SetActiveScene(Scene* NewActiveScene);

protected :

    Scene* CurrentActiveScene;

};