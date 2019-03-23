/*
InterviewBit : Valid Sudoku

Link : https://www.interviewbit.com/problems/valid-sudoku/

Asked in:
Google
Amazon


Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/
int Solution::isValidSudoku(const vector<string> &A) {
	
	// Each integer is a bitmask where every bit signifies whether that number is present in the row/col/grid or not
	vector<int> rowHash(9,0);
	vector<int> colHash(9,0);
	vector<int> gridHash(9,0);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){

			// Ignore empty squares
			if(A[i][j]=='.')continue;
			
			// Left shift 1 by the number occuring in the sudoku
			int mask = 1<<(A[i][j] -'0');

			// If this number has already been seen, return 0
			if(rowHash[i] & mask || colHash[j] & mask || gridHash[(i/3)*3 + (j/3)] & mask) return 0;
			
			// Add the number to the hashes
			rowHash[i] |= mask;
			colHash[j] |= mask;
			gridHash[(i/3)*3 + (j/3)] |= mask;
		}
	}
	return 1;

}
