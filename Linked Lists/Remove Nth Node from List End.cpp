/*
InterviewBit : Remove Nth Node from List End

Link : https://www.interviewbit.com/problems/remove-nth-node-from-list-end/


Asked in:
HCL
Amazon

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// This approach takes 2 traversals through the linked list
// First traversal calculates length of linked list
// Then position of nth node from end is calculated from start
// Then this node is found by traversal and then removed
ListNode* findLengthFirstAndThenRemoveNodeApproach(ListNode* A,int B){
    
    // Find length of list
    ListNode *trav = A;
    int len =0;
    while(trav){
        len++;
        trav=trav->next;
    }

    // N is non positive:  corner case
    if(B<=0)B=1;
    // Position of node from start
    len -= B;

    // B is greater than len, then remove first node
    if(len<=0){
        ListNode *temp = A;
        A=A->next;
        delete temp;
        return A;
    }
    int count =0;
    trav = A;
    ListNode* prev = NULL;

    // Traverse
    while(trav){
        // Found node to be removed
        if(len==count){
            ListNode* temp = trav;
            prev->next = temp->next;
            delete temp;
            return A;
        }
        // Increase count of nodes and continue traversal
        count++;
        prev=trav;
        trav=trav->next;
    }
    return A;
}
// A pointer is started from head and run till n places
// Then another pointer is started from head and both are increased
// When first pointer reaches end of list, then required node is found
ListNode* runFirstPointerNPlacesAndThenStartSecondPointerApproach(ListNode* A,int B){
    
    ListNode *trav1=A,*trav2=A;
    // Traverse till end of list or till B nodes whichever comes first
    while(B-- && trav1){
        trav1=trav1->next;
    }
    ListNode* prev = NULL;
    // Start second pointer
    while(trav1){
        prev = trav2;
        trav2=trav2->next;
        trav1=trav1->next;
    }
    // Node to be removed
    ListNode* temp = trav2;
    // prev is null if first node is to be removed
    (!prev) ? A=A->next : prev->next = prev->next->next;
    delete temp;
    return A;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

    if(!A)return A;
    // return findLengthFirstAndThenRemoveNodeApproach(A,B);
    return runFirstPointerNPlacesAndThenStartSecondPointerApproach(A,B);
        
}