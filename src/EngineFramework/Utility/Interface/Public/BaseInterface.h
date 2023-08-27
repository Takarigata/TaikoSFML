#pragma once

class Interface
{

   public:
      Interface(){}

      ~Interface();
      virtual void InitInterface() = 0;    
      virtual void CloseInterface() = 0;
};