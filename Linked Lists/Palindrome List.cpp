/*
InterviewBit : Palindrome List

Link : https://www.interviewbit.com/problems/palindrome-list/


Asked in:
Amazon
Microsoft

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    ListNode* fast = head, slow = head;
    while(fast && fast.next){
        fast = fast->next->next;
        slow = slow->next;
    }
    // Odd number of nodes; let right half smaller
    if(fast) slow = slow->next;
    
    // Now slow is halfway, make a split
    slow = reverse(slow);
    fast = head;

    // Compare that the 2 lists are equal
    while(slow){
        if(fast->val != slow->val) return 0;
        fast = fast->next;
        slow = slow->next;
    }
    return 1;
}

ListNode* reverse(ListNode head){
    ListNode* prev = NULL;
    while(head){
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}