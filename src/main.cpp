#include "Game.h"
// #include "EngineFramework/Public/EventHandler.h"
#include "EngineFramework/SubSystem/EventHandler/Public/EventHandler.h"
#include "EngineFramework/SubSystem/Public/BaseSubsystem.h"
// #include "BaseEngineSubsystem.h"

GameSFML *gameSFML = nullptr;
// BaseEngineSubsystem* Engine = nullptr;

int main(int argc, char* argv[])
{
	//return 0;
	gameSFML = new GameSFML();
	
	gameSFML->init("Taiko SDK", 1920 , 1080, false, 144);

	
	while(gameSFML->running())
	{
		gameSFML->handleEvents();
		EventHandler::instance().UpdateInputEvent(gameSFML);
		gameSFML->update();
		gameSFML->render();
	}
	
	gameSFML->clean();
	
	return 0;
}