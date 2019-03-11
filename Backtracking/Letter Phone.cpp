/*

InterviewBit : Letter Phone

Link : https://www.interviewbit.com/problems/letter-phone


Asked in:  
Facebook
Epic Systems

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
    
    1        2        3
           abc       def
    4        5        6
   ghi     jkl     mno
    7        8        9
   pqrs    tuv    wxyz
            0


The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.


*/
void findCombinations(string A,int i,int n ,vector<string> &ans,string c){
    
    // Completed string; add to vector and return
    if(i==n){
        ans.push_back(c);
        return;
    }
    
    // get int value of number
    int num = A[i]-'0';
    // 0 or 1 case simply add to string and recur
    if(num==0 || num ==1){
        c+=A[i];
        findCombinations(A,i+1,n,ans,c+(char)add);
    }
    else{    
        // Get the value to be increased to 'a' for particular number
        int add = (num-2) * 3 + 'a';

        // 7 has 4 letters so increase 1 to make up for it
        if(num>7)add++;
        
        // Recur for all 3 letters e.g. for 2 : a ,b and c
        for(int j=0;j<3;j++){
            findCombinations(A,i+1,n,ans,c+(char)add++);
        }
        
        // 7 and 9 have 4 letters each
        if(num==7 || num==9){
            findCombinations(A,i+1,n,ans,c+(char)add);
        }
    }    
    
}
vector<string> Solution::letterCombinations(string A){

    vector<string> ans;
    int n = A.size();

    findCombinations(A,0,n,ans,"");

    return ans;
    
}