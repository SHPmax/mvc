#pragma once
#include <string>
class IntArrayShowView {
public:
  static void render(HWND hWnd, mx::Array<int>* current_array) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    SelectObject(hdc, ViewHelper::defaultFont(hdc));
    if (current_array->isEmpty()) {
      ViewHelper::Text(hdc, 10, 150, "Empty array", 11);
    }
    else {
      std::string ar = current_array->toString();
      ViewHelper::Text(hdc, 10, 150, ar.c_str(), ar.size());
    }
    ViewHelper::CreateBtn(hWnd, "pushBack", 10, 10, 100, 50, IDC_INT_ARRAY_PUSH_BACK, 0);
    ViewHelper::CreateBtn(hWnd, "pushFront", 120, 10, 100, 50, IDC_INT_ARRAY_PUSH_FRONT, 1);
    ViewHelper::CreateBtn(hWnd, "popBack", 10, 70, 100, 50, IDC_INT_ARRAY_POP_BACK, 2);
    ViewHelper::CreateBtn(hWnd, "popFront", 120, 70, 100, 50, IDC_INT_ARRAY_POP_FRONT, 3);
    ViewHelper::CreateBtn(hWnd, "Home", 230, 10, 100, 50, IDC_HOME, 5);
    ViewHelper::CreateBtn(hWnd, "All Arrays", 230, 70, 100, 50, IDC_INT_ARRAY, 6);


    ViewHelper::CreateEdit(hWnd, "1" ,400, 10, 200, 25, EDIT_FIRST, 100);



    EndPaint(hWnd, &ps);
  }
};