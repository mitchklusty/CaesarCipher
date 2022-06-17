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

struct params{
	string words = "";
	int shift = 0;
};

int indexOf(char* arr, char c, int n){
	for (int i = 0; i < n ; i++)
		if (arr[i] == c)
			return i;
	return -1;
}

string encryptShift(string words, int shift){
	string shifted = "";
	for (int i = 0; i < words.length(); i++){
		if (words[i] == ' '){
			shifted += ' ';
			continue;
		}
		int index = indexOf(characters, words[i], NUM_CHARS);
		if (index > -1){
			shifted += characters[(index+shift)%NUM_CHARS];
			continue;
		}
		index = indexOf(characters, tolower(words[i]), NUM_CHARS);
		if (index > -1){
			shifted += toupper(characters[(index+shift)%NUM_CHARS]);
			continue;
		}
		shifted += words[i];
	}
	cout << "Shift " << setw(2) << shift << ": " << shifted << endl;	
	return shifted;
}

params getParams(){
	params p;
	cout << "Enter Code to Encrypt: ";
	getline(cin, p.words);
	cout << "Enter Shift: ";
	while(!(cin >> p.shift)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter an int: ";
    }
	cout << endl;

	return p;
}

int main(){
	params p = getParams();
	encryptShift(p.words, p.shift);

	return 0;
}