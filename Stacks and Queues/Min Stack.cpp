/*
InterviewBit : Min Stack

Link : https://www.interviewbit.com/problems/min-stack/


Asked in:  
Yahoo
Amazon
Adobe

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 


*/

// Check version history for older solution using 2 stacks-------------------------------------------------------


// Stores the input elements
stack<int> s;
int minEle = INT_MAX;

// Reset variables
MinStack::MinStack() {
    while(!s.empty())s.pop();
    minEle = INT_MAX;
}


void MinStack::push(int x) {

	if(x<minEle){

		// Now previous min element can be retrieved from this stack value
		s.push(2*x - minEle);
		
		// Set new element as min element
		minEle = x;
	}

	// Simply push element
	else s.push(x);
}

void MinStack::pop() {
    
    // No elements
    if(s.empty()) return;
	
	// Retrieve the new minimum value after this value is removed    
    if(s.top()<minEle){

    	minEle = 2*minEle - s.top();
    	s.pop();
    }
    else s.pop();
}

int MinStack::top() {
    
    if(s.empty()) return -1;
    
    if(s.top()<minEle) {
    	// Retrieve new min element if top element is removed
    	int temp = 2* minEle - s.top();

    	// Return actual value that should have been inserted
    	return (s.top() + temp)/2;
	}    
    else return s.top();
}

int MinStack::getMin() {
    if(s.empty())return -1;
    return minEle;
}	

