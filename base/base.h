#pragma once
class Base {
private:
  static unsigned int currentControllerName;
  static void cleanScr(HWND hWnd, const BOOL paint, const BOOL clean);
public:
  static bool routing(HWND hWnd, unsigned int message, UINT msg, const bool paint = TRUE);


  static void redirectTo(unsigned int message);

  static unsigned int currentMsg();
};
