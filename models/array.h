#pragma once
#include <algorithm>
#include <set>
#include <ostream>
#include <sstream>

namespace mx {
  template<class T>
  class Array {
  public:
    typedef Iterator<T> iterator;
    typedef Iterator<const T> const_iterator;
    Array() {};
    Array(const std::initializer_list<int>& list) {
      length = list.size();
      int count = 0;
      _array = new T[length];
      for (auto& element : list) {
        _array[count] = element;
        ++count;
      }
    }
    Array(const Array<T>& x) {
      length = 0;
      _array = new T[x.size()];

      for (auto elem : x) {
        this->pushBack(elem);
      }
    }

    Array(Array<T>&& x) {
      for (auto& elem : x) {
        this->pushBack(elem);
      }
      delete[] x._array;
    }
    ~Array() {
      clear();
    }

    Array<T>& operator=(Array<T>&& x) {
      if (&x == this) return *this;

      delete[] _array;
      length = 0;

      for (auto& elem : x) {
        this->pushBack(elem);
      }
      delete[] x._array;

      return *this;
    }

    Array<T>& operator=(const Array<T>& x) {
      if (&x == this) return *this;

      delete[] _array;
      length = 0;

      _array = new T[x.size()];
      for (auto& elem : x) {
        this->pushBack(elem);
      }
      return *this;
    }

    iterator begin() {
      if (length == 0) return iterator(nullptr);

      return iterator(&this->front());
    };

    const_iterator begin() const {
      if (length == 0) return const_iterator(nullptr);

      return const_iterator(&_array[0]);
    }

    iterator end() {
      if (length == 0) return iterator(nullptr);

      return iterator(&this->back() + 1);
    };

    const_iterator end() const {
      if (length == 0) return const_iterator(nullptr);

      return const_iterator(&_array[length]);
    }

    void unique() {
      auto last = std::unique(this->begin(), this->end());
      int d = this->end()._cur - last._cur;
      length -= d;
      T* temp = new T[length];
      for (int i = 0; i < length; i++) temp[i] = _array[i];
      delete[] _array;
      _array = temp;
    }

    void sort() {
      std::multiset<int> m;
      for (int i = 0; i < length; i++) {
        m.insert(_array[i]);
      }
      T* temp = _array;
      for (auto& e : m) {
        *temp = e;
        temp++;
      }

    }
    std::string toString() {
      std::ostringstream stream;
      for (auto& elem : *this) {
        stream << elem << ',';
      }
      std::string temp = stream.str();
      return std::string(temp.substr(0, temp.size() - 1));
    }
    template<class R>
    friend std::ostream& operator<<(std::ostream& out, const Array<R>& a);
    template<class R>
    friend bool operator==(const Array<R>& c1, const Array<R>& c2);
    template<class R>
    friend bool operator!=(const Array<R>& c1, const Array<R>& c2);
    template<class R>
    friend Array<R> operator+(const Array<R>& c1, const Array<R>& c2);
    Array<T> operator+=(const Array<T>& c1) {
      Array<T> temp = *this + c1;
      //    std::cout<<"sad"<<temp<<'\n';
      *this = temp;
      return Array<T>(*this);
    };

    T& operator[](const int index) const {
      if (index >= length) { throw "index more then length"; }
      return _array[index];
    };

    std::string getType() { return typeid(T).name(); }

    void pushBack(T elem) {
      auto* temp = new T[length + 1];
      for (int i = 0; i < length; i++) {
        temp[i] = _array[i];
      }
      temp[length] = elem;
      length++;
      delete[] _array;
      _array = temp;
    }

    void pushFront(T elem) {
      auto* temp = new T[length + 1];
      temp[0] = elem;
      for (int i = 0; i < length; i++) {
        temp[i + 1] = _array[i];
      }
      length++;
      delete[] _array;
      _array = temp;
    }

    void popBack() {
      if (isEmpty()) return;
      auto* temp = new T[length--];
      for (int i = 0; i < length; i++) {
        temp[i] = _array[i];
      }
      delete[] _array;
      _array = temp;
    }

    void popFront() {
      if (isEmpty()) return;
      auto* temp = new T[length--];
      for (int i = 0; i < length; i++) {
        temp[i] = _array[i + 1];
      }
      delete[]_array;
      _array = temp;
    }

    T& front() {
      if (isEmpty()) { throw "empty _array"; }
      return _array[0];
    }

    T& back() {
      if (isEmpty()) { throw "empty _array"; }
      return _array[length - 1];
    }

    bool isEmpty() const {
      return length == 0;
    }

    void clear() {
      if (isEmpty()) { return; }
      delete[] _array;
      length = 0;
    }

    int size() const { return length; }
  private:
    T* _array = nullptr;
    unsigned int length = 0;
  };
  template<class T>
  bool operator==(const Array<T>& c1, const Array<T>& c2) {
    if (c1.size() != c2.size()) return false;

    for (int i = 0; i < c1.size(); i++) if (c1[i] != c2[i]) return false;

    return true;
  }
  template<class T>
  bool operator!=(const Array<T>& c1, const Array<T>& c2) {

    return !(c1 == c2);
  }
  template<class T>
  std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
    for (auto& elem : a) {
      out << elem << ',';
    }
    out << '\b';
    return out;
  }
  template<class R>
  Array<R> operator+(const Array<R>& c1, const Array<R>& c2) {
    Array<R> temp;
    Array<R> min;
    if (c1.size() > c2.size()) {
      temp = c1;
      min = c2;
    }
    else {
      temp = c2;
      min = c1;
    }
    for (auto& elem : min) {
      temp.pushBack(elem);
    }

    return Array<R>(temp);
  }
}