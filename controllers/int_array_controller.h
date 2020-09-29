#pragma once
class IntArrayController {
private:
  static  mx::Array<int>* current_array;
public:
  static void index(HWND hWnd ) {
  
    //if (DataBase::intArrays.empty()) DataBase::intArrays.push_back(new mx::Array<int>);
   // DataBase::intArrays.back()->pushBack(1);


    IntArrayIndexView::render(hWnd, DataBase::intArrays);
  }

  static void pushBack(HWND hWnd) {
    //current_array->pushBack(1);
    Base::redirectTo(WM_HOME);
  }
};

mx::Array<int>* IntArrayController::current_array;