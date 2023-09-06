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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr=head;
        while(curr!=nullptr){
            len++;
            curr=curr->next;
        }
        int parts = len / k;
        int extr_part = len % k;
        vector<ListNode*> ans(k, nullptr);
        curr=head;
        ListNode* prev = nullptr;
        for(int i=0;i<k && curr!=nullptr;i++){
            ans[i] = curr;
            int part_length = parts + (i < extr_part ? 1 : 0);
            for(int j=0;j<part_length;j++){
                prev = curr;
                curr = curr->next;
            }
            if(prev!=nullptr){
                prev->next = nullptr;
            }
        } 
        return ans;
    }
};