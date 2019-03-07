/*
InterviewBit : Simplify Directory Path

Link : https://www.interviewbit.com/problems/simplify-directory-path/


Asked in:  
Microsoft


Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.


*/
string Solution::simplifyPath(string A) {
	
	// stack and vector to store the paths
	stack<string> path;
	vector<string> ans;

	int i=1;
	int n = A.size();
	string temp;

	// iterate over input string
	while(i<=n){
	
		// Handle the temp string as '/' found 
		if(i==n || A[i]=='/'){

			// Go back one directory i.e. pop from stack
			if(temp==".." && !path.empty()) path.pop();
			
			// push valid path to stack
			else if(temp!=".." && temp!="." && temp!=""){
				path.push(temp);
			}

			// clear temp for next path
			temp.clear();
			
			// end of string, break
			if(i==n)break;
		}
		// Alphabetical or '.' character found, add to temp
		else temp.append(1,A[i]);
		i++;
	}

	// Add paths to vector
	while(!path.empty()){
		ans.push_back(path.top());
		path.pop();
	}

	// Reverse the vector to get desired output
	reverse(ans.begin(),ans.end());
	
	// Add strings from vector with slashes
	string finalPath;
	for(i=0;i<ans.size();i++){
		finalPath +="/";
		finalPath += ans[i];
	}

	// If path is empty, return single slash
	return (!finalPath.empty())?finalPath:"/";
}
