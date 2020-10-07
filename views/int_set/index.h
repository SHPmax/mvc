#pragma once
#include <string>
class IntSetIndexView {
public:
  static void render(HWND hWnd, std::vector<mx::Set<int>*> sets) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    SelectObject(hdc, ViewHelper::defaultFont(hdc));

    ViewHelper::CreateBtn(hWnd, "New", 10, 10, 100, 50, IDC_INT_NEW_SET, -IDC_INT_NEW_SET);


    ViewHelper::Text(hdc, 10, 70, "All Sets:", 9);

    const int setsSize = sets.size();
    for (int i = 0; i < setsSize; i++) {
      const int y = 110 + i * 35;
      int length;
      if (sets[i]->isEmpty()) {
        length = 9;
        ViewHelper::Text(hdc, 150, y, "Empty set", length);
      }
      else {

        std::string ar = sets[i]->toString();
        length = ar.size();
        ViewHelper::Text(hdc, 150, y, ar.c_str(), length);
      }
      ViewHelper::CreateBtn(hWnd, "delete", 65, y, 50, 35, i * 1000 + IDC_INT_DESTROY_SET, IDC_INT_NEW_ARRAY + 2 * i + 1);
      ViewHelper::CreateBtn(hWnd, "edit", 10, y, 50, 35, i * 1000 + IDC_INT_EDIT_SET, IDC_INT_NEW_ARRAY + 2 * i);
      ViewHelper::CreateChBox(hWnd, "f", 120, y, 20, 35, i*1000 + IDC_CH_BOX, y);

    }
    ViewHelper::CreateBtn(hWnd, "Home", 470, 10, 100, 50, IDC_HOME, -1);
    ViewHelper::CreateBtn(hWnd, "+", 120, 10, 100, 50, IDC_INT_SET_PLUS, 1);
    ViewHelper::CreateBtn(hWnd, "*", 230, 10, 100, 50, IDC_INT_SET_MUL, 2);
    ViewHelper::CreateBtn(hWnd, "/", 350, 10, 100, 50, IDC_INT_SET_DEL, 3);

    EndPaint(hWnd, &ps);
  }
};