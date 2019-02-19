/*
InterviewBit : Length of Last Word

Link : https://www.interviewbit.com/problems/length-of-last-word/

Asked in: 

Amazon


Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.


*/
int Solution::lengthOfLastWord(const string A) {
    
    // Pointer to start of string
    const char* s = &A[0];
    int len =0;

    // Traverse till end of list
    while(*s){
        // Character found
        if(*s!=' '){
            len++;
            s++;
            continue;
        }

        // This line is reached if character is a space
        s++;
        // Now this character should be letter otherwise multiple spaces present
        if(*s && *s!=' ')len=0;
    }
    return len;
}
