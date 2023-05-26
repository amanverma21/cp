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
    // ListNode* temp;
    bool isPalindrome(ListNode* head) {
         ListNode* temp = head;
        
        stack<int> s;
        
        while (temp) {
            s.push(temp -> val);
            temp = temp -> next;
        }
        
        while (s.size() / 2) {
            if (s.top() != head -> val) {
                return false;
            }
            head = head -> next;
            s.pop();
        }
        return true;
    }
    
    
};