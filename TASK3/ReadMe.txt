Tic-Tac-Toe Game Explanation

1.Initialization and Display:

	The square array represents the game board, with each element corresponding to a board position.
	The board() function displays the current game state, including player symbols and Xs and Os.

2.Win and Draw Check:

	The checkAllBoxesFull() function detects if there are unmarked positions left, indicating a draw.
	The checkwin() function examines rows, columns, and diagonals to determine a winner.
	AI Move Calculation (Minimax Algorithm):

	The minimax() function employs the minimax algorithm, simulating future moves to find the AI's best move.
	The algorithm evaluates game states, assigning scores for AI's favorable outcomes and unfavorable ones for the human.
	AI Move Selection:

3.The findBestMove() function utilizes minimax to identify the optimal AI move, considering both AI's and human's potential moves.
Main Game Loop:

4.The main() function houses the game's core logic.
	The game loop continues until a winner or draw occurs, alternating between human and AI turns.
	Player 1 (human) selects X positions; player 2 (AI) employs findBestMove() to determine O placements.
	Final Result:

After the loop, the board's final state displays.
The game result is determined based on a win by player 1 or AI, or a draw