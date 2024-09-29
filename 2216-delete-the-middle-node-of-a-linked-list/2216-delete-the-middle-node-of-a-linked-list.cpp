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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return nullptr;
        }
        else{
            ListNode*s=head;
            ListNode*f=head;
            while(f!=NULL&&f->next!=NULL){
                s=s->next;
                f=f->next->next;
            }
            //ListNode*u=s;
            ListNode*temp=head;
            while(temp->next!=s){
                temp=temp->next;
            }
            temp->next=s->next;
            delete s;
            return head;
        }
    }
};