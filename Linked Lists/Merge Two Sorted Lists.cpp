/*
InterviewBit : Merge Two Sorted Lists

Link : https://www.interviewbit.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Inefficient solution; creates duplicate for every node
ListNode* initialSolutionByCreatingNewNodes(ListNode* A,ListNode* B){
	// Handle empty list case
	if(A==NULL)return B;
	if(B==NULL)return A;	


	ListNode *ans=NULL,*trav=NULL;
	
	// Traverse lists while no list has reached end 
	while(A && B){

		// Create copy of lower value node and add it to answer list

		if(A->val<B->val){
			ListNode* temp = new ListNode(A->val);
			if(!ans){
				ans = temp;
			}
			else{
				trav->next = temp;
			}
			trav = temp;
			A=A->next;
		}
		else {
			ListNode* temp = new ListNode(B->val);
			if(!ans){
				ans = temp;
			}
			else{
				trav->next = temp;
			}
			trav = temp;
			B=B->next;
		}
	}
	// If nodes are left in list A, add them
	while(A){
		ListNode*temp = new ListNode(A->val);
		trav->next = temp;
		trav = temp;
		A=A->next;
	}
	
	// If nodes are left in list B, add them
	while(B){
		ListNode*temp = new ListNode(B->val);
		trav->next = temp;
		trav = temp;
		B=B->next;
	}
	return ans;
}

ListNode* newSolutionWithoutCreatingNewNodes(ListNode *A,ListNode *B){
	
	// Handle empty lists
	if(!A)return B;
	if(!B)return A;

	// Set first node as the lower value node
	ListNode *ans=NULL;
	if(A->val < B->val){
		ans=A;
		A=A->next;
	}
	else{
		ans=B;
		B=B->next;
	}
	// Ans node will be used as head to answer list, this will be returned at end of function
	ListNode *trav = ans;

	// Traverse while no list has reached end
	while(A && B){

		// Add smaller node to list
		if(A->val < B->val){
			trav->next = A;
			A=A->next;
		}
		else{
			trav->next=B;
			B=B->next;
		}
		trav=trav->next;
	}

	// Add remaining list if any
	if(A)trav->next = A;
	else if(B)trav->next = B;

	return ans;
}
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

	// return initialSolutionByCreatingNewNodes(A,B);
	return newSolutionWithoutCreatingNewNodes(A,B);

}
