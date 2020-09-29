#pragma once
class Base {
private:
  static unsigned int currentControllerName;
public:
  static bool routing(HWND hWnd, unsigned int message, const bool paint = TRUE);


  static void redirectTo(unsigned int message);

  static unsigned int currentMsg();
};
