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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*res=new ListNode(0);
        res->next=head;
        ListNode*slow=res;
        ListNode*fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return res->next;
    }
};