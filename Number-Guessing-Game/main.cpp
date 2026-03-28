#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void guessNumber(int secret, int maxAttempts){
    int guess;
    int attempts = 0;

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
            cout << "\n🎉 Congratulations! You guessed it in "
                 << attempts << " attempts.\n";
            return;
        }

        int diff = abs(secret - guess);
    
        if(diff <= 5){
            cout << "But Very close!\n";
        }
        else if(diff <= 10){
            cout << "But Close!\n";
        }

        cout << (maxAttempts - attempts) << " attempts left\n";
    }

    cout << "\n You lost! The number was: " << secret << endl;
}

int main(){
    srand(time(0));

    int maxAttempts = 10;
    char playAgain;

    do{
        int secret = rand() % 100 + 1;

        cout << "\n=== Guess Number (1 to 100) ===\n";
        guessNumber(secret, maxAttempts);

        cout << "\nDo you want to play again (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y');

    cout << "Exited!\n";
    return 0;
}