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

// Stores the minimum elements at point of insertion
stack<int> minS;

// Stores the input elements
stack<int> s;

// Clear out the stacks
MinStack::MinStack() {
    while(!minS.empty())minS.pop();
    while(!s.empty())s.pop();
}


void MinStack::push(int x) {
	
	// Add the element to main stack
	s.push(x);

	// Add element only if minstack is empty or the new value is less than equal to current min
    if(minS.empty() || minS.top()>x)minS.push(x);
}

void MinStack::pop() {
    
    // No elements
    if(s.empty()) return;
    
    // Pop from min stack only if the value to be removed is less than or equal to min stack top value
    if(s.top()<=minS.top())minS.pop();
    s.pop();
}

int MinStack::top() {
    
    if(s.empty())return -1;
    return s.top();
}

int MinStack::getMin() {
    if(minS.empty())return -1;
    return minS.top();
}

