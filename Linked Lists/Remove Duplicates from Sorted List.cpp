/*
InterviewBit : Remove Duplicates from Sorted List

Link : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/


Asked in:
Microsoft
VMWare

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    
    ListNode* trav = A;
    while(trav->next){
        // If next value is duplicate then remove it 
        if(trav->next->val == trav->val){
            ListNode* temp = trav->next;
            trav->next = trav->next->next;
            delete temp;            
        }
        // Otherwise go to next node
        else{
            trav=trav->next;
        }
    }
    return A;

}
