#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
	struct Character {
		char correct;

		char visible;
		Character() {}
		Character(char argument) {
			this->correct = argument;
			visible = '_';
		}

		void setVars(char argument) {
			this->correct = argument;
			visible = '_';

			if (argument == ' ') {
				visible = ' ';
			}
			else if (argument == '-') {
				visible = '-';
			}
		}

	};

	string solution;
	Character* characters;
	string phrase;


public:
	Solution() {
		cout << "~~~No phrase was given; the solution is \"A\"~~~" << endl;
		solution = "A";
		characters = new Character[solution.length()];
		for (int i = 0; i < solution.length(); i++) {
			characters[i].setVars(solution[i]);
		}
	}

	Solution(string phrase) {
		solution = phrase;
		characters = new Character[solution.length()];
		for (int i = 0; i < solution.length(); i++) {
			if ((int)solution[i] >= 97 && (int)solution[i] < 123) {
				characters[i].setVars(solution[i] - 32);
			}
			else {
				characters[i].setVars(solution[i]);
			}
		}
	}

	void display() {
		for (int i = 0; i < solution.length(); i++) {
			cout << characters[i].visible << " ";
		}
		cout << "\n" << endl;
	}

	bool check(char attempt) {
		bool good = false;
		for (int i = 0; i < solution.length(); i++) {
			if (characters[i].correct == attempt) {
				characters[i].visible = attempt;
				good = true;
			}
		}

		return good;
	}

	bool checkWin() {
		for (int i = 0; i < solution.length(); i++) {
			if (characters[i].correct != characters[i].visible) {
				return false;
			}
		}

		return true;
	}

	string sendMessage() {

	}
};