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
ListNode* initialSolution(ListNode* A);
ListNode* newSolution(ListNode* A);

ListNode* Solution::insertionSortList(ListNode* A) {

    if(!A ||!A->next)return A;

    // return initialSolution(A);
    return newSolution(A);
}
// Lesser memory required
ListNode* newSolution(ListNode* A){
    ListNode* sorted = NULL;
    ListNode* list = A;
    ListNode* curr;
  
    // Traverse over the list
    while(list){
        //get first node; this node will be inserted in sorted list
        curr = list;

        // Detach this node from list
        list=list->next;
        curr->next=NULL;

        // Sorted list has not been created || this value is smaller than first node in sorted list
        if(!sorted || sorted->val > curr->val){
            curr->next = sorted;
            sorted = curr;
        }
        // Node will be inserted inside list
        else{
        
            // traversal pointer
            ListNode* s = sorted;
            // Traverse till correct insertion position is found
            while(s->next && s->next->val < curr->val) s=s->next;
            
            // Insert the node in the list
            ListNode* temp = s->next;
            s->next = curr;
            curr->next =temp;
        }
    }
    return sorted;
}
ListNode* initialSolution(ListNode* A){


    ListNode* ans = new ListNode(0);
    ListNode* trav = ans;

    while(A){
        int val = A->val;
        trav = ans;
        // Find correct insertion place in sorted list
        while(trav->next && val>trav->next->val){
            trav=trav->next;
        }
        // Copy the node in sorted list
        ListNode *temp = trav->next;
        trav->next  = new ListNode(val);
        trav = trav->next;
        trav->next = temp;
        A=A->next;
    }
    return ans->next;

}
