/*
InterviewBit : Integer to Roman

Link : https://www.interviewbit.com/problems/integer-to-roman/

Asked in

Facebook
Amazon
Microsoft
Twitter

Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"


*/

// Get the largest Roman numeral that should be used for the number
int greatestRoman(int A){
	if(A>=1000) return 1000;
	if(A>=500) return 500;
	if(A>=100)return 100;
	if(A>=50)return 50;
	if(A>=10) return 10;
	if(A>=5)return 5;
	return 1;
}
// Get the Roman character for the integer argument
char getRomanChar(int A){
	switch(A){
		case 1000:return 'M';
		case 500:return 'D';
		case 100:return 'C';
		case 50:return 'L';
		case 10:return 'X';
		case 5:return 'V';
		case 1:return 'I';
	}
}
bool isRomanNumeralStartingFromFive(int a){ return a==5 || a==50 || a==500;}
string Solution::intToRoman(int A) {

	// Stores the answer Roman numerals
	string ans;

	// Stores the greatest number present in A and greaterNum stores the number greater than num
	// This is done to figure out how to place the letters
	// e.g. 3 is written as III whereas 4 is IV
	// So in line 63 the if condition (greaterNum>num) will be applicable for 4 and not for 3
	// Similarly 99 , 40 etc all such numbers will be in this condition
	int num,greaterNum;
	
	while(A){
		// Get the current greatest number possible in terms of one Roman numeral
		num = greatestRoman(A);

		// if starting from 5, then they have their own Roman representation and dont need to be 
		// treated in the small number preceding larger number case
		// e.g. if this condition is not present then 50 may be written as LC instead of L
		greaterNum = (isRomanNumeralStartingFromFive(num))?greatestRoman(A+num/5):greatestRoman(A+num);
		
		// This condition traps the cases where a smaller Roman letter precedes a larger one
		// applicable according to Roman system
		if(greaterNum>num){

			if(isRomanNumeralStartingFromFive(num)) num/=5;

			// Subtract the number being written in Roman from the actual number
			A = A - greaterNum + num;

			// Add the Roman numerals to the string ans
			ans.append(1,getRomanChar(num));
			ans.append(1,getRomanChar(greaterNum));
		}
		else{
			// Not a number preceding a larger number case
			// Simply append the Roman letter to the ans and subtract from the number A
			A-=num;
			ans.append(1,getRomanChar(num));
		}
	}
	return ans;
}
