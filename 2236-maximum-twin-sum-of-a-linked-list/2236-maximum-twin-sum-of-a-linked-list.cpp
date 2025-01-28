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
// 0 1 2 3 4 5
class Solution {
public:
    ListNode* reversell(ListNode*headd){
        ListNode*prev=nullptr;
        ListNode*curr=headd;
        while(curr!=nullptr){
            ListNode*aageka=curr->next;
            curr->next=prev;
            prev=curr;
            curr=aageka;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=reversell(slow->next);
        slow->next=temp;   
        long long int res=INT_MIN;
        while(temp!=nullptr){
            long long int tp=(head->val)+(temp->val);
            res=max(res,tp);
            head=head->next;
            temp=temp->next;
        }
        return res;
    }
};