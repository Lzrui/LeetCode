#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
 public:
  Node *prev;
  Node *next;
  T val;
  Node(T value) : val(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class NodeDoubleLinkedlist {
 private:
  Node<T> *head;
  Node<T> *tail;

 public:
  NodeDoubleLinkedlist() : head(nullptr), tail(nullptr) {}

  void AddNode(Node<T> *new_node) {
    if (new_node == nullptr)
      return;
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    }
    else {
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;
    }
  }

  void MoveNodeToTail(Node<T> *node) {
    if (node == tail)
      return;
    if (node == head) {
      head = head->next;
      head->prev = nullptr;
    }
    else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    tail->next = node;
    node->prev = tail;
    node->next = nullptr;
    tail = node;
  }

  Node<T> *RemoveHead() {
    if (head == nullptr)
      return nullptr;
    Node<T>* res = head;
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
    }
    else {
      head = res->next;
      head->prev = nullptr;
      res->next = nullptr;
    }
    return res;
  }
};

template <typename K, typename V>
class LRU_Cache {
 private:
  unordered_map<K, Node<V>*> KeyNodeMap;
  unordered_map<Node<V>*, K> NodeKeyMap;
  NodeDoubleLinkedlist<V> NodeList;
  unsigned int capacity;

  void RemoveMostUnusedCache() {
    Node<V>* res = NodeList.RemoveHead();
    K key = NodeKeyMap[res];
    NodeKeyMap.erase(res);
    KeyNodeMap.erase(key);
  }

 public:
  LRU_Cache(unsigned int k) : capacity(k) {}

  V get(K key) {
    try {
      if (KeyNodeMap.count(key)) {
        Node<V>* res = KeyNodeMap[key];
        NodeList.MoveNodeToTail(res);
        return res->val;
      }
      else throw runtime_error("No Found");
    }
    catch (runtime_error &err) {
      cout << err.what() << endl;
    }
    return 0;
  }

  void set(K key, V value) {
    if (KeyNodeMap.count(key)) {
      Node<V>* node = KeyNodeMap[key];
      node->val = value;
      NodeList.MoveNodeToTail(node);
    }
    else {
      auto *node = new Node<V>(value);
      KeyNodeMap[key] = node;
      NodeKeyMap[node] = key;
      NodeList.AddNode(node);
      if (KeyNodeMap.size() == capacity + 1)
        RemoveMostUnusedCache();
    }
  }
};

int main() {
  LRU_Cache<char,int> test(3);
  test.set('a',1);
  test.set('b',2);
  test.set('c',3);
  test.set('d',4);
  int val = test.get('b');
  val = test.get('a');
  val = test.get('c');
  return 0;
};

