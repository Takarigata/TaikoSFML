#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "BaseEngineSubsystem.h"

class WindowManagerSubSystem : BaseEngineSubsystem
{
    public:

        GameSFML* GameRefl;
        sf::RenderWindow* WindowRef;

        //static override  
};