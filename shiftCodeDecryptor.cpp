#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include <string> // to_string
#include <iomanip> // setprecision
#include <unistd.h>
#include <cctype>

using namespace std;

const int NUM_CHARS = 26;

char characters[NUM_CHARS] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

int indexOf(char* arr, char c, int n){
	for (int i = 0; i < n ; i++)
		if (arr[i] == c)
			return i;
	return -1;
}

void decryptShift(){
	string word;
	cout << "Enter Code to Decrypt: ";
	getline(cin, word);
	cout << endl;
	
	for (int i = NUM_CHARS-1; i > 0; i--){
		string shifted = "";
		for (int j = 0; j < word.length(); j++){
			if (word[j] == ' '){
				shifted += ' ';
				continue;
			}
			int index = indexOf(characters, word[j], NUM_CHARS);
			if (index > -1){
				shifted += characters[(index+i)%NUM_CHARS];
				continue;
			}
			index = indexOf(characters, tolower(word[j]), NUM_CHARS);
			if (index > -1){
				shifted += toupper(characters[(index+i)%NUM_CHARS]);
				continue;
			}
			shifted += word[j];
		}
		cout << "Shift " << setw(2) << NUM_CHARS - i << ": " << shifted << endl;
	}
	
}

int main(){
	decryptShift();	

	return 0;
}