#include <iostream>
#include <string>

int min(int x, int y, int z) {
    return std::min(std::min(x,y), z);
}

// Does not work
int distance(std::string& x, int index1, std::string& y, int index2) {
    if(index1 == -1)
        return index2 + 1;
    
    if(index2 == -1)
        return index1 + 1;

    //int substitution_cost {1};
    
    if(x[index1] == y[index2])
        //substitution_cost = 0;
        return distance(x, index1 - 1, y, index2 - 1);
    
    return 1 + min(distance(x, index1 - 1, y, index2),
                    distance(x, index1, y, index2 - 1),
                    distance(x, index1 - 1, y, index2 - 1));
}

int main(int argc, char **argv)
{
    std::string s1 {"horse"}, s2 {"ros"};
	std::cout << distance(s1, 4, s2, 2) << "\n";
	return 0;
}


/*
    // Function to find Levenshtein Distance between string X and Y
    // m and n are the number of characters in X and Y respectively
    int dist(string X, int m, string Y, int n)
    {
	    // for all i and j, T[i,j] will hold the Levenshtein distance between
	    // the first i characters of X and the first j characters of Y
	    // note that T has (m+1)*(n+1) values

	    int T[m + 1][n + 1] = { 0 };

	    // source prefixes can be transformed into empty string by
	    // dropping all characters

	    for (int i = 1; i <= m; i++)
		    T[i][0] = i;				// (case 1)

	    // target prefixes can be reached from empty source prefix
	    // by inserting every character

	    for (int j = 1; j <= n; j++)
		    T[0][j] = j;				// (case 1)

	    int substitutionCost;

	    // fill the lookup table in bottom-up manner
	    for (int i = 1; i <= m; i++)
	    {
		    for (int j = 1; j <= n; j++)
		    {
			    if (X[i - 1] == Y[j - 1])   			 // (case 2)
				    substitutionCost = 0;   			 // (case 2)
			    else
				    substitutionCost = 1;   			 // (case 3c)

			    T[i][j] = min(min(T[i - 1][j] + 1,	        // deletion (case 3b)
				    			  T[i][j - 1] + 1),	        // insertion (case 3a)
				    T[i - 1][j - 1] + substitutionCost);    // replace (case 2 & 3c)
		    }
	    }

	    return T[m][n];    
    }
*/

// A Dynamic Programming based C++ program to find minimum 
// number operations to convert str1 to str2 
#include<bits/stdc++.h> 
using namespace std; 

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m+1][n+1]; 

	// Fill d[][] in bottom up manner 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i==0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j==0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i-1] == str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j-1], // Insert 
								dp[i-1][j], // Remove 
								dp[i-1][j-1]); // Replace 
		} 
	} 

	return dp[m][n]; 
} 

// Driver program 
int main() 
{ 
	// your code goes here 
	string str1 = "sunday"; 
	string str2 = "saturday"; 

	cout << editDistDP(str1, str2, str1.length(), str2.length()); 

	return 0; 
} 
