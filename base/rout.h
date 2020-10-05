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

bool Base::routing(HWND hWnd, unsigned int message, UINT msg, const bool paint) {
  currentControllerName = message;
  //ViewHelper::cleanScrean(hWnd);

  switch (message)
  {
  case IDC_HOME:
    //if (!paint)
    cleanScr(hWnd, paint, TRUE);
    HomeController::index(hWnd);
    return TRUE;
    break;
  case IDC_INT_ARRAY:
    //if (!paint)
    cleanScr(hWnd, paint, TRUE);
    IntArrayController::index(hWnd);
    return TRUE;
    break;
  case IDC_INT_ARRAY_PUSH_BACK:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::pushBack(hWnd);
    return TRUE;
    break;
  case IDC_INT_ARRAY_PUSH_FRONT:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::pushFront(hWnd);
    return TRUE;
    break;
  case IDC_INT_ARRAY_POP_BACK:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::popBack(hWnd);
    return TRUE;
    break;
  case IDC_INT_ARRAY_POP_FRONT:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::popFront(hWnd);
    return TRUE;
    break;
  case IDC_INT_NEW_ARRAY:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::newArray(hWnd);
    return TRUE;
    break;
  case IDC_INT_SHOW_ARRAY:
    cleanScr(hWnd, paint, FALSE);
    IntArrayController::show(hWnd);
    return TRUE;
    break;
  default:
    break;
  }


  unsigned int rawMsg = message;
  int param = message / 1000;
  int msgFromParam = int(message - param * 1000);
  switch (msgFromParam)
  {
  case IDC_INT_DESTROY_ARRAY:
  {
    //message = IDC_INT_DESTROY_ARRAY;
    cleanScr(hWnd, paint, TRUE);
    IntArrayController::deleteArray(hWnd, param);
    return TRUE;
  }
  break;
  case IDC_INT_EDIT_ARRAY:
  {
    //message = IDC_INT_DESTROY_ARRAY;
    cleanScr(hWnd, paint, TRUE);
    IntArrayController::editArray(hWnd, param);
    return TRUE;
  }
  break;
  default:
    return FALSE;
    break;
  }

  return true;
}