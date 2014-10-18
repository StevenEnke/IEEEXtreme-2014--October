#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_MEMORY = 256;
int hexToDec(char someHex);
int getMemorySize(char firstChar, char secondChar);
void getCommand(string command, char* memoryIndex);
void printRange(int lowerAddress, int upperAddress, char* memoryIndex, bool isComma);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	char char1, char2;
	string command;
	int memorySize;
	char memoryIndex[MAX_MEMORY];
	
	// Getting the first two characters
	cin >> char1;
	cin >> char2;
	
	// Retrieving size of the memory
	memorySize = getMemorySize(char1, char2);
	
	// Indexing the array
	for(int i = 0; i < (memorySize+1)*2; i++) {
		memoryIndex[i] = '0';
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

int getMemorySize(char firstChar, char secondChar) {
	int memorySize;

	// Converting first char into decimal integer
	memorySize = hexToDec(firstChar) * 16;
	
	// Converting second char into decimal integer and adding it to firstChar result
	memorySize += hexToDec(secondChar);
	while(memorySize >= MAX_MEMORY)
		memorySize - MAX_MEMORY;

	return memorySize;
}

void getCommand(string command, char* memoryIndex) {
	int lowerAddress, upperAddress, index, lowerAddress2, upperAddress2;
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
			lowerAddress = hexToDec(command[4])*32;
			upperAddress = (hexToDec(command[5])+1);

			memoryIndex[lowerAddress + upperAddress - 1] = command[1];
			memoryIndex[lowerAddress + upperAddress] = command[2];
		}
		
		else { // No '#'
			lowerAddress = hexToDec(command[0]);
			upperAddress = hexToDec(command[1]);
			lowerAddress2 = hexToDec(command[3])*2;
			upperAddress2 = hexToDec(command[4])*2;

			memoryIndex[lowerAddress2] = memoryIndex[lowerAddress];
			memoryIndex[upperAddress2] = memoryIndex[upperAddress];
		}
	}
	
	else if(command.compare("ADD") == 0) {
		
	}
	
	return;
}

void printRange(int lowerAddress, int upperAddress, char* memoryIndex, bool isComma) {
	cout << memoryIndex[lowerAddress] << memoryIndex[lowerAddress+1];
	
	if(isComma) {
		for(int i = lowerAddress + 2; i < 2*(upperAddress+1); i+=2) {
			cout << ' ' << memoryIndex[i] << memoryIndex[i+1];
		}
	}
	cout << endl;
	
	return;
}