#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

const int SIZE = 4;  // Размер игрового поля

enum Direction { UP, DOWN, LEFT, RIGHT };

class Game2048 {
public:
    Game2048() {
        // Инициализация поля
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = 0;
            }
        }

        // Генерация первых двух чисел
        generateNumber();
        generateNumber();
    }

    void play() {
        while (true) {
            std::system("cls");
            // Вывод текущего состояния поля
            std::cout << "Score: " << getScore() << std::endl;
            drawBoard();

            if (isGameWin()) {
                std::cout << "Game Win!" << std::endl;
                break;
            }
            // Проверка на проигрыш
            if (isGameOver()) {
                std::cout << "Game Over!" << std::endl;
                break;
            }
            
            // Ввод направления движения
            Direction dir = getDirection();

            bool flagus = false;

            if (moveTiles(dir, false) || mergeTiles(dir, false)) {
                flagus = true;
            }

            // Выполнение движения и слияния клеток
            moveTiles(dir, true);
            mergeTiles(dir, true);
            moveTiles(dir, true);

            // Генерация новой клетки
            if (flagus) {
                generateNumber();
            }
        }
    }

private:
    int board[SIZE][SIZE];

    void drawBoard() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << "+----";
            }
            std::cout << "+" << std::endl;

            for (int j = 0; j < SIZE; ++j) {
                std::cout << "|";
                if (board[i][j] == 0) {
                    std::cout << std::setw(4) << "";
                }
                else {
                    std::cout << std::setw(4) << board[i][j];
                }
            }
            std::cout << "|" << std::endl;
        }

        for (int j = 0; j < SIZE; ++j) {
            std::cout << "+----";
        }
        std::cout << "+" << std::endl;
    }

    void generateNumber() {
        // Поиск пустой клетки
        int emptyTiles[SIZE * SIZE][2];
        int count = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    emptyTiles[count][0] = i;
                    emptyTiles[count][1] = j;
                    count++;
                }
            }
        }
        if (count == 0) {
            return;
        }
        // Генерация случайного числа 2 или 4
        std::srand(std::time(0));
        int index = std::rand() % count;
        int value = (std::rand() % 2 + 1) * 2;

        // Вставка числа в пустую клетку
        int x = emptyTiles[index][0];
        int y = emptyTiles[index][1];
        board[x][y] = value;
    }

    // Функция для проверки, является ли текущее состояние игрового поля победным
    bool isGameWin() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 8192) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isGameOver() {
        // Проверка на наличие пустых клеток
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        // Проверка на возможность слияния клеток
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE - 1; ++j) {
                if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i]) {
                    return false;
                }
            }
        }

        return true;
    }

    int getScore() {
        // Вычисление текущего счета
        int score = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                score += board[i][j];
            }
        }
        return score;
    }

    Direction getDirection() {
        char input;
        std::cout << "Enter direction (W - up, S - down, A - left, D - right, Q - quit): ";
        input = _getch();

        switch (input) {
        case 'W':
        case 'w':
            return UP;
        case 'S':
        case 's':
            return DOWN;
        case 'A':
        case 'a':
            return LEFT;
        case 'D':
        case 'd':
            return RIGHT;
        case 'q':
        case 'Q':
            exit(0);
        default:
            break;
        }
    }

    bool moveTiles(Direction dir, bool flag) {
        bool moved = false;
        for (int i = 0; i < SIZE; ++i) {
            switch (dir) {
            case UP:
                for (int j = 0; j < SIZE - 1; ++j) {
                    for (int k = j + 1; k < SIZE; ++k) {
                        if (board[k][i] != 0) {
                            if (board[j][i] == 0) {
                                if (flag) {
                                    board[j][i] = board[k][i];
                                    board[k][i] = 0;
                                }
                                moved = true;
                            }
                            break;
                        }
                    }
                }
                break;

            case DOWN:
                for (int j = SIZE - 1; j > 0; --j) {
                    for (int k = j - 1; k >= 0; --k) {
                        if (board[k][i] != 0) {
                            if (board[j][i] == 0) {
                                if (flag) {
                                    board[j][i] = board[k][i];
                                    board[k][i] = 0;
                                }
                                moved = true;
                            }
                            break;
                        }
                    }
                }
                break;

            case LEFT:
                for (int j = 0; j < SIZE - 1; ++j) {
                    for (int k = j + 1; k < SIZE; ++k) {
                        if (board[i][k] != 0) {
                            if (board[i][j] == 0) {
                                if (flag) {
                                    board[i][j] = board[i][k];
                                    board[i][k] = 0;
                                }
                                moved = true;
                            }
                            break;
                        }
                    }
                }
                break;

            case RIGHT:
                for (int j = SIZE - 1; j > 0; --j) {
                    for (int k = j - 1; k >= 0; --k) {
                        if (board[i][k] != 0) {
                            if (board[i][j] == 0) {
                                if (flag) {
                                    board[i][j] = board[i][k];
                                    board[i][k] = 0;
                                }
                                moved = true;
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
        return moved;
    }

    int mergeTiles(Direction dir, bool flag) {
        bool merged = false;
        for (int i = 0; i < SIZE; ++i) {
            switch (dir) {
            case UP:
                for (int j = 0; j < SIZE - 1; ++j) {
                    if (board[j][i] != 0 && board[j][i] == board[j + 1][i]) {
                        if (flag) {
                            board[j][i] += board[j + 1][i];
                            board[j + 1][i] = 0;
                        }
                        merged = true;
                    }
                }
                break;

            case DOWN:
                for (int j = SIZE - 1; j > 0; --j) {
                    if (board[j][i] != 0 && board[j][i] == board[j - 1][i]) {
                        if (flag) {
                            board[j][i] += board[j - 1][i];
                            board[j - 1][i] = 0;
                        }
                        merged = true;
                    }
                }
                break;

            case LEFT:
                for (int j = 0; j < SIZE - 1; ++j) {
                    if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
                        if (flag) {
                            board[i][j] += board[i][j + 1];
                            board[i][j + 1] = 0;
                        }
                        merged = true;
                    }
                }
                break;

            case RIGHT:
                for (int j = SIZE - 1; j > 0; --j) {
                    if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
                        if (flag) {
                            board[i][j] += board[i][j - 1];
                            board[i][j - 1] = 0;
                        }
                        merged = true;
                    }
                }
                break;
            }
        }
        return merged;
    }
};

int main() {
    while (true) {
        Game2048 game;
        game.play();
        std::cout << "Play again?\nNo - press 'q'\nYes - press any key" << std::endl;
        char input = _getch();
        switch (input) {
        case 'Q':
        case 'q':
            exit(0);
        }
    }

    return 0;
}