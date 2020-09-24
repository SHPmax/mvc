#pragma once
class HomeController {
public:
  static void index(HWND hWnd) {
    //ControllerHelper::cleanScrean(hWnd);

    HomeIndexView::render(hWnd);
  }
};