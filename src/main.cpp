#include "Game.h"
#include "EngineFramework/Public/EventHandler.h"
// #include "BaseEngineSubsystem.h"

GameSFML *gameSFML = nullptr;
// BaseEngineSubsystem* Engine = nullptr;

int main(int argc, char* argv[])
{
	gameSFML = new GameSFML();
	
	gameSFML->init("Taiko SDK", 1920 , 1080, false);

	
	while(gameSFML->running())
	{
		gameSFML->handleEvents();
		static_cast<EventHandler*>(EventHandler::GetInstance())->UpdateInputEvent(gameSFML);
		gameSFML->update();
		gameSFML->render();
	}
	
	gameSFML->clean();
	
	return 0;
}