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

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    // TODO: Write your code here
    ListNode *fast = head, *slow = head;
    int cyc_len = 0;
    while(fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast) {
        cyc_len = countLength(slow);
        break;
      }
    }
    return findStart(cyc_len,head);
  }
 private:
  static int countLength(ListNode *slow) {
    ListNode *curr = slow;
    int cyc_len = 0;
    do {
      cyc_len++;
      curr = curr->next;
    }while(curr != slow);
    return cyc_len;
  }
  static ListNode *findStart(int len, ListNode *head) {
    if(len == 0) return nullptr;
    ListNode *ptr1 = head, *ptr2 = head;
    while(len > 0) {
      len--;
      ptr1 = ptr1->next;
    }
    while(ptr1 != ptr2){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    return ptr1;
  }
};