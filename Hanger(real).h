#pragma once
#include <iostream>
#include <string>
using namespace std;

class Hanger {
	string image;
	short appendages;
	char guesses[26];

public:
	Hanger() {
		image = "   __________\n   |        |\n   |\n   |\n   |\n   |\n   |\n   |\n___|_____________\n\n";
		appendages = 0;
		for (int i = 0; i < 26; i++) {
			guesses[i] = ' ';
		}
	}

	bool updateImage() {
		if (appendages == 0) {
			image = "   __________\n   |        |\n   |        O\n   |\n   |\n   |\n   |\n   |\n___|_____________\n\n";
		}
		else if (appendages == 1) {
			image = "   __________\n   |        |\n   |        O\n   |        |\n   |\n   |\n   |\n   |\n___|_____________\n\n";
		}
		else if (appendages == 2) {
			image = "   __________\n   |        |\n   |        O\n   |       /|\n   |\n   |\n   |\n   |\n___|_____________\n\n";
		}
		else if (appendages == 3) {
			image = "   __________\n   |        |\n   |        O\n   |       /|\\\n   |\n   |\n   |\n   |\n___|_____________\n\n";
		}
		else if (appendages == 4) {
			image = "   __________\n   |        |\n   |        O\n   |       /|\\\n   |        |\n   |       /\n   |\n   |\n___|_____________\n\n";
		}
		else if (appendages >= 5) {
			image = "   __________\n   |        |\n   |        O\n   |       /|\\\n   |        |\n   |       / \\\n   |\n   |\n___|_____________\n\n";
			appendages++;
			return true;
		}
		appendages++;
		return false;
	}

	void printImage() {
		cout << image;
	}

	void displayUsed() {
		cout << "Wrong letters:" << endl;
		for (int i = 0; i < 26; i++) {
			cout << guesses[i] << " ";
		}
		cout << "\n";
	}

	void updateGuesses(char guess) {
		bool added = false;
		short counter = 0;
		while (added == false || counter == 25) {
			if (guesses[counter] != guess && guesses[counter] == ' ') {
				guesses[counter] = guess;
				added = true;
			}
			counter++;
		}
	}
};