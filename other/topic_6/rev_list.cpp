class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    // TODO: Write your code here
    if(!head || !head->next)
      return head;
    ListNode *curr = head, *next = nullptr, *prev = nullptr;
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};