//very typicall
class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    // TODO: Write your code here
    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};