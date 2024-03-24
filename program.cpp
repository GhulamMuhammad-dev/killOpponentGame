#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

using namespace std;

void clearScreen() {
       system("cls");
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
    vector<vector<char>> board;
public:
    Board() {
        board.resize(10, vector<char>(10, '-')); 
       
        for (int i = 0; i < 10; ++i)
            board[i][0] = '$';
       
        for (int i = 0; i < 10; ++i)
            board[i][9] = '&';
    }
    void display() const {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << ' ';
            }
            cout << '\n';
        }
    }

    char& at(int row, int col) {
        return board[row][col];
    }

    int size() const {
        return board.size();
    }
};

class Player {
public:
    int chooseRow() {
        int row;
        cout << "Enter row number: ";
       cin >> row;
        return row;
    }
};

class AI {
public:
    int chooseRow() {
        return rand() % 10; 
    }
};

class Game {
private:
    Board board;
    Player player1;
    AI player2;
    bool gameOver;

    int rollDice() {
        return rand() % 6 + 1; 
    }

    bool checkWinCondition() {
       
        for (int i = 0; i < board.size(); ++i) {
            if (board.at(i, 9) == '$') {
                return true;
            }
        }
        
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
        
        if (player == 1) {
         
            for (int i = 0; i < steps; ++i) {
                if (board.at(row, i) == '$') {
                    board.at(row, i) = '-';
                    board.at(row, i + 1) = '$';
                }
            }
        } else {
            
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

           cout << "Player 1, press 'p' to roll the dice: ";
            char key;
            do {
                key = _getch(); 
            } while (key != 'p'); 
            int diceRoll = rollDice();
            cout << "Player 1 rolled: " << diceRoll << std::endl;
            int chosenRow = player1.chooseRow();
            movePawn(1, chosenRow, diceRoll);

            clearScreen();
            board.display();

          
            if (checkWinCondition()) {
               cout << "Player 1 wins!\n";
                break;
            }

          
            int aiChosenRow = player2.chooseRow();
            int aiDiceRoll = rollDice();
            cout << "AI rolled: " << aiDiceRoll << std::endl;
            movePawn(2, aiChosenRow, aiDiceRoll);

            clearScreen();
            board.display();

            if (checkWinCondition()) {
               cout << "AI wins!\n";
                break;
            }
        }
    }
};

int main() {
    srand(time(nullptr)); 
    Game game;
    game.start();
    return 0;
}
