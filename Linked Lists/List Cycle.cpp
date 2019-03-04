/*
InterviewBit : List Cycle

Link : https://www.interviewbit.com/problems/list-cycle/


Asked in:
Microsoft
Amazon
NetApp

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 



*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*********************************
    Very well explained and simple solution for this problem

    https://cs.stackexchange.com/questions/10360/floyds-cycle-detection-algorithm-determining-the-starting-point-of-cycle
    
        <--x-----><-y-><-------z-
        1->2->3->4->5->6->7->8->9|
                   ^           ||
                   |           ||                   Node value 6 is meeting point                                                        
                    ------------|         
                   <----z--------     

        Distance travelled by slow pointer is x + y
        Distance travelled by fast pointer is x + y + z +y

        As time is constant for both

        => Distance travelled by fast  = 2 * Distance travelled by slow
                            x + 2y + z = 2*(x +y)
                                     z = x
        Therefore setting slow pointer to head and then continuing fast from meeting point
        and slow from head one node at a time, the node at which they meet again will be the starting node

*/              
// 2 methods to find cycle start; the first one uses the above explained algorithm                                             
ListNode* findCycleStartUsingTrivialDistanceMath(ListNode* A,ListNode* slow,ListNode* fast);                                   
ListNode* findCycleStartUsingCycleLengthMethod(ListNode* A,ListNode* slow,ListNode* fast);

ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A->next)return NULL;

    // Detect presence of Cycle using Floyds algorithm
    // Run two pointers starting from head; one jumps one node at a time while other jumps 2
    // If any pointer reaches NULL, then there is no cycle
    ListNode* slow=A;
    ListNode* fast = A;
    while(slow && fast){
        slow=slow->next;
        if(!fast->next)return NULL;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(!slow || !fast )return NULL;
    
    // Now find the starting point of the cycle    
    return findCycleStartUsingTrivialDistanceMath(A,slow,fast);
    // return findCycleStartUsingCycleLengthMethod(A,slow,fast);
    
}
                             
ListNode* findCycleStartUsingTrivialDistanceMath(ListNode* A,ListNode* slow,ListNode* fast){

    // Explanation is given at top
    slow = A;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }  
    return slow;
}
// This method is similar 
// First the length of the cycle (say k) is calculated by a round traversal
// then one pointer is moved by k nodes
// then other pointer is started from head and both are moved together
// their meeting point gives the cycle start
ListNode* findCycleStartUsingCycleLengthMethod(ListNode* A,ListNode* slow,ListNode* fast){                                   

    int cycleLen = 1;
    fast=fast->next;
    while(slow!=fast){
        fast=fast->next;
        cycleLen++;
    }
    
    slow = A;
    fast = A;
    while(cycleLen--)fast=fast->next;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}