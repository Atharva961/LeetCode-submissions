/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head; 
        ListNode * ptr = head, *prev = new ListNode(-1);
        ListNode * ans = new ListNode(ptr->next->val);
        while(ptr && ptr->next)
        {
            ListNode * temp = ptr->next;
            ptr->next = ptr->next->next;
            prev->next = temp;
            temp->next = ptr;
            prev = ptr;
            ptr = ptr->next;
            // printf("prev: %d, ptr: %d, temp: %d\n", prev->val, ptr->val, temp->val);
        }
        ans->next = head;
        return ans;
    }
};