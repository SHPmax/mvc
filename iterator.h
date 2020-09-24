#pragma once
#include <iterator>
namespace mx {
  template<typename ValueType>
  class Array;

  template<typename ValueType>
  class Iterator : public std::iterator<std::forward_iterator_tag, ValueType> {
    friend class Array<ValueType>;
  public:
    explicit Iterator(ValueType* cur) : _cur(cur) {};
  public:
    Iterator(const Iterator<ValueType>& it) : _cur(it._cur) {};

    bool operator!=(Iterator<ValueType> const& other) const {
      return _cur != other._cur;
    };
    bool operator==(Iterator<ValueType> const& other) const {
      return _cur == other._cur;
    };
    bool operator<(Iterator<ValueType> const& other) const {
      return *_cur < *other._cur;
    };
    typename Iterator<ValueType>::reference operator*() const {
      return *_cur;
    };
    Iterator<ValueType>& operator++() {
      ++_cur;
      return *this;
    };

  private:
    ValueType* _cur;
  };
}
