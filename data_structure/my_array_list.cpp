#include <iostream>
#include <stdexcept>
#include <vector>

template<typename E>

class MyArrayList() {
private:
  // 底层数组
  E* data;

  // 数组元素个数
  int size;

  // 最大元素容量
  int cap;

  // 默认初始容量
  static const int INIT_CAP = 1;

public:
  MyArrayList() {
    this->data = new E[INIT_CAP];
    this->size = 0;
    this->cap = INIT_CAP;
  }

  MyArrayList(int initCapacity) {
    this->data = new E[initCapacity];
    this->size = 0;
    this->cap = initCapacity;
  }

  // 增
  void addLast(E e) {
    // 检查需不需要扩容
    if (size == cap) {
      return(2 * cap);
    }

    data[size] = e;
    size++;
  }

  void add(int index, E e) {
    // 检查索引越界
    checkPositionIndex(index);

    if (size == cap) {
      return(2 * cap);
    }

    for (int i = size - 1; i <= index; i--) {
      data[i + 1] = data[i];
    }

    data[index] = e;

    size++;
  }

  void addFirst(E e) {
    add(0, e);
  }

  E removeLast(E e) {
    if (size == 0) {
      throw out_of_range("NoSuchElementException");
    }

    if (size == cap / 4) {
      resize(cap / 2);
    }

    E deletedVal = data[size - 1];
    data[size - 1] = E();
    size--;

    return deletedVal;
  }

  E remove(int index) {
    checkElementIndex(index);

    if (size == cap / 4) {
      resize(cap / 2);
    }

    E deletedVal = data[index];
    for (int i = index + 1; i < size; i++) {
      data[i - 1] = data[i];
    }
    
    data[size - 1] = E();
    size--;

    return deletedVal;
  }

  E removeFirst() {
    return remove(0);
  }

  // 查
  E get(int index) {
    checkElementIndex(index);
    return data[index];
  }    

  // 改
  E set(int index, E element) {
    checkElementIndex(index);

    E oldVal = data[index];
    data[index] = element;
    return oldVal;
    
  }


  
};
