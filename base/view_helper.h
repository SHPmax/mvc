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

  static void CreateEdit(HWND hWnd, LPCTSTR name, const int x, const int y, const int width, const int height, UINT key, const int id, LPVOID pointer = NULL, BOOL update = false) {
    if (update || !btnExist(id)) {
      ids.insert(id);
      CreateWindowEx(NULL, _T("edit"), name, WS_CHILD | WS_VISIBLE | WS_VSCROLL |
        WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, x, y, width, height, hWnd, (HMENU)key, NULL, NULL);

    }
  }

  static BOOL Text(HDC hdc, const int x, const int y, LPCTSTR text, const UINT text_length) {
    return TextOut(hdc, x, y, text, text_length);
  }

  static HFONT defaultFont(HDC hdc) {
    HFONT hFont;

    static LOGFONT lf;
    lf.lfWeight = FW_BOLD;
    lf.lfHeight = 1000000;
    static const int points_per_inch = 35;
    int pixels_per_inch = GetDeviceCaps(hdc, LOGPIXELSY);
    int pixels_height = -MulDiv(10, pixels_per_inch, points_per_inch);
    lf.lfHeight = points_per_inch;
    //GetObject(GetStockObject(SYSTEM_FIXED_FONT), sizeof(LOGFONT), &lf);

    hFont = CreateFont(lf.lfHeight, lf.lfWidth,
      lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
      lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut,
      lf.lfCharSet, lf.lfOutPrecision, lf.lfClipPrecision,
      lf.lfQuality, lf.lfPitchAndFamily, lf.lfFaceName);

    return hFont;
  }
};

std::set<int> ViewHelper::ids{};
std::vector<HWND> ViewHelper::btns{};

