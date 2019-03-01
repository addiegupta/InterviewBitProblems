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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

    int len =0;
    ListNode *trav = A;
    while(trav){
        len++;
        trav=trav->next;
    }
    if(B<=0)B=1;
    len -= B;
    if(len<0){
        len =0;
    }
    int count =0;
    trav = A;
    ListNode* prev = NULL;
    while(trav){
        if(len==count){
            if(!prev){
                ListNode* temp= trav;
                trav=trav->next;
                delete temp;
                return trav;
            }
            else{
                ListNode* temp = trav;
                prev->next = temp->next;
                delete temp;
                return A;
            }
        }
        count++;
        prev=trav;
        trav=trav->next;
    }
    return A;    
}