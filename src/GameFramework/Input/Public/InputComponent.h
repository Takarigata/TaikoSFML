#pragma once
#include "../../../EngineFramework/Utility/Interface/Public/BaseInterface.h"
#include <stdio.h>

class InputComponent : public Interface
{
    public:
        InputComponent();
        ~InputComponent();

        void InitInterface();

        void CloseInterface();

        void method1();

        void method2();
};
