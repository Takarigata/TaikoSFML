#include "../Public/InputComponent.h"

void InputComponent::method1()
{
   printf("Triggerd \n");
}

void InputComponent::method2()
{
    printf("Triggerd 2 \n");
}

void InputComponent::InitInterface()
{

}

void InputComponent::CloseInterface()
{

}

InputComponent::~InputComponent()
{
    printf("Destroyed \n");
}

InputComponent::InputComponent()
{
    printf("Created \n");
}