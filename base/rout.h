#pragma once
bool Base::routing(HWND hWnd, unsigned int message, const bool paint) {
  currentControllerName = message;

  switch (message)
  {
  case WM_HOME:
    if (!paint)
      HomeController::index(hWnd);
    break;
  case IDC_INT_ARRAY:
    if (!paint)
      IntArrayController::index(hWnd);
    break;
  case IDC_INT_ARRAY_PUSH_BACK:
    IntArrayController::pushBack(hWnd);
    break;
  default:
    return false;
  }
  if (paint) {
    ViewHelper::cleanScrean(hWnd);
    InvalidateRect(hWnd, NULL, TRUE);
    UpdateWindow(hWnd);
  }
  return true;
}