#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

class GuessTheNumber
{
private:
    int num;

public:
    int GenerateNumber()
    {
        srand(time(0));
        return rand() % 100 + 1;
    }

    void StartGame(int num)
    {
        int GuessNum, Attempts = 0;
        cout << "Welcome to Guess the Number Game!" << endl;
        cout << "I've picked a number between 1 and 100. Try to guess it." << endl;

        do
        {
            cout << "Your guess: ";
            cin >> GuessNum;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            if (GuessNum < num)
            {
                cout << "Try a larger number." << endl;
            }
            else if (GuessNum > num)
            {
                cout << "Try a smaller number." << endl;
            }
            Attempts++;
        } while (GuessNum != num);

        cout << "Congratulations! You guessed the number " << num << " in " << Attempts << " attempts." << endl;
    }
};

int main()
{
    GuessTheNumber game;
    string response;

    do
    {
        game.StartGame(game.GenerateNumber());
        cout << "Do you want to play again? (yes/no): ";
        cin >> response;
    } while (response == "yes");

    cout << "Thank you for playing!" << endl;

    return 0;
}
