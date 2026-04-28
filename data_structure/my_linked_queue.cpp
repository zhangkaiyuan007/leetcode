#include <list>
#include <iostream>

template <typename E>
class MyLinkedQueue {
private:
  std::list<E> list;

public:
  void push(const E &e) {
    list.push_back(e);
  }

  E pop() {
    E value = list.front();
    list.pop_front();
    return value;
  }

  E peek() {
    return list.front();
  }

  int size() {
    return list.size();
  }
};

int main() {
  MyLinkedQueue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);

  std::cout << queue.peek() << std::endl;
  return 0;

}
