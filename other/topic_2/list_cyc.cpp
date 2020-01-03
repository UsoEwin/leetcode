using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycle {
 public:
  static bool hasCycle(ListNode *head) {
    // TODO: Write your code here
    ListNode *slow = head, *fast = head;
    //only need to check fast since it will hit end first
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next;
      fast = fast->next;
      if(slow == fast)
        return true;
    }
    return false;
  }
};