#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>  // Add this line for numeric_limits

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        attempts++;

        if (userGuess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        } else if (userGuess < secretNumber) {
            cout << "Too low. Try again!\n";
        } else {
            cout << "Too high. Try again!\n";
        }

    } while (userGuess != secretNumber);

    return 0;
}

