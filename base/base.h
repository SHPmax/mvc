#pragma once
class Base {
private:
  static unsigned int currentControllerName;
public:
  static bool routing(HWND hWnd, unsigned int message, const bool paint = TRUE) {
    if (!paint) {
      ViewHelper::cleanScrean(hWnd);
      switch (message)
      {
      case WM_CREATE:
        HomeController::index(hWnd);
        break;
      case IDC_INT_ARRAY:
        IntArrayController::index(hWnd);
        break;
      case IDC_INT_ARRAY_PUSH_BACK:
        IntArrayController::pushBack(hWnd);
        break;
      default:
        return false;
      }
    }
    currentControllerName = message;
    if (paint) {
     InvalidateRect(hWnd, NULL, TRUE);
     UpdateWindow(hWnd);
    }
    return true;
  }

  static unsigned int currentMsg() {
    return currentControllerName;
  }
};