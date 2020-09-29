#pragma once
#include <string>
class IntArrayIndexView {
public:
  static void render(HWND hWnd, std::vector<mx::Array<int>*> arrays) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    //ViewHelper::Text(hdc, 300, 300, "cur", 3);

    ViewHelper::CreateBtn(hWnd, "New", 10, 10, 100, 50, IDC_INT_ARRAY_PUSH_BACK);
    ViewHelper::CreateBtn(hWnd, "Use", 120, 10, 100, 50, IDC_INT_ARRAY_PUSH_FRONT);

    for (auto& elem : arrays) {
      ViewHelper::Text(hdc, 300, 300, elem->toString().c_str(), 2 * elem->size() - 1);
    }

    EndPaint(hWnd, &ps);
  }
};