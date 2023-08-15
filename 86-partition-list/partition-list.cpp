
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_head = new ListNode(0);
        ListNode* small = small_head;
        ListNode* higher_head = new ListNode(0);
        ListNode* higher = higher_head;

        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                higher->next = head;
                higher = higher->next;
            }
            head = head->next;
        }
        
        higher->next = nullptr;
        small->next = higher_head->next;
        
        return small_head->next;
    }
};
