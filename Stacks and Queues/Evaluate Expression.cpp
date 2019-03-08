/*
InterviewBit : Evaluate Expression

Link : https://www.interviewbit.com/problems/evaluate-expression/


Asked in:  
Yahoo
Google
Facebook

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


*/
int Solution::evalRPN(vector<string> &A) {
	
	// Store numbers
	stack<int> nums;
	int n = A.size();

	for(int i=0;i<n;i++){
		
		// Operator found
		if(A[i]=="+" ||A[i]=="-"||A[i]=="*"||A[i]=="/"){
			
			// Get two top most numbers from stack
			int b = nums.top();
			nums.pop();
			int a = nums.top();
			nums.pop();

			// Push the result of performing operation on 2 operators
			if(A[i]=="+") nums.push(a+b);
			else if (A[i]=="-")nums.push(a-b);
			else if (A[i]=="/")nums.push(a/b);
			else if (A[i]=="*")nums.push(a*b);
		
		}
		else{
			// Number found, push number to stack
			nums.push(stoi(A[i]));
		}
	}

	// Return answer which is the only remaining value in stack
	return nums.top();

}
