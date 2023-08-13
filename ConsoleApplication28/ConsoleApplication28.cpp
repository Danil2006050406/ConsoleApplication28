// ConsoleApplication28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 10;
const int SHIP_COUNT = 5;
const char EMPTY = '.';
const char SHIP = 'S';
const char HIT = 'X';
const char MISS = 'O';


void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void placeShipsRandomly(vector<vector<char>>& board) {
    for (int i = 0; i < SHIP_COUNT; ++i) {
        int x, y;
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (board[x][y] == SHIP);

        board[x][y] = SHIP;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    
    vector<vector<char>> playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
    vector<vector<char>> computerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));

    
    placeShipsRandomly(playerBoard);
    placeShipsRandomly(computerBoard);

    cout << "Welcome to Battleship!" << endl;
    cout << "Here's your board:" << endl;
    printBoard(playerBoard);

    int playerShipsLeft = SHIP_COUNT;
    int computerShipsLeft = SHIP_COUNT;

    while (playerShipsLeft > 0 && computerShipsLeft > 0) {
        int x, y;

        
        cout << "Enter target coordinates (x y): ";
        cin >> x >> y;

        if (computerBoard[x][y] == SHIP) {
            computerBoard[x][y] = HIT;
            cout << "You hit a ship!" << endl;
            computerShipsLeft--;
        }
        else {
            cout << "You missed." << endl;
            computerBoard[x][y] = MISS;
        }

        
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;

        if (playerBoard[x][y] == SHIP) {
            playerBoard[x][y] = HIT;
            cout << "Computer hit your ship!" << endl;
            playerShipsLeft--;
        }
        else {
            cout << "Computer missed." << endl;
            playerBoard[x][y] = MISS;
        }

        cout << "Your board:" << endl;
        printBoard(playerBoard);
    }

    if (playerShipsLeft == 0) {
        cout << "You lost! Computer wins." << endl;
    }
    else {
        cout << "Congratulations! You sank all computer's ships. You win!" << endl;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
