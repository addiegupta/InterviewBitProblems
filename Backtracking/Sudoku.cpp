/*
InterviewBit : Sudoku

Link : https://www.interviewbit.com/problems/sudoku

Asked in:
Microsoft
Qualcomm


Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.


*/

/**

	This problem is solved using backtracking and storing the numbers appearing in rows,columns and subgrids
	in integers in the form of bit mask for every row,column and subgrid.
	Sets can also be used instead of bitmask but bitmask is more efficient as set is more complex and needs more space

*/

bool isValid(int i,int j,int num,vector<int> &rowHash, vector<int> &colHash, vector<int> &gridHash);
bool bitMaskSolve(vector<vector<char>> &A,int i,int j,vector<int> &rowHash,vector<int> &colHash,vector<int> &gridHash);

void Solution::solveSudoku(vector<vector<char> > &A) {
	
	vector<int> rowHash(9,0);
	vector<int> colHash(9,0);
	vector<int> gridHash(9,0);

	// Add numbers to hashes
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(A[i][j]=='.') continue;
			int num = A[i][j] -'0';
			rowHash[i] |= (1<< num);
			colHash[j] |= (1<<num);
			gridHash[(i/3)*3 + (j/3)] |= (1<<num);
		}
	}

	bitMaskSolve(A,0,0,rowHash,colHash,gridHash);
}

bool isValid(int i,int j,int num,vector<int> &rowHash, vector<int> &colHash, vector<int> &gridHash){
	
	// If this number is present in any of the hashes, return false as this number is not valid
	int mask = 1<<num;
	if((rowHash[i] & mask ) || (colHash[j] & mask) || (gridHash[(i/3)*3 + (j/3)] & mask)) return false;

	return true;
}

bool bitMaskSolve(vector<vector<char>> &A,int i,int j,vector<int> &rowHash,vector<int> &colHash,vector<int> &gridHash){
    
    // Reached end of row, increment row num and reset column count
    if(j>=9){
        j=0;
        i++;
    }
    // Reached end of board, return true as solution has been found
    if(i>=9)return true;

    // This position has a number, proceed to solve for next position
    if(A[i][j]!='.') return bitMaskSolve(A,i,j+1,rowHash,colHash,gridHash);

    // Else fit a number here using backtracking 
    else{

    	// Try all the numbers
        for(int k=1;k<=9;k++){
        	
        	// If k can be the number at this position, add it to hashes and board and proceed
            if(isValid(i,j,k,rowHash,colHash,gridHash)) {

                A[i][j] = (char)(k + '0');
                rowHash[i] |= (1<<k);
                colHash[j] |= (1<<k);
                gridHash[(i/3)*3 + (j/3)] |= (1<<k);
            	
            	// Recursively solve; if return value is true, then solution has been found; else remove this number and try some other number    
                if(bitMaskSolve(A,i,j+1,rowHash,colHash,gridHash)){
                    return true; 
                }
                else {
                
                    A[i][j] = '.';
                    rowHash[i] ^= (1<<k);
                    colHash[j] ^= (1<<k);
                    gridHash[(i/3)*3 + (j/3)] ^= (1<<k);
                }
            }  
            
        }
    }

    // No numbers fit, backtrack
    return false;
}


