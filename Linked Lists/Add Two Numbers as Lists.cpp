/*
InterviewBit : Add Two Numbers as Lists

Link : https://www.interviewbit.com/problems/add-two-numbers-as-lists/


Asked in:
Microsoft
Amazon
Qualcomm
Facebook

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* newCompactSolution(ListNode* A,ListNode* B){

    // Get first sum and carry values
    int sum = A->val + B->val;
    int carry = sum/10;

    // Store sums in new Linked list
    ListNode* ans = new ListNode(sum%10);

    // Tail iterator to traverse the list
    ListNode* tail = ans;
    
    // Jump to second nodes
    A=A->next;
    B=B->next;
    
    // Loop while any list is not null or carry is present
    while(A || B || carry){

        // Create sum value for current values + carry
        sum = (A?A->val:0) + (B?B->val:0) + carry;
        // Obtain carry for next step
        carry = sum/10;

        // Create new value node and add to answer list
        ListNode* temp = new ListNode(sum%10);
        tail->next = temp;
        tail = temp;

        // Traverse
        if(A)A=A->next;
        if(B)B=B->next;
    }
    return ans;
}
// untidy solution but doesnt require extra space for most of the additions
ListNode* initialSolution(ListNode* A,ListNode *B){
    
    ListNode* trav1 = A;
    ListNode* trav2 = B;
    
    int sum =0,carry=0;
    // Store instance of previous node for adding new sum values once list A has ended
    ListNode* prevTrav1=NULL;

    // Loop while both lists have nodes
    while(trav1 && trav2){
        
        sum = trav1->val+trav2->val+carry;
    
        trav1->val = sum%10;
        carry = sum/10;
        
        prevTrav1 = trav1;
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    // Loop while only A has nodes
    while(trav1){
        
        sum=trav1->val + carry;
        
        trav1->val = sum%10;
        carry = sum/10;
        
        prevTrav1 = trav1;
        trav1 = trav1->next;
    }
    // Loop while only B has nodes
    while(trav2){
        sum=trav2->val + carry;
    
        prevTrav1->next = new ListNode(sum%10);
        carry = sum/10;
    
        prevTrav1= prevTrav1->next;
        trav2=trav2->next;
    }
    
    // Add last remaining carry value if any
    if(carry>0) prevTrav1->next  = new ListNode(carry);

    return A;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    if(!A)return B;
    if(!B)return A;

    // return initialSolution(A,B);
    return newCompactSolution(A,B);
}
