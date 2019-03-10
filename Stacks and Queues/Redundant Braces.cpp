/*
InterviewBit : Redundant Braces

Link : https://www.interviewbit.com/problems/redundant-braces/


Asked in:  
Amazon

Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0




*/
int initialSolutionUsingStacks(string A);
int newSolutionWithoutStacks(string A);
int anotherSolution(string A);
int Solution::braces(string A) {
    
    // return initialSolutionUsingStacks(A);
    // return newSolutionWithoutStacks(A);
    return anotherSolution(A);
}
int initialSolutionUsingStacks(string A){
    
    // Store opening brackets and operators
    stack<char> brackets,ops;

    int n = A.size();
    for(int i=0;i<n;i++){

        // Push on stack
        if(A[i]=='('){
            brackets.push('(');
        }
        // If no operator present then this bracket is redundant
        else if(A[i] == ')'){
            if(ops.empty())return 1;

            // else remove a bracket and an operator
            brackets.pop();
            ops.pop();
        }
        // Push operator
        else if(!brackets.empty() && !isalpha(A[i]))ops.push(A[i]);
    }
    return 0;
}

int newSolutionWithoutStacks(string A){
    int bracks=0,ops=0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]=='(')bracks++;
        else if (A[i]==')'){
            if(ops==0)return 1;

            bracks--;
            ops--;
        }
        else if(bracks!=0 && !isalpha(A[i])) ops++;
    }
    return 0;
}

// Every bracket should have at least one operator associated with it
int anotherSolution(string A){
        
    int n = A.size();
    int count =0;
    for(int i=0;i<n;i++){
        if(A[i]=='(') count++;
        else if((A[i]=='+' || A[i]=='/' || A[i] == '*' || A[i]=='-')&&count>0) count--;
    }
    return (count>0) ? 1 : 0;

}