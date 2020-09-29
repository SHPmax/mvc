#pragma once
class ViewHelper {
private:
  static BOOL CALLBACK DestoryChildCallback(
    HWND   hwnd,
    LPARAM lParam
  )
  {
    if (hwnd != NULL) {
      DestroyWindow(hwnd);
    }

    return TRUE;
  }
public:
  static void cleanScrean(HWND hWnd) {
    EnumChildWindows(hWnd, DestoryChildCallback, NULL);
  }
  static void CreateBtn(HWND hWnd, LPCTSTR name, const int x, const int y, const int width, const int height, UINT key, BOOL update = false) {
    if (update || GetWindow(hWnd, key) == NULL) {
      HWND hwndButton = CreateWindow(
        "BUTTON",  // Predefined class; Unicode assumed 
        name,      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        x,         // x position 
        y,         // y position 
        width,        // Button width
        height,        // Button height
        hWnd,     // Parent window
        (HMENU)key,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
   }
  }


  static BOOL Text(HDC hdc, const int x, const int y, LPCTSTR text, const UINT text_length) {
    return TextOut(hdc, x, y, text, text_length);
  }
};

