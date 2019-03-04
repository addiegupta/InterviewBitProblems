/*
InterviewBit : Swap List Nodes in pairs

Link : https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/


Asked in:
Microsoft
Amazon


Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// First submitted code; slightly untidy
ListNode* initialSolution(ListNode* A){
   
    ListNode* prevChain=NULL;
    ListNode* temp1=A;
    ListNode* temp2 = temp1->next;
    while(temp1 && temp2){
        if(prevChain)   prevChain->next = temp2;
        else  A = temp2;
        
        // Swap
        temp1->next = temp2->next;
        temp2->next = temp1;
        
        // Initialisation for next iteration
        prevChain = temp1;
        temp1 = temp1->next;
        
        if(!temp1)break;
        temp2 = temp1->next; 
    }
    return A;
}
// Helper function which swaps node A and B and returns pointer to B
ListNode* utilSwapNodes(ListNode* A,ListNode* B){

    // Link Node A to chain after B
    A->next = B->next;
    // Link B to A
    B->next = A;
    // Return B pointer
    return B;
}
// New cleaner code which basically does same operation as initial code
ListNode* newCleanerCodeSolution(ListNode* A){
    
    // This removes the need to treat head as a special case
    ListNode* start = new ListNode(0);
    start->next = A;

    ListNode * trav = start;
    
    // Traverse while 2 nodes exist in front i.e. a need to swap exists
    while(trav->next && trav->next->next){
        // swap nodes and connect to previous chain
        trav->next = utilSwapNodes(trav->next,trav->next->next);
        // Skip these 2 nodes
        trav = trav->next->next;
    }
    // Start is a self created useless node; return its next which is where list starts
    return start->next;

}


ListNode* Solution::swapPairs(ListNode* A) {

    // return initialSolution(A);
    return newCleanerCodeSolution(A);

}
