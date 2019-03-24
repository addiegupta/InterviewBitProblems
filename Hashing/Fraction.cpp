/*
InterviewBit : Fraction

Link : https://www.interviewbit.com/problems/fraction

Asked in:
Amazon
Microsoft

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"


*/


string Solution::fractionToDecimal(int A, int B) {
    

	// Convert parameters to long long int
    long long int num  = A;
    long long int den = B;

    // Initial string stores the floor of the answer e.g. for 5/2, initial = "2"
    string initial = "";
       
    // Handle negative sign
    if((num<0 && den>0) || (num>0 && den<0)){
        initial = "-" + initial;
    }

    // Make both positive
 	num = abs(num);
    den = abs(den);

    // Set initial to floor along with sign
    long long int floor = num/den;
    initial += to_string(floor);
 	
 	// Get the remainder
    num=num%den;

    // No decimal part, return floor
    if(num==0) return initial;

    // Stores decimal string
    string decimal = "";

    // Stores result integer at every division
    int result;
    
    // Maps remainder value to the position at which it is found, this will give the repeating part if any
    unordered_map<int,int> hash;
    
    // Iterate until remainder becomes 0 and current remainder is not found previously
    while(num!=0 && (hash.find(num)==hash.end())){
        
        // Add current remainder to hash with value as the position of the remainder in decimal string
        hash[num] = decimal.length();
 	
 		// Multiply by 10 for division
        num = num*10;
 		
 		// Get new quotient and append to decimal string
        result = num/den;
        decimal += to_string(result);
 		
 		// Set num as the remainder of num/den for next iteration
        num %=den;
    }
    
    // No remainder => No repeating decimal part
    if(num==0) return initial + "." + decimal;
	

	// Get repeating part which is the substring from the position the remainder was found till end of string 
	string repeating = decimal.substr(hash[num]);

	// Non repeating part is the left portion of the decimal string
  	decimal = decimal.substr(0,hash[num]);

  	// Add parentheses around the repeating part
   	return initial + "." + decimal + "(" + repeating + ")";
}