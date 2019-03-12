/*
InterviewBit : Copy List

Link : https://www.interviewbit.com/problems/copy-list

Asked in:
Amazon
Microsoft

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.


*/
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

RandomListNode* solutionUsingHashMap(RandomListNode* A);
RandomListNode* solutionUsingCreatingNodesWithinTheList(RandomListNode* A);

RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	return solutionUsingHashMap(A);
//  return solutionUsingCreatingNodesWithinTheList(A);

}
/* Step 1: Insert nodes within the list which are copy of prev node e.g. for A->B->C->D
		we get A->A'->B->B'->C->C'->D->D'
  Step 2: Assign random pointer to the new nodes i.e. for A', random node is A->random->next
  Step 3: Detach the list of new nodes to get the answer
  */
RandomListNode* solutionUsingCreatingNodesWithinTheList(RandomListNode* A){
	
	if(!A) return A;
	
	// Step 1
	RandomListNode* trav = A;
	while(trav){
		RandomListNode* temp = trav->next;
		RandomListNode* newNode = new RandomListNode(trav->label);
		trav->next = newNode;
		newNode->next = temp;
		trav=temp;
	}
	
	// Step 2
	trav=A;
	while(trav){
		if(trav->random) trav->next->random = trav->random->next;
		else trav->next->random = NULL;
		trav=trav->next->next;
	}

	// Step 3
	RandomListNode* ans=NULL;
	RandomListNode* tail = ans;
	trav=A;
	while(trav){
		if(!ans){
			ans=trav->next;
			tail = ans;
		}
		else{
			tail->next = trav->next;
			tail = tail->next;
		}
		trav->next = tail->next;
		tail->next=NULL;
		trav=trav->next;
	}
	return ans;

}

/*
	Uses hashmap to store nodes

	Step 1: Create a copy of the original list and while creating the copy, keep storing value->node pairs in hash map
	Step 2: In second traversal, check the random node for corresponding node in original list, look for that node in 
	         hash map and assign the random pointer
*/
RandomListNode* solutionUsingHashMap(RandomListNode *A){

    RandomListNode* ansHead = new RandomListNode(0);
    RandomListNode* ansTail = ansHead;
    RandomListNode* trav = A;
    
    unordered_map<int,RandomListNode*> hash;

    // Step 1
    while(trav){
        
        RandomListNode *temp = new RandomListNode(trav->label);
        ansTail->next = temp;
        hash[temp->label] = temp;
        ansTail = temp;
        trav=trav->next;
    }
    
    // Step 2
    ansTail = ansHead->next;
    trav = A;
    while(trav){

        ansTail->random = hash[trav->random->label];
        ansTail=ansTail->next;
        trav=trav->next;
    }

    return ansHead->next;
}