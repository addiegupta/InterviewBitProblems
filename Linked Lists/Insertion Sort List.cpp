/*
InterviewBit : Insertion Sort List

Link : https://www.interviewbit.com/problems/insertion-sort-list/


Asked in:
Microsoft
Google

Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {

    if(!A ||!A->next)return A;

    ListNode* ans = new ListNode(0);
    // ListNode* trav = A;
    ListNode* trav = ans;
    while(A){
        int val = A->val;
        trav = ans;
        while(trav->next && val>trav->next->val){
            trav=trav->next;
        }
        ListNode *temp = trav->next;
        trav->next  = new ListNode(val);
        trav = trav->next;
        trav->next = temp;
        A=A->next;
    }
    return ans->next;

}
