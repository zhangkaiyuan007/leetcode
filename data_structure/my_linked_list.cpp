// 双链表api实现
#include <iostream>
#include <string>
#include <stdexcept>


template<typename E>
class MyLinkedList {
  struct Node {
    E val;
    Node* next;
    Node* prev;

    Node(E value) : val(value), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  int size;

public:
  // 初始化链表，虚拟头尾
  MyLinkedList() {
    head = new Node(E());
    tail = new Node(E());
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  ~MyLinkedList() {
    while (size > 0) {
      removeFirst();
    }
    delete head;
    delete tail;
  }

  // 增
  void addLast(E e) {
    Node* x = new Node(e);
    Node* temp = tail->prev;

    temp->next = x;
    x->prev = temp;

    x->next = tail;
    tail->prev = x;

    size++;
  }

  void addFirst(E e) {
    Node* x = new Node(e);
    Node* temp = head->next;

    temp->prev = x;
    x->next = temp;

    head->next = x;
    x->prev = head;

    size++;
  }

  void add(int index, E element) {
    checkPositionIndex(index);
    if (index == size) {
      addLast(element);
      return;
    }

    Node* p = getNode(index);
    Node* temp = p->prev;

    Node* x = new Node(element);

    p->prev = x;
    temp->next = x;

    x->prev = temp;
    x->next = p;

    size++;
  }

  // 删
  E removeFirst() {
    if (size < 1) {
      throw out_of_range("No element to remove");
    }

    Node* x = head->next;
    Node* temp = x->next;

    head->next = temp;
    temp->prev = head;

    E val = x->val;
    x->next = nullptr;
    x->prev = nullptr;
    delete x;

    size--;
    return val;
  }

  E removeLast() {
    if (size < 1) {
      throw std::out_of_range("No element to remove");
    }

    Node* x = tail->prev;
    Node* temp = x->prev;

    tail->prev = temp;
    temp->next = tail;

    E val = x->val;
    x->next = nullptr;
    x->prev = nullptr;
    delete x;

    size--;
    return val;
  }

  E remove(int index) {
    checkElementIndex(index);
    Node* x = getNode(index);
    Node* prev = x->prev;
    Node* next = x->next;

    next = prev->next;
    prev = next->prev;

    E val = x->val;
    x->prev = nullptr;
    x->next = nullptr;

    size--;
    return val;
  }

  // 查
  E get(int index) {
    checkElementIndex(index);
    Node* p = getNode(index);
    E val = p->val;
    return val;
  }

  E getFirst() {
    if (size < 1) {
      throw std::out_of_range("No element in the list");
    }

    return head->next->val;
  }

  E getLast() {
    if (size < 1) {
      throw std::out_of_range("No element in the list");
    }

    return tail->prev->val;
  }

  // 改
  E set(int index, E val) {
    checkElementIndex(index);
    Node* p = getNode(index);
    E oldVal = p->val;
    p->val = val;
    return oldVal;
  }

  int getSize() const {
    return size;
  }

  bool isEmpty() const {
    return size == 0;
  }

  void display() {
    std::cout << "size: " << size << std::endl;
    for (Node* p = head->next; p != tail; p = p->next) {
      std::cout << p->val << std::endl;
    }

    std::cout << "nullptr" << std::endl;
    std::cout << std::endl;
  }

private:
  Node* getNode(int index) {
    checkElementIndex(index);
    Node* p = head->next;
    for (int i = 0; i < index; i++) {
      p = p->next;
    }
    return p;
  }

  bool isElementIndex(int index) const {
    return index >= 0 && index < size;
  }

  bool isPositionIndex(int index) const {
    return index >= 0 && index <= size;
  }

  void checkElementIndex(int index) const {
    if (!isElementIndex(index)) {
      throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }
  }

  void checkPositionIndex(int index) const {
    if (!isPositionIndex(index)) {
      throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }
  }
};


int main() {
  MyLinkedList<int> list;
  return 0;
}
