
/*
InterviewBit : Letter Phone

Link : https://www.interviewbit.com/problems/letter-phone


Asked in:  
Facebook
Epic Systems


*/
void findCombinations(string A,int i,int n ,vector<string> &ans,string c){
    
    if(i==n){
        ans.push_back(c);
        return;
    }

    int num = A[i]-'0';
    if(num==0 || num ==1){
        c+=A[i];
        findCombinations(A,i+1,n,ans,c+(char)add);
    }
    else{    
        int add = (num-2) * 3 + 'a';
        if(num>7)add++;
        for(int j=0;j<3;j++){
        	findCombinations(A,i+1,n,ans,c+(char)add++);
        }
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