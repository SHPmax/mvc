#pragma once
#include <string>
class IntArrayIndexView {
public:
  static void render(HWND hWnd, std::vector<mx::Array<int>*> arrays) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
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


    SelectObject(hdc, hFont);

    ViewHelper::CreateBtn(hWnd, "New", 10, 10, 100, 50, IDC_INT_NEW_ARRAY,-IDC_INT_NEW_ARRAY);
    //MessageBox(hWnd, std::toGetWindow(hWnd, IDC_INT_NEW_ARRAY)), "sdsd", 1);
  

    ViewHelper::Text(hdc, 10, 70, "All Arrayes:", 12);

    const int arraysSize = arrays.size();
    for (int i = 0; i < arraysSize; i++) {
      const int y = 110 + i * 35;
      int length;
      if (arrays[i]->isEmpty()) {
        length = 11;
        ViewHelper::Text(hdc, 70, y, "Empty array", length);
      }
      else {
        length = 2 * arrays[i]->size() - 1;
        ViewHelper::Text(hdc, 70, y, arrays[i]->toString().c_str(), length);
      }
      ViewHelper::CreateBtn(hWnd, "delete", 10 , y, 50, 35, IDC_INT_DESTROY_ARRAY, IDC_INT_NEW_ARRAY + i);
    }

    EndPaint(hWnd, &ps);
  }
};