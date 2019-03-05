/*
InterviewBit : Partition List

Link : https://www.interviewbit.com/problems/partition-list/


Asked in:
Microsoft


Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Adds the node to the list removing it from its original list
void addNodeToList(ListNode **list,ListNode **node){
    
    (*list)->next=(*node);
    (*list)=(*list)->next;
    (*node)=(*node)->next;
    (*list)->next = NULL;
}
ListNode* Solution::partition(ListNode* A, int B) {

    if(!A)return NULL;
    // Maintain 2 lists; one for storing lesser values and one for greater values
    ListNode *left = new ListNode(0),*leftStart = left;
    ListNode *right = new ListNode(0),*rightStart = right;
    ListNode* trav = A;

    while(trav){
        if(trav->val<B){
            // Add Node to Left List
            addNodeToList(&left,&trav);
        }
        else{
            // Add Node to Right List
            addNodeToList(&right,&trav);
        }
    }
    // No nodes in lesser list
    if(!leftStart->next)return rightStart->next;
    // No nodes in greater list
    if(!rightStart->next)return leftStart->next;
    left->next = rightStart->next;
    return leftStart->next;

}