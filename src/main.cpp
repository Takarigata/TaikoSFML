#include "Game.h"
#include "EngineFramework/SubSystem/EventHandler/Public/EventHandler.h"
#include "EngineFramework/SubSystem/Public/BaseSubsystem.h"
#include "TJAParser/Public/TJAParser.h"

GameSFML *gameSFML = nullptr;
int main(int argc, char* argv[])
{
	std::string path = "E:\\DEV\\TJADB\\ESE\\07 Game Music\\Hopes and Dreams\\Hopes and Dreams.tja";
	// std::string path = "E:/DEV/ボーカロイド.tja";
	TJAMap* map = TJAParser::instance().ParseTJAMap(path);

	// return 0;
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