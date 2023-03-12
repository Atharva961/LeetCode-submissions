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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans = new ListNode(-1);
        ListNode * tail = ans;
        
        while(true)
        {
            int minn = INT_MAX, mini = -1;
            int null_count = 0;
            for(int i=0; i<lists.size(); i++)
            {
                if(!lists[i])null_count++;
                else if(lists[i]->val<minn)
                {
                    minn = lists[i]->val;
                    mini = i;
                }
            }
            if(null_count==lists.size())break;
            ListNode * temp = new ListNode(minn);
            tail->next = temp;
            tail = tail->next;
            lists[mini] = lists[mini]->next;
        }
        ans = ans->next;
        return ans;

    }
};