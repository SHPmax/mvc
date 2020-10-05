#pragma once
#include <string>
class IntArrayIndexView {
public:
  static void render(HWND hWnd, std::vector<mx::Array<int>*> arrays) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
   
    SelectObject(hdc, ViewHelper::defaultFont(hdc));

    ViewHelper::CreateBtn(hWnd, "New", 10, 10, 100, 50, IDC_INT_NEW_ARRAY,-IDC_INT_NEW_ARRAY);
    //MessageBox(hWnd, std::toGetWindow(hWnd, IDC_INT_NEW_ARRAY)), "sdsd", 1);
  

    ViewHelper::Text(hdc, 10, 70, "All Arrayes:", 12);

    const int arraysSize = arrays.size();
    for (int i = 0; i < arraysSize; i++) {
      const int y = 110 + i * 35;
      int length;
      if (arrays[i]->isEmpty()) {
        length = 11;
        ViewHelper::Text(hdc, 120, y, "Empty array", length);
      }
      else {
    
        std::string ar = arrays[i]->toString();
        length = ar.size();
        ViewHelper::Text(hdc, 120, y, ar.c_str(), length);
      }
      ViewHelper::CreateBtn(hWnd, "delete", 65 , y, 50, 35, i*1000 + IDC_INT_DESTROY_ARRAY , IDC_INT_NEW_ARRAY + 2*i + 1);
      ViewHelper::CreateBtn(hWnd, "edit", 10, y, 50, 35, i * 1000 + IDC_INT_EDIT_ARRAY, IDC_INT_NEW_ARRAY + 2*i);

    }

    EndPaint(hWnd, &ps);
  }
};