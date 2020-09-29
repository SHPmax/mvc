#pragma once
   unsigned int Base::currentControllerName = 0;


   void Base::redirectTo(unsigned int message) {
    currentControllerName = message;
  }

   unsigned int Base::currentMsg() {
    return currentControllerName;
  }
