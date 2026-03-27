#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    int maxAttempts = 10;

    cout << "=== Guess Number (1 to 100) ===\n";

    while(attempts < maxAttempts){
        cout << "\nEnter your guess: ";
        cin >> guess;

        if(guess < 1 || guess > 100){
            cout << "Invalid input! Enter between 1 and 100.\n";
            continue;
        }

        attempts++;

        if(guess > secret){
            cout << "Too high!\n";
        }
        else if(guess < secret){
            cout << "Too low!\n";
        }
        else{
            cout << "\n Congratulations! You guessed it in "
                 << attempts << " attempts.\n";
            return 0;
        }

        cout << (maxAttempts - attempts) << " attempts left\n";
    }

    cout << "\n You lost! The number was: " << secret << endl;

    return 0;
}