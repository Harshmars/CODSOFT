#include <iostream>
#include <algorithm>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkAllBoxesFull()
{
    for (int i = 0; i <= 7; i++)
    {
        //cheking for draw
        if (square[i] == '1' || square[i] == '2' || square[i] == '3' || square[i] == '4' || square[i] == '5' || square[i] == '6' || square[i] == '7' || square[i] == '8' || square[i] == '9')
        {
            return 0;
        }
    }
    return 1;
}
int checkwin()
{
    for (int i = 1; i <= 7; i += 3)
    {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
        {
            return 1;
        }
    }
    for (int i = 1; i <= 3; ++i)
    {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
        {
            return 1;
        }
    }
    if (square[1] == square[5] && square[5] == square[9])
    {
        return 1;
    }
    if (square[3] == square[5] && square[5] == square[7])
    {
        return 1;
    }
    return 0;
}

void board()
{
    system("cls");
    cout << "\n\n\nTic Tac Toe Game\n\n";
    cout << "player 1(X) - player 2(0)\n\n\n";
    cout << "     |       |       " << endl;
    cout << " " << square[1] << "   |     " << square[2] << " |     " << square[3] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << " " << square[4] << "   |     " << square[5] << " |     " << square[6] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << " " << square[7] << "   |     " << square[8] << " |     " << square[9] << endl;
    cout << "     |       |       " << endl;
}

int minimax(char board[10], int depth, bool isMaximizing)
{
    int scores[2] = {10, -10};
    int result = checkwin();
    if (result == 1)
        return scores[0];
    if (result == 2)
        return scores[1];
    if (result == 0)
        return 0;

    if (isMaximizing)
    {
        int bestScore = -1000;
        for (int i = 1; i <= 9; ++i)
        {
            if (board[i] == char(i + 48))
            {
                board[i] = 'O';
                int score = minimax(board, depth + 1, !isMaximizing);
                board[i] = char(i + 48);
                bestScore = max(bestScore, score);
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 1000;
        for (int i = 1; i <= 9; ++i)
        {
            if (board[i] == char(i + 48))
            {
                board[i] = 'X';
                int score = minimax(board, depth + 1, !isMaximizing);
                board[i] = char(i + 48);
                bestScore = min(bestScore, score);
            }
        }
        return bestScore;
    }
}

int findBestMove(char board[10])
{
    int bestMove = -1;
    int bestScore = -1000;
    for (int i = 1; i <= 9; ++i)
    {
        if (board[i] == char(i + 48))
        {
            board[i] = 'O';
            int moveScore = minimax(board, 0, false);
            board[i] = char(i + 48);
            if (moveScore > bestScore)
            {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

int main()
{
    int player = 1, choice;
    char mark;
    int i, score;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 1)
        {
            cout << "Player " << player << ", Enter the number: ";
            cin >> choice;
            mark = 'X';
        }
        else
        {
            choice = findBestMove(square);
            mark = 'O';
        }

        if (choice >= 1 && choice <= 9 && square[choice] == char(choice + 48))
        {
            square[choice] = mark;
        }
        else
        {
            bool check = checkAllBoxesFull();
            if (check)
            {
                cout << "Draw";
                cin.ignore();
                cin.get();
                return 0;
            }
            cout << "Invalid move!" << endl;
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();

        player++;
    } while (i == 0);

    board();
    if (player - 1 == 1)
        cout << "You Win" << endl;
    else
        cout << "You lose" << endl;
    cin.ignore();
    cin.get();
    return 0;
}
