#include "Game.h"
// #include "BaseEngineSubsystem.h"

GameSFML *gameSFML = nullptr;
// BaseEngineSubsystem* Engine = nullptr;

int main(int argc, char* argv[])
{
	gameSFML = new GameSFML();
	
	gameSFML->init("Taiko SDK", 1920 , 1080, false);
	//printf("Window = %d", WindowManagerSubSystem::GetInstance()->GetWindowRef()->getSize().x);

	
	while(gameSFML->running())
	{
		gameSFML->handleEvents();
		gameSFML->update();
		gameSFML->render();
	}
	
	gameSFML->clean();
	
	return 0;
}