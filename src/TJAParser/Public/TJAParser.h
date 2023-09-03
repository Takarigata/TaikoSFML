#pragma once
#include "../../EngineFramework/SubSystem/Public/BaseSubsystem.h"
#include <iostream>
#include <fstream>
#include <codecvt>
#include <fcntl.h>
#include <locale>
//#include <windows.h>
#include "TJAMap.h"


class TJAParser  : public BaseEngineSubSystem<TJAParser>
{
public:
    
    TJAParser(token) {}
    ~TJAParser() {}

    void use() const {};

    TJAMap* ParseTJAMap(std::string& file_path);
};