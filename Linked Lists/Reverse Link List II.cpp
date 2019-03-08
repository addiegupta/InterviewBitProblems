/*
InterviewBit : Reverse Link List II

Link : https://www.interviewbit.com/problems/reverse-link-list-ii/


Asked in:
Microsoft
Amazon
Facebook

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

    // Single node to be reversed, no changes required
    if(B==C)return A;
    
    // Insert dummy node so that corner cases do not need to be handled
    ListNode *dummy = new ListNode(0), *trav = dummy;
    dummy->next = A;

    // Number of nodes to be reversed
    C = C - B+1;

    // Decrement so that first B-1 nodes are skipped
    B--;
    while(B--) trav=trav->next;
    
    // Set next node as head and tail of sublist which is to be reversed
    ListNode* revHead = trav->next;
    ListNode* revTail = trav->next;

    // Stores the remaining next list
    ListNode* tempList=NULL;

    // Reverse nodes
    while(C--){
        
        // Store the list after node to be reversed
        tempList = trav->next->next;

        // Add next node to reverse list as its head
        trav->next->next = revHead;
        revHead = trav->next;
        
        // Remove reversed node from this list
        trav->next = tempList;
    }

    //Connect the reversed sublist to main list
    tempList = trav->next;
    trav->next = revHead;
    revTail->next = tempList;

    // Return head of new list
    return dummy->next;
}