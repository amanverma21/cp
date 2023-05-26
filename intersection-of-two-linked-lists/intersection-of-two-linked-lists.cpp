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

    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        ListNode* a=ha;
        ListNode* b=hb;
        int lena=0,lenb=0;
        while(a){
            lena++;
            a=a->next;
        }
        while(b){
            lenb++;
            b=b->next;
        }
        int diff=abs(lena-lenb);
        if(lena>lenb){
            while(lena>lenb){
                ha=ha->next;
                lena--;
            }
        }
        else if(lenb>lena){
            while(lenb>lena){
                hb=hb->next;
                lenb--;
            }
        }
        while(ha&&hb){
            if(ha==hb) return ha;
            ha=ha->next;
            hb=hb->next;
        }
        return NULL;
    }
};