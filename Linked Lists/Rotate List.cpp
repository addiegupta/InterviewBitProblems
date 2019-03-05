/*
InterviewBit : Rotate List

Link : https://www.interviewbit.com/problems/rotate-list/


Asked in:
Amazon

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {

    if(B<=0 || !A || !A->next)return A;

    ListNode *trav1 = A,*trav2 = A;
    int k = B,len=0;                            
    
    /**************************************
     Why does the while(k-- && trav2) loop exist twice at 1 and 2?
    
     A: If the value of B is less than length of list
     then the traversal needs to be carried out only for B nodes
     and not for entire list
     Hence saving the unnecessary traversal of the last (n-B) nodes where n is length of list
     
     If B is greater than length of list, then one loop counts the length
     and the other loop is then necessary to find the point of rotation
    
     Hence by creating 2 loops, some execution is saved in cases where B<n
     and no additional steps are created for the B>n case
    
    *****/

    // Traverse the pointer trav2 by k nodes
    while(k-- && trav2)trav2=trav2->next,len++; // While Loop 1
    // If k>0 => the rotation value is greater than length of list
    // We obtain k = B%length of list
    if(k>0){
        k=B%len;
        if(k<=0)return A;
        trav2 = A;
        while(k-- && trav2)trav2=trav2->next; // While Loop 2
    }
    // Now trav2 is at k nodes 
    // starting trav1 from head and moving both
    // by the time trav2 reaches end 
    // trav1 is at node at which rotation needs to take place
    while(trav1 && trav2->next){
        trav1=trav1->next;
        trav2=trav2->next;
    }

    // Head of rotated list which is to be returned
    ListNode* newHead = trav1->next;

    // Disconnect previous nodes from this point
    trav1->next =NULL;
    // Connect end of original list to start of original list
    trav2->next =A;
    return newHead;
}
