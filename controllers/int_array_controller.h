#pragma once
class IntArrayController {
private:
  static  mx::Array<int>* current_array;
public:
  static void index(HWND hWnd) {//IDC_INT_ARRAY

    if (DataBase::intArrays.empty()) DataBase::intArrays.push_back(new mx::Array<int>({1,2,4,4,5,5,5,5,5,5}));
   //DataBase::intArrays.back()->pushBack(1);


    IntArrayIndexView::render(hWnd, DataBase::intArrays);
  }

  static void newArray(HWND hWnd) {
    DataBase::intArrays.push_back(new mx::Array<int>);
    Base::redirectTo(IDC_INT_ARRAY);
  }

  static void pushBack(HWND hWnd) {
    //current_array->pushBack(1);
    Base::redirectTo(WM_HOME);
  }

  static void deleteArray(HWND hWnd, LPARAM pointer) {
   // current_array = (mx::Array<int>*)GetWindowLong(hWnd,);
    //a->pushBack(1);
    //CLIENTCREATESTRUCT *s; //declare pointer-to-struct variable
    auto s = (CLIENTCREATESTRUCT*)pointer;
    //auto a = GetWindowLong(hWnd, GWLP_HINSTANCE);
    Base::redirectTo(IDC_INT_ARRAY);
  }
};

mx::Array<int>* IntArrayController::current_array;