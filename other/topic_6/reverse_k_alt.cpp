class ReverseAlternatingKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    if(head == nullptr || k <= 1)
      return head;
    ListNode *curr = head, *prev = nullptr;
    while(true) {
      ListNode *last_of_prev_list = prev, *last_of_curr_list = curr, *next = nullptr;
      for(int i = 0; i < k && curr != nullptr; ++i) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      if(last_of_prev_list == nullptr) 
        head = prev;
      else
        last_of_prev_list->next = prev;
      last_of_curr_list->next = curr;
      for(int i = 0; i < k && curr != nullptr; ++i) {
        prev = curr;
        curr = curr->next;
      }
      if(curr == nullptr)
        break;
    }
    return head;
  }
};