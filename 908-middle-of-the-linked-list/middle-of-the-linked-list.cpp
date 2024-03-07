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
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
       int size=len;
       int half=len/2;
       while(head){
           if((size%2==0 && len==half) || (size%2!=0 && len-1==half)){
              break;
           }
           head=head->next;
           len--;
       }
       return head;
    }
};