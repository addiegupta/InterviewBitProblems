/*
InterviewBit : Wave Array

Link : https://www.interviewbit.com/problems/wave-array/

Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 

*/
vector<int> Solution::wave(vector<int> &A) {
	// Sort the array
    sort(A.begin(),A.end());
    int n= A.size();
    for(int i=0;i<n-1;i+=2){
    	// Swap every 2 consecutive elements
        swap(A[i],A[i+1]);
    }
    return A;
}

//Java O(n) Solution added later 01/2022
public static void convertToWave(int arr[], int n){
        
        // keep peaks at even position, by swapping large values of adjacent odd positions
	// if peaks are in place, valleys will automatically be in place too
	// hence, no need to sort; every decision can be made locally
        for(int i = 0; i < n; i += 2){
            if(i > 0 && arr[i-1] > arr[i]){
                swap(arr, i, i-1);
            }
            if(i < n-1 && arr[i+1] > arr[i]){
                swap(arr,i,i+1);
            }
        }
    }
    private static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
