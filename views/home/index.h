#pragma once
class HomeIndexView {
public:
  static void render(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    ViewHelper::CreateBtn(hWnd, "Array", 10, 10, 100, 50, IDC_INT_ARRAY, -IDC_INT_ARRAY);


    EndPaint(hWnd, &ps);
  }
};