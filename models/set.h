#pragma once
#include <algorithm>
namespace mx {
  template<class T>
  class Set {
  public:
    typedef mx::Iterator<T> iterator;
    typedef mx::Iterator<const T> const_iterator;

    iterator begin() {
      return _array.begin();
    };

    const_iterator begin() const {
      return _array.begin();
    }

    iterator end() {
      return _array.end();
    };

    const_iterator end() const {
      return _array.end();

    }
    template<class R>
    friend Set<R> operator+(const Set<R>& d1, const Set<R>& d2);
    //  ~Set() { clear(); }
    Set() {};
    Set(const mx::Array<T>& a) : _array(a) { uniqSort(); }
    Set(const std::initializer_list<int>& list) : _array(list) { uniqSort(); };
    Set(const Set& x) : _array(x._array) {};

    Set(Set&& x) : _array(x._array) {
      x.clear();
    }

    Set& operator=(Set&& x) {
      if (&x == this) return *this;

      _array = x._array;  

      x.clear();

      return *this;
    }

    Set& operator=(const Set& x) {
      if (&x == this) return *this;

      _array = x._array;

      return *this;
    }

    T& operator[](const int index) { return _array[index]; };

    friend bool operator==(const Set& c1, const Set& c2);
    friend bool operator!=(const Set& c1, const Set& c2);
    template<class R>
    friend Set<R> operator*(const Set<R>& c1, const Set<R>& c2);
    template<class R>
    friend Set<R> operator/(const Set<R>& c1, const Set<R>& c2);
    template<class R>
    friend std::ostream& operator<<(std::ostream& out, const Set<R>& a);

    Set operator/=(const Set& c1) {
      *this = *this / c1;
      return Set(*this);
    }
    Set operator*=(const Set& c1) {
      *this = *this * c1;
      return Set(*this);
    };
    Set operator+=(const Set& c1) {
      this->_array += c1._array;
      this->uniqSort();
      return Set(*this);
    };

    void swap(Set<T>& set) { std::swap(this, set); }

    int size() { return _array.size(); }
    void clear() { _array.clear(); }

    bool isEmpty() { return _array.isEmpty(); }
    std::string toString() {
      return _array.toString();
    }
    void insert(T &elem) {
      _array.pushBack(elem);
      uniqSort();
    }
  private:
    void uniqSort() {
      _array.sort();
      _array.unique();

    }
    mx::Array<T> _array;
  };
  template<class T>
  bool operator==(const Set<T>& c1, const Set<T>& c2) {
    return c1._array == c2._array;
  }
  template<class T>
  bool operator!=(const Set<T>& c1, const Set<T>& c2) {
    return !(c1 == c2);
  }
  template<class R>
  Set<R> operator+(const Set<R>& c1, const Set<R>& c2) {
    mx::Array<R> temp = c1._array + c2._array;
    //  std::cout<<'s'<<c1._array<<'s';
    return Set<R>(temp);
  }
  template<class R>
  std::ostream& operator<<(std::ostream& out, const Set<R>& a) {
    out << a._array;
    return out;
  }
  template<class R>
  Set<R> operator*(const Set<R>& c1, const Set<R>& c2) {
    mx::Array<R> temp;
    for (auto& elem : c1) {
      //    std::cout<<elem<<".";
      if (std::find(c2.begin(), c2.end(), elem) != c2.end()) {
        temp.pushBack(elem);
      }
    }
    return Set<R>(temp);
  }
  template<class R>
  Set<R> operator/(const Set<R>& c1, const Set<R>& c2) {
    mx::Array<R> temp;
    for (auto& elem : c1) {
      //    std::cout<<elem<<".";
      if (std::find(c2.begin(), c2.end(), elem) == c2.end()) {
        temp.pushBack(elem);
      }
    }
    return Set<R>(temp);
  }
}
