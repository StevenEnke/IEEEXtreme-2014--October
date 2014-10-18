#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_MEMORY = 256;
int hexToDec(char someHex);
char decToHex(int someDec);
int getMemorySize(char firstChar, char secondChar);
void getCommand(string command, string memoryIndex[]);
void printRange(int lowerAddress, int upperAddress, string memoryIndex[], bool isComma);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	char char1, char2;
	string command;
	int memorySize;
	string memoryIndex[MAX_MEMORY];
	
	// Getting the first two characters
	cin >> char1;
	cin >> char2;
	
	// Retrieving size of the memory
	memorySize = getMemorySize(char1, char2);
	
	// Indexing the array
	for(int i = 0; i < memorySize+1; i++) {
		memoryIndex[i] = "00";
	}
	
	// Getting commands
	while(getline(cin, command)) {
		getCommand(command, memoryIndex);
	}

    return 0;
}

int hexToDec(char someHex) {
	int decimalInt;
	if(someHex >= 'A')
		decimalInt = someHex - 'A' + 10;
	else
		decimalInt = someHex - '0';
	
	return decimalInt;
}

char decToHex(int someDec) {
	int hexChar;
	if(someDec >= 10)
		hexChar = someDec + 'A' - 10;
	else
		hexChar = someDec + '0';
	
	return hexChar;
}

int getMemorySize(char firstChar, char secondChar) {
	int memorySize;

	// Converting first char into decimal integer
	memorySize = hexToDec(firstChar) * 16;
	
	// Converting second char into decimal integer and adding it to firstChar result
	memorySize += hexToDec(secondChar);

	return memorySize;
}

void getCommand(string command, string memoryIndex[]) {
	int lowerAddress, upperAddress, index, toAdd;
	string concatenateChars, hexAdd;
	char temp;
	bool commaTrue = false;

	getline(cin, command, ' ');
	
	if(command.compare("PRINT") == 0) {
		cin >> command;

		for(int i = 0; i < command.length(); i++) {
			if(command[i] == ',') {
				index = i;
				commaTrue = true;
				i = command.length();
			}
		}
		
		lowerAddress = hexToDec(command[0])*16 + hexToDec(command[1]);

		if(commaTrue) {
			upperAddress = hexToDec(command[index+1])*16 + hexToDec(command[index+2]);
		}
		
		printRange(lowerAddress, upperAddress, memoryIndex, commaTrue);
	}
	
	else if(command.compare("MOVE") == 0) {
		cin >> command;
		if(command.front() == '#') {
			concatenateChars = command[1];
			concatenateChars += command [2];
			memoryIndex[hexToDec(command[4]) + hexToDec(command[5])] = concatenateChars;
		}
		
		else { // No '#'
			lowerAddress = hexToDec(command[0]) + hexToDec(command[1]);
			upperAddress = hexToDec(command[3]) + hexToDec(command[4]);

			memoryIndex[upperAddress] = memoryIndex[lowerAddress];
		}
	}
	
	else if(command.compare("ADD") == 0) {
		cin >> command;
		if(command.front() == '#') {
		}
		
		else { // No '#'
			lowerAddress = hexToDec(command[0]) + hexToDec(command[1]);
			upperAddress = hexToDec(command[3]) + hexToDec(command[4]);
			
			concatenateChars = memoryIndex[lowerAddress];
			concatenateChars += memoryIndex[upperAddress];
			toAdd = hexToDec(concatenateChars[0])*16 + hexToDec(concatenateChars[1]) + hexToDec(concatenateChars[2])*16 + hexToDec(concatenateChars[3]);
			
			while(toAdd > 0) {
				hexAdd += decToHex(toAdd%16);
				toAdd /= 16;
			}
			while(hexAdd.length() > 2) {
				hexAdd.pop_back();
			}
			
			temp = hexAdd[0];
			hexAdd[0] = hexAdd[1];
			hexAdd[1] = temp;
			
			memoryIndex[upperAddress] = hexAdd;
		}
	}
	
	return;
}

void printRange(int lowerAddress, int upperAddress, string memoryIndex[], bool isComma) {
	cout << memoryIndex[lowerAddress];
	
	if(isComma) {
		for(int i = lowerAddress + 1; i < upperAddress+1; i++) {
			cout << ' ' << memoryIndex[i];
		}
	}
	cout << endl;
	
	return;
}