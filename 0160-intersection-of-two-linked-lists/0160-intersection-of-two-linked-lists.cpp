/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a=0,len_b=0;
        ListNode*temp=headA;
        while(temp!=nullptr){
            len_a++;
            temp=temp->next;
        }
        ListNode*temp1=headB;
        while(temp1!=nullptr){
            len_b++;
            temp1=temp1->next;
        }
        ListNode*strA=headA;
        ListNode*strB=headB;
        int diff=abs(len_a-len_b);
        if(len_a>len_b){
            while(diff>0){
                strA=strA->next;
                diff--;
            }
        }
        else{
            while(diff>0){
                strB=strB->next;
                diff--;
            }
        }
        //check for similar val after moving A and B at same location
        while(strA!=NULL && strB!=NULL){
            if(strA==strB){
                return strA;
            }
            strA=strA->next;
            strB=strB->next;
        }
        return NULL;
    }
};