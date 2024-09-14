#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <climits>

using namespace std;
using namespace std::chrono;

class NumberGuessingGame {
private:
    int numberToGuess;
    int numberOfTries;
    int minTime;
    int minute;
    vector<int> guesses;
    vector<int> guessTimes;
    vector<int> guessCounts;

public:
    NumberGuessingGame() {
        srand(time(0));
        resetGame();
        minTime = INT_MAX;
        minute = 0;
    }

    void resetGame() {
        numberToGuess = rand() % 1000 + 1;
        numberOfTries = 0;
        guesses.clear();
        guessTimes.clear();
        guessCounts.clear();
    }

    void startGame() {
        cout << "-------------------------------------------" << endl;
        cout <<endl <<"Starting a new round!" << endl;
        cout << "I have selected a number between 1 and 1000. Can you guess it?" << endl;
        cout<<"You have only two minute to solve the game"<<endl;
        auto start = high_resolution_clock::now();
        int userGuess;
        int time = 0;

        do {
            cout << endl<<"Enter your guess: ";
            cin >> userGuess;
            numberOfTries++;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start);
            minute = duration.count() / 60;
            time = duration.count();
            guesses.push_back(userGuess);
            guessCounts.push_back(numberOfTries);
            guessTimes.push_back(duration.count());

            int remainingSeconds = 60 * minute;
            if (userGuess > numberToGuess) {
                cout << "Too high! Try again." << endl;
                cout << "Time Taken in this step is: " <<  minute << " minute " << abs(remainingSeconds - duration.count()) << " sec" << endl;
            } else if (userGuess < numberToGuess) {
                cout << "Too low! Try again." << endl;
                cout << "Time Taken in this step is: " <<  minute << " minute " << abs(remainingSeconds - duration.count()) << " sec" << endl;
            } else {
                cout << "Congratulations! You've guessed the correct number in " << numberOfTries << " tries." << endl;
                cout << "Time taken to guess the correct number is: " << minute << " minute " << abs(remainingSeconds - duration.count()) << " sec" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }

            cout << endl;
            if(time>120){
                cout<<"OOps! Time limit is over"<<endl;
                cout<<"You loose the game!"<<endl;
                cout<<endl;
                cout<<"Try another game:"<<endl;
                cout<<endl;
                break;
            }

        } while (userGuess != numberToGuess);


        //displayResults();
        updateMinTime(time);
    }

    void displayResults() {
        if (guesses.empty()) {
            cout << "No results to display." << endl;
            return;
        }

        cout << "User Replay:" << endl;
        for (size_t i = 0; i < guesses.size(); ++i) {
            cout << "Try: " << guessCounts[i] << " | Guess: " << guesses[i] << " | Time: " << guessTimes[i] << " sec" << endl;
        }
        cout << endl;
    }

    void updateMinTime(int time) {
        if (time < minTime || time<120) {
            minTime = time;
            
        }
         else{
            cout<<"Game will not solve";
        }
        cout <<endl<< "MinTime to solve the game: " << minTime << " sec" << endl;
    }

    void menu() {
        char choice;
        do {
            cout << "-------------------- Menu --------------------" << endl;
            cout << "1. Play the game" << endl;
            cout << "2. Show results of the last game" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case '1':
                    resetGame();
                    startGame();
                    break;
                case '2':
                    displayResults();
                    break;
                case '3':
                    cout << "Exiting the game. Goodbye!" << endl;
                    break;   
                default:
                    cout << "Invalid choice. Please select again." << endl;
            }

            cout << endl;

        } while (choice != '3');
    }
};

int main() {
    NumberGuessingGame game;
    game.menu();
    return 0;
}
