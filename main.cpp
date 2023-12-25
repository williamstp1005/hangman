#include <iostream>
#include <string>
#include "Solution.h"
#include "Hanger(real).h"
using namespace std;

int main() {
	string phrase;
	string message;
	string screen = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	bool quit = false;
	bool gameOver = false;
	char guess;
	Solution* solution;

	cout << "WELCOME TO HANGMAN!!!!!!";

	while (quit == false) {
		cout << "\n\n\nWhat's your secret phrase???" << endl;
		getline(cin, phrase);
		cout << screen << endl;
		if ((bool)phrase.length()) {
			solution = new Solution(phrase);
		}
		else {
			solution = new Solution;
		}
		Hanger hanger;

		while (gameOver == false) {
			if (solution->checkWin()) {
				gameOver = true;
				message = "~*~*~Congratulations! You win!~*~*~";
				continue;
			}
			hanger.printImage();
			solution->display();
			hanger.displayUsed();
			cout << message << endl << endl;
			message = "";
			cout << "What are you gonna guess?" << endl;
			cin >> guess;
			
			if ((int)guess < 65 || (int)guess > 122 || ((int)guess > 90 && (int)guess < 97)) {
				message = "That is not a valid suggestion!";
				continue;
			}
			else if ((int)guess >= 97) {
				guess -= 32;
				cout << guess;
			}

			if (!solution->check(guess)) {
				if (hanger.updateImage()) {
					gameOver = true;
					message = "#%#%You lose!#%#%\nThe answer was: " + phrase + "\n";
					cout << screen;
					hanger.printImage();
					continue;
				}
				hanger.updateGuesses(guess);
			}
			cout << screen << endl;
		}

		while (gameOver == true) {
			char response;
			cout << message << "\nDo you wanna play again? (y/n)" << endl;
			cin >> response;
			if (response == 'n') {
				quit = true;
				gameOver = false;
			}
			else if (response == 'y') {
				getline(cin, phrase);
				gameOver = false;
			}
			else {
				cout << screen << "I don't know what this means..." << endl;
			}
			message = "";
		}
	}
	cout << "\n\nThank you for playing!!!!!!" << endl;
	return 0;
}