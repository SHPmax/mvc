#pragma once
#include <string>
class IntSetShowView {
public:
  static void render(HWND hWnd, mx::Set<int>* current_set) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    SelectObject(hdc, ViewHelper::defaultFont(hdc));
    if (current_set->isEmpty()) {
      ViewHelper::Text(hdc, 10, 150, "Empty set", 9);
    }
    else {
      std::string ar = current_set->toString();
      ViewHelper::Text(hdc, 10, 150, ar.c_str(), ar.size());
    }
    ViewHelper::CreateBtn(hWnd, "insert", 10, 10, 100, 50, IDC_INT_SET_INSERT, 0);

    //ViewHelper::CreateBtn(hWnd, "popBack", 10, 70, 100, 50, IDC_INT_ARRAY_POP_BACK, 2);
    //ViewHelper::CreateBtn(hWnd, "popFront", 120, 70, 100, 50, IDC_INT_ARRAY_POP_FRONT, 3);
    ViewHelper::CreateBtn(hWnd, "Home", 230, 10, 100, 50, IDC_HOME, 5);
    ViewHelper::CreateBtn(hWnd, "All Sets", 230, 70, 100, 50, IDC_INT_SET, 6);


    ViewHelper::CreateEdit(hWnd, "1" ,400, 10, 200, 25, EDIT_FIRST, 100);



    EndPaint(hWnd, &ps);
  }
};