#include <iostream>


using namespace std;

//the function to first find the LCP between two strings by comparison, 
//then traverse through the list of strings given 

string find_the_longest_common_prefix_between_two(string InputString1, string InputString2) {
	
	//create an empty result string to insert 
	
	string common_prefix_between_two_strings; 
	
	//intialize the sizes of two strings to compare 
	
	int x,y;
	
	x = InputString1.length(); 
	
	y = InputString2.length(); 
	
	//Use for loop to traverse two strings to find their LCP
	//to incrementally compare all other strings throughout the entire list 
	
	//for index i in InputString1, index j in InputString2
	//traverse these two strings, compare, find their LCP 
	
	for (int i = 0, j=0; i<=x-1 && j<=y-1; i++, j++ ){
		
		//since the index spot of two strings are always the same (i=j) 
		//start comparing from the 0 index since finding common prefix
		//whenever their characters at the same indices are not the same characters
		//which indicates that they have reached their longest common prefix string, break. 
		
		//base case 
		
		if (InputString1[i] != InputString2[j]) {
			
			break;
		}
		
		//else if InputString1[i] = InputString2[j]
		//that character is in their LCP string
		//use push_back() method to insert the character at i spot in InputString1 
		//recursively, until hit the base case when achieved the LCP string
		
		common_prefix_between_two_strings.push_back(InputString1[i]); 
		
	}
	
	
	//then return the LCP of two strings 
	
	return (common_prefix_between_two_strings); 
	
	
}




//the function to then find the LCP amongst all the strings in the given list/array 

string find_the_longest_common_prefix_amongst_all(string given_string_array[], int s) {
	
	
	//intialize the result LCP 
	
	string LCP_amongst_all = given_string_array[0]; 
	
	//traverse through the entire given array of strings
	//s is the size of the given_string_array
	
	for (int i = 1; i <= s - 1; i++) {
		
		//call the find_the_longest_common_prefix_between_two funciton here 
		//to incrementally and recursively comparing any two adjacent strings throughout 
		//the given array of strings until done traversalling. 
		
		LCP_amongst_all = find_the_longest_common_prefix_between_two(LCP_amongst_all, given_string_array[i]); 
		
	}
	
	//we got the longest common prefix string within the given array of strings 
	
	return (LCP_amongst_all); 
	
	
	
}



//driver 

int main(int argc, char *argv[]) {
	
	string myArray[] = {"apple", "app", "aple", "appl"};
	
	int ArraySize = sizeof(myArray) / sizeof(myArray[0]);
	
	//call the function to get the LCP here 
	
	string OutputLCP = find_the_longest_common_prefix_amongst_all(myArray, ArraySize); 
	
	// If the strings has the longest common prefix, return  the LCP
	
	//If the strings do not have any common prefix, return the empty string
	
	
	//if OutputLCP.length()!=0/if there is LCP 
	
	if (OutputLCP.length())
		
		cout<<"Input array has the longest common prefix as:" <<OutputLCP.c_str(); 
		
	
	else
		return {}; 
	

	
}