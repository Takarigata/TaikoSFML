#pragma once
#include <string>

class BaseComponent 
{
    public:
        BaseComponent();
        ~BaseComponent();

        virtual void tick(float elapsed_time);

        std::string component_name;

};