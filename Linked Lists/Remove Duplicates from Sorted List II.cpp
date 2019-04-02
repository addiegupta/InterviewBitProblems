/*
InterviewBit : Remove Duplicates from Sorted List II

Link : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/


Asked in:
Microsoft
VMWare


Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    if(!A)return NULL;

    // Add a dummy node before head to handle base cases
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    
    // Traversal pointer
    ListNode* trav = dummy;
    
    // Duplicate value
    int dup;
    
    // Traverse through list
    while(trav && trav->next && trav->next->next){
        
        // Found repeated values
        if(trav->next->val == trav->next->next->val){
            
            // Save int value in variable
            dup = trav->next->val;

            // Remove nodes while duplicate value is found
            while(trav->next && trav->next->val==dup){
                ListNode* temp = trav->next;
                trav->next=trav->next->next;
                delete temp;
            }
        }
        // No repeated values, increase traversal pointer
        else{
            trav=trav->next;
        }
    }

    // Return head of original list
    return dummy->next;
}
