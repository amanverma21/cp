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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode* tmp = list1, *tmp2 = list2;
        while(b--) tmp = tmp->next;
        while(tmp2->next) tmp2 = tmp2->next;
        tmp2->next = tmp->next;

        a--;
        tmp = list1;
        while(a--) tmp = tmp->next;

        tmp->next = list2;
        return list1;
    }
};