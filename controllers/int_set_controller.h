#pragma once
#include <string>
class IntSetController {
private:
  //static std::vector<mx::Array<int>*> intArrays;
  static  mx::Set<int>* current_set;
public:
  static void index(HWND hWnd) {//IDC_INT_ARRAY
    IntSetIndexView::render(hWnd, DataBase::intSets);
  }
  static void newSet(HWND hWnd) {
    DataBase::intSets.push_back(new mx::Set<int>);
    Base::redirectTo(IDC_INT_SET);
  }

  static void deleteSet(HWND hWnd, int param) {
    DataBase::intSets.erase(DataBase::intSets.begin() + param);
    Base::redirectTo(IDC_INT_SET);
  }

  static void show(HWND hWnd) {
    IntSetShowView::render(hWnd, current_set);
  }

  static void editSet(HWND hWnd, int param) {
    current_set = DataBase::intSets[param];
    Base::redirectTo(IDC_INT_SHOW_SET);
  }

  static void insert(HWND hWnd) {
    int nRetVal = GetDlgItemInt(hWnd, EDIT_FIRST, 0, 0);
    current_set->insert(nRetVal);
    Base::redirectTo(IDC_INT_SHOW_SET);
  }

  static void plus(HWND hWnd) {
    mx::Set<int>* temp = new mx::Set<int>;
    mx::Array<int> ids;
    for (int i = 0; i < DataBase::intSets.size(); i++) {
      if (IsDlgButtonChecked(hWnd, i * 1000 + IDC_CH_BOX)) {
        ids.pushBack(i);
        //*temp *= *DataBase::intSets[i];
      }
    }
    if (ids.size() == 0) {
      Base::redirectTo(IDC_INT_SET);
      return;
    }
    *temp = *DataBase::intSets[ids.front()];
    ids.popFront();
    for (auto& elem : ids) {
      *temp += *DataBase::intSets[elem];
    }
    DataBase::intSets.push_back(temp);
    Base::redirectTo(IDC_INT_SET);
  }

  static void mul(HWND hWnd) {
    mx::Set<int>* temp = new mx::Set<int>;
    mx::Array<int> ids;
    for (int i = 0; i < DataBase::intSets.size(); i++) {
      if (IsDlgButtonChecked(hWnd, i * 1000 + IDC_CH_BOX)) {
        ids.pushBack(i);
        //*temp *= *DataBase::intSets[i];
      }
    }
    if (ids.size() == 0) {
      Base::redirectTo(IDC_INT_SET);
      return;
    }
    *temp = *DataBase::intSets[ids.front()];
    ids.popFront();
    for (auto& elem : ids) {
      *temp *= *DataBase::intSets[elem];
    }
    DataBase::intSets.push_back(temp);
    Base::redirectTo(IDC_INT_SET);
  }

  static void del(HWND hWnd) {
    mx::Set<int>* temp = new mx::Set<int>;
    mx::Array<int> ids;
    for (int i = 0; i < DataBase::intSets.size(); i++) {
      if (IsDlgButtonChecked(hWnd, i * 1000 + IDC_CH_BOX)) {
        ids.pushBack(i);
        //*temp *= *DataBase::intSets[i];
      }
    }
    if (ids.size() == 0) {
      Base::redirectTo(IDC_INT_SET);
      return;
    }
    *temp = *DataBase::intSets[ids.front()];
    ids.popFront();
    for (auto& elem : ids) {
      *temp /= *DataBase::intSets[elem];
    }
    DataBase::intSets.push_back(temp);
    Base::redirectTo(IDC_INT_SET);
  }
};

mx::Set<int>* IntSetController::current_set;