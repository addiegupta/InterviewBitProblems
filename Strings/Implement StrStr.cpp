/*
InterviewBit : Implement StrStr

Link : https://www.interviewbit.com/problems/implement-strstr/


Asked in:
Facebook
Amazon
Qualcomm
Wipro
Microsoft


*/

int ZPatternSearch(string s,string x);
int KMPPatternSearch(string,string);

int Solution::strStr(const string A, const string B) {
    // return ZPatternSearch(A,B);
    return KMPPatternSearch(A,B);
}

void createZArray(int z[],string s,string x){
    // Substring starting from index 0 is equal to the prefix hence it is not relevant
    z[0]=0;
    // Pattern + a character that does not appear in neither the pattern nor the text + the given text
    string a = x + '$' + s;
    int n=s.length(),m=x.length(),len=a.length();
    // Indices to keep track of a 'box' in string 'a'
    // This box extends from l to r and contains matching pattern with prefix
    int l=0,r=0;
    // Iterate over Z array
    for(int k=1;k<len;k++){
        // Iterator of string a greater than position of r
        if(k>r){
            // Set box equal to the current index only
            l=r=k;
            // Match following characters with pattern and increment r to increase the size of box
            while(r<len && a[r]==a[r-l]){
                r++;    
            }
            // Set length of box as z value
            z[k]=r-l;
            // Decrement box size
            r--;
        }
        // Index is less than position of r
        else{
            //TODO Explain this part
            int k1 = k-l;
            if(z[k1]<r-k+1){
                z[k]=z[k1];
            }
            else{
                l = k;
                while(r<len && a[r]==a[r-l]){
                    r++;
                }
                z[k]=r-l;
                r--;
            }
        }
    }
}

// Uses Z array to search for pattern; z[i] contains length of longest substring starting from
// index i which is equal to the prefix of the string
int ZPatternSearch(string s,string x){
    int n = s.length(),m=x.length();
    if(n==0 || m==0)return -1;
    int z[m+n+1];
    memset(z,0,sizeof(z));
    // Creates Z array
    createZArray(z,s,x);
    for(int i=m;i<=m+n;i++){
        // Length equal to length of pattern
        if(z[i]==m)return i-m-1;
    }
    return -1;
}

// Computes the Longest Proper Prefix which is also suffix array for the pattern
int* computeKmpLps(string x){

    int n = x.length();
    int *lps = new int[n];
    int len=0;
    
    // lps[0] is always 0 as no matching characters for 0 length
    lps[0]=0;
    int i=1;
    while(i<n){
        // match found; increment length variable and set lps value to len
        // increment i
        if(x[i]==x[len]){
            lps[i++]= ++len;
        }
        // Mismatch
        else{
            // try decrementing length and then check for match
            // i is not incremented
            if(len!=0){
                len=lps[len-1];
            }
            // no matching characters, set to 0 and increment i
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int KMPPatternSearch(string s,string x){
    int n = s.length();
    int m = x.length();
    int *lps = computeKmpLps(x);
    int i=0,j=0;

    while(i<n){
        // Matching characters, increment iterators
        if(s[i]==x[j]){
            i++;
            j++;
        }
        // found entire pattern return index
        if(j==m)return i-m;

        // Mismatching characters
        else if(s[i]!=x[j] && i<n){
            // try smaller match
            if(j>0){
                j = lps[j-1];
            }
            else i++;
        }
    }
    return -1;
}