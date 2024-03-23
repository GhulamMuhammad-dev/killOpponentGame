#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For _getch()

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        std::system("cls"); // For Windows
    #else
        std::system("clear"); // For Unix-like systems
    #endif
}

class Pawn {
private:
    int position;
public:
    Pawn() : position(0) {}
    int getPosition() const { return position; }
    void setPosition(int newPos) { position = newPos; }
};

class Board {
private:
    std::vector<std::vector<char>> board;
public:
    Board() {
        board.resize(10, std::vector<char>(10, '-')); // Initialize the board with empty spaces
        // Place player 1 pawns ('$') in the first column
        for (int i = 0; i < 10; ++i)
            board[i][0] = '$';
        // Place player 2 pawns ('&') in the last column
        for (int i = 0; i < 10; ++i)
            board[i][9] = '&';
    }
    void display() const {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
    }

    // Method to access elements by row and column
    char& at(int row, int col) {
        return board[row][col];
    }

    // Method to get the size of the board
    int size() const {
        return board.size();
    }
};

class Player {
public:
    int chooseRow() {
        int row;
        std::cout << "Enter row number: ";
        std::cin >> row;
        return row;
    }
};

class AI {
public:
    int chooseRow() {
        return rand() % 10; // AI chooses a row randomly
    }
};

class Game {
private:
    Board board;
    Player player1;
    AI player2;
    bool gameOver;

    int rollDice() {
        return rand() % 6 + 1; // Generate a random number between 1 and 6
    }

    bool checkWinCondition() {
        // Check if player 1's pawns have reached the last column
        for (int i = 0; i < board.size(); ++i) {
            if (board.at(i, 9) == '$') {
                return true;
            }
        }
        // Check if player 2's pawns have reached the first column
        for (int i = 0; i < board.size(); ++i) {
            if (board.at(i, 0) == '&') {
                return true;
            }
        }
        return false;
    }

public:
    Game() : gameOver(false) {}

    void movePawn(int player, int row, int steps) {
        // Move the pawn of the specified player by the specified number of steps
        if (player == 1) {
            // Player 1 moves to the right (increasing column)
            for (int i = 0; i < steps; ++i) {
                if (board.at(row, i) == '$') {
                    board.at(row, i) = '-';
                    board.at(row, i + 1) = '$';
                }
            }
        } else {
            // Player 2 moves to the left (decreasing column)
            for (int i = 9; i > 9 - steps; --i) {
                if (board.at(row, i) == '&') {
                    board.at(row, i) = '-';
                    board.at(row, i - 1) = '&';
                }
            }
        }
    }

    void start() {
        while (!gameOver) {
            clearScreen();
            board.display();

            // Player 1's turn
            std::cout << "Player 1, press 'p' to roll the dice: ";
            char key;
            do {
                key = _getch(); // Get a character without echoing it
            } while (key != 'p'); // Wait for 'p' to be pressed
            int diceRoll = rollDice();
            std::cout << "Player 1 rolled: " << diceRoll << std::endl;
            int chosenRow = player1.chooseRow();
            movePawn(1, chosenRow, diceRoll);

            clearScreen();
            board.display();

            // Check if player 1 wins
            if (checkWinCondition()) {
                std::cout << "Player 1 wins!\n";
                break;
            }

            // AI's turn
            int aiChosenRow = player2.chooseRow();
            int aiDiceRoll = rollDice();
            std::cout << "AI rolled: " << aiDiceRoll << std::endl;
            movePawn(2, aiChosenRow, aiDiceRoll);

            clearScreen();
            board.display();

            // Check if AI wins
            if (checkWinCondition()) {
                std::cout << "AI wins!\n";
                break;
            }
        }
    }
};

int main() {
    srand(time(nullptr)); // Seed the random number generator
    Game game;
    game.start();
    return 0;
}
