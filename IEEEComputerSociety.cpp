#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findPalindrome(string posPalindrome);
bool isPalindrome(string palindrome);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string posPalindrome;
	int longestPalindrome;
	
	cin >> posPalindrome;
	
	cout << "Is Palindrome?: " << isPalindrome(posPalindrome) << endl;
	
	longestPalindrome = findPalindrome(posPalindrome);
	
	cout << longestPalindrome;
	
    return 0;
}

int findPalindrome(string posPalindrome) {
	int maxPalindromeFound = 1; // Maximum "palindrome is guaranteed to be 1
	int count = 0;
	int length;
	string subStringLeft = "";
	string subStringRight = "";

	
	length = posPalindrome.length();
	for(int i=0; i < length; i++) {
		for(int j = 0; j < length; j++) {	
			subStringLeft[j+1] = posPalindrome[j-i];
			subStringRight[j-1] = posPalindrome[j+i];

			cout << "Is subString: " << subStringLeft << " :: " << subStringRight << endl;
			
			if(isPalindrome(subString)) {
				if(maxPalindromeFound < subString.length()) {
					maxPalindromeFound = subString.length();
				}
			}
		}	

	}
	return maxPalindromeFound;
}

bool isPalindrome(string palindrome) {	
	if(equal(palindrome.begin(), palindrome.begin() + palindrome.size()/2, palindrome.rbegin())) {
		return true;
	}
	return false;
}