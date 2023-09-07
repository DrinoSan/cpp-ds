#include <cstddef>
#include <iostream>

class Node {

private:
  int32_t data;
  Node *next = nullptr;

public:
  Node(int32_t data) : data{data} {}

  void insertNodeAtEnd(int32_t data) {
    auto *currNode = this;

    while (true) {
      if (currNode->next == nullptr) {
        // Found end of linked list
        Node *newNode = new Node(data);
        currNode->next = newNode;
        return;
      }

      currNode = currNode->next;
    }
  }

  Node *insertNodeAtHead(int32_t data) {
    Node *node = new Node(data);
    node->next = this;

    return node;
  }

  static Node *deleteNode(Node *head, int32_t data) {
    if (head->data == data) {
      Node *newHead = head->next;
      delete head;
      return newHead;
    }

    Node *currNode = head;
    Node *nextNode = head->next;

    while (nextNode->next != nullptr) {
      if (nextNode->data == data) {
        currNode->next = nextNode->next;
        delete nextNode;
        return nullptr;
      }

      currNode = nextNode;
      nextNode = nextNode->next;
    }

    return nullptr;
  }

  bool searchNode(Node *node);

  bool isEmpty() {
    if (this->next == nullptr)
      return true;
    return false;
  }

  int32_t getSize() {
    if (this->next == nullptr)
      return 1;

    int32_t len{1};
    auto *node = this;

    while (node->next != nullptr) {
      len++;
      node = node->next;
    }

    return len;
  }

  void showList()
  {
    Node* currNode = this;
    int32_t index{0};
    while( currNode->next != nullptr )
    {
        std::cout << " -- N(" << index++ << ") Val(" << currNode->data << ") -- " << std::endl;
        currNode = currNode->next;
    }
    std::cout << " -- N(" << index++ << ") Val(" << currNode->data << ") -- " << std::endl;

  }
};

int main() {

  Node *head = new Node(0);

  head->insertNodeAtEnd(1);
  head->insertNodeAtEnd(2);
  head->insertNodeAtEnd(3);
  head = head->insertNodeAtHead(5);
  Node* res = Node::deleteNode(head, 2);
  if( res != nullptr)
    head = res;

  head->showList();
  std::cout << "Size: " << head->getSize() << std::endl;

  return 0;
}