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
    ListNode* reverse( ListNode* head )
    {
        if ( head == nullptr || head -> next == nullptr )
            return head ;
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* front = nullptr ;
        while ( curr != nullptr )
        {
            front = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = front ;
        }
        return prev ;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        head = reverse ( head ) ;
        int carry = 0 ;
        int sum = 0 ;
        ListNode* ptr = head ;
        ListNode* newHead = new ListNode ( -1 ) ;
        ListNode* newTail = newHead ;
        while ( ptr != nullptr )
        {
            sum = 2 * ptr -> val + carry ;
            if ( sum > 9 )
            {
                newTail -> next = new ListNode ( sum % 10 ) ;
                newTail = newTail -> next ;
                ptr = ptr -> next ;
                carry = 1 ;
            }
            else
            {
                newTail -> next = new ListNode ( sum ) ;
                newTail = newTail -> next ;
                ptr = ptr -> next ;
                carry = 0 ;
            }
        }    
        if ( carry == 1 )
            newTail -> next = new ListNode ( carry ) ;
        return reverse ( newHead -> next ) ;
    }
};