#pragma once
#include <string>
class IntArrayController {
private:
  //static std::vector<mx::Array<int>*> intArrays;
  static  mx::Array<int>* current_array;
public:
  static void index(HWND hWnd) {//IDC_INT_ARRAY
    IntArrayIndexView::render(hWnd, DataBase::intArrays);
  }

  static void show(HWND hWnd) {
    IntArrayShowView::render(hWnd, current_array);
  }

  static void newArray(HWND hWnd) {
    DataBase::intArrays.push_back(new mx::Array<int>);
    Base::redirectTo(IDC_INT_ARRAY);
  }

  static void pushBack(HWND hWnd) {
    int nRetVal = GetDlgItemInt(hWnd, EDIT_FIRST, 0, 0);
    current_array->pushBack(nRetVal);
    Base::redirectTo(IDC_INT_SHOW_ARRAY);
  }
  static void pushFront(HWND hWnd) {
    int nRetVal = GetDlgItemInt(hWnd, EDIT_FIRST, 0, 0);
    current_array->pushFront(nRetVal);
    Base::redirectTo(IDC_INT_SHOW_ARRAY);
  }

  static void popBack(HWND hWnd) {
    current_array->popBack();
    Base::redirectTo(IDC_INT_SHOW_ARRAY);
  }


  static void popFront(HWND hWnd) {
    current_array->popFront();
    Base::redirectTo(IDC_INT_SHOW_ARRAY);
  }
  static void deleteArray(HWND hWnd, int param) {
    DataBase::intArrays.erase(DataBase::intArrays.begin() + param);
    Base::redirectTo(IDC_INT_ARRAY);
  }

  static void editArray(HWND hWnd, int param) {
    current_array = DataBase::intArrays[param];
    Base::redirectTo(IDC_INT_SHOW_ARRAY);
  }
};

mx::Array<int>* IntArrayController::current_array;