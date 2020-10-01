#pragma once
#include <algorithm>
class ViewHelper {
private:
  static std::vector<HWND> btns;

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
  static std::set<int> ids;
  static BOOL btnExist(const int id) {
    return  (std::find(ids.begin(), ids.end(), id) != ids.end());
  }
public:
  static void cleanScrean(HWND hWnd) {
    ids.clear();
    //btns.clear();
    EnumChildWindows(hWnd, DestoryChildCallback, NULL);
    //InvalidateRect(hWnd, NULL, TRUE);
  }
  static void CreateBtn(HWND hWnd, LPCTSTR name, const int x, const int y, const int width, const int height, UINT key, const int id, LPVOID pointer = NULL, BOOL update = false) {
    if (update || !btnExist(id)) {
      ids.insert(id);

      HWND btn = CreateWindow(
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
        pointer);     // Pointer not needed.
    }
  }


  static BOOL Text(HDC hdc, const int x, const int y, LPCTSTR text, const UINT text_length) {
    return TextOut(hdc, x, y, text, text_length);
  }
};

std::set<int> ViewHelper::ids{};
std::vector<HWND> ViewHelper::btns{};

