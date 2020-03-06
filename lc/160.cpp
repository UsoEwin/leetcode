//lc 160
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr_a = headA, *ptr_b = headB;
        while(ptr_a != ptr_b) {
            ptr_a = ptr_a == nullptr ? headB : ptr_a->next;
            ptr_b = ptr_b == nullptr ? headA : ptr_b->next;
        }
        return ptr_a;
    }
};