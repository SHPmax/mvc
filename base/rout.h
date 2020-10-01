#pragma once

void Base::cleanScr(HWND hWnd, const BOOL paint, const BOOL clean) {
  if (paint) {
    if (clean) {
      ViewHelper::cleanScrean(hWnd);
    }
    InvalidateRect(hWnd, NULL, TRUE);
    //UpdateWindow(hWnd);
  }
}

bool Base::routing(HWND hWnd, unsigned int message, LPARAM pointer, const bool paint) {
  currentControllerName = message;
  //ViewHelper::cleanScrean(hWnd);


  switch (message)
  {
  case WM_HOME:
    //if (!paint)
    cleanScr(hWnd, paint, true);
    HomeController::index(hWnd);
    break;
  case IDC_INT_ARRAY:
    //if (!paint)
    cleanScr(hWnd, paint, true);
    IntArrayController::index(hWnd);
    break;
  case IDC_INT_ARRAY_PUSH_BACK:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::pushBack(hWnd);
    break;
  case IDC_INT_NEW_ARRAY:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::newArray(hWnd);
    break;
  case IDC_INT_DESTROY_ARRAY:
    //HWND s; //declare pointer-to-struct variable
    //s = (HWND)pointer;
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::deleteArray(hWnd, pointer);
    break;
  default:
    return false;
  }

  return true;
}