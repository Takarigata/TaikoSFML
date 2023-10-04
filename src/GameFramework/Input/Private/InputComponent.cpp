#include "../Public/InputComponent.h"

void InputComponent::drum_hit()
{
   printf("DRUM HIT \n");
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