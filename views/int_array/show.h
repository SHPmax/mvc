#pragma once
#include <string>
class IntArrayShowView {
public:
  static void render(HWND hWnd, mx::Array<int>* current_array) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    ViewHelper::Text(hdc, 300, 300, current_array->toString().c_str(), 2*current_array->size()-1);

    ViewHelper::CreateBtn(hWnd, "pushBack", 10, 10, 100, 50, IDC_INT_ARRAY_PUSH_BACK);
    ViewHelper::CreateBtn(hWnd, "pushFront", 120, 10, 100, 50, IDC_INT_ARRAY_PUSH_FRONT);
    ViewHelper::CreateBtn(hWnd, "popBack", 10, 70, 100, 50, IDC_INT_ARRAY_POP_BACK);
    ViewHelper::CreateBtn(hWnd, "popFront", 120, 70, 100, 50, IDC_INT_ARRAY_POP_FRONT);


    EndPaint(hWnd, &ps);
  }
};