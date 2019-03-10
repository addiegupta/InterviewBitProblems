/*
InterviewBit : Colorful Number

Link : https://www.interviewbit.com/problems/colorful-number/

Asked in:

Epic systems

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1


*/
int initialSolutionUsingConversionOfIntToVector(int A);
int newSolutionUsingSprintf(int A);
int Solution::colorful(int A) {
	
	if(A==0)return 1;
	
	// return initialSolutionUsingConversionOfIntToVector(A);

	return newSolutionUsingSprintf(A);

}
int newSolutionUsingSprintf(int A){
	
	// This converts int to string
	char num[60];
	sprintf(num,"%d",A);
	int n = strlen(num);

	unordered_set<int> hash;
	for(int i=0;i<n;i++){
		int mul=1;
		for(int j=i;j<n;j++){
			mul*= (num[j]-'0');
			if(hash.find(mul)!=hash.end()) return 0;
			hash.insert(mul);
		}
	}
	return 1;

}
vector<int> numToVec(int A){
	
	vector<int> ans;
	while(A){
		ans.push_back(A%10);
		A/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int initialSolutionUsingConversionOfIntToVector(int A){

	// Get the number in digits form
	vector<int> digits = numToVec(A);
	int n = digits.size();

	unordered_set<int> hash;
	
	// For every subsequence check if the product exists in hash set
	for(int i=0;i<n;i++){
		int mul=1;
		for(int j=i;j<n;j++){
			mul *= digits[j];
			if(hash.find(mul)!=hash.end())return 0;
			hash.insert(mul);
		}
	}
	return 1;
}