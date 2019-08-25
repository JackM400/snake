#include <iostream>
#include <synchapi.h>
#include <conio.h>

using namespace std;
bool gameRunning = true;
int score;
int width = 20;
int height = 20;
int snakeX;
int snakeY;
int foodX;
int foodY;

enum snakeDirection {
    STATIONARY = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
snakeDirection direction;


void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            //quit / pause
            case 'p':
                gameRunning = false;
                break;
                //up
            case 'w':
                direction = UP;
                break;
                //down
            case 's':
                direction = DOWN;
                break;
                //left
            case 'a':
                direction = LEFT;
                break;
                //right
            case 'd':
                direction = RIGHT;
                break;

        }
    }
}

void Draw() {
    /*
   //target design
   //  ^^^^^^^^^^^^^
   //  ^           ^
   //  ^           ^
   //  ^^^^^^^^^^^^^
    system("cls");\
   //make screen
    //width = height == square screen
     */
    system("cls"); //system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << " ^"; //top
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << " < "; //L.side



            //Game Screen
            if (j == snakeX && i == 7) {
                cout << "O "; //snake head
            } else if (j == foodX && i == foodY) {
                cout << "* "; //FOOD [* . ,]
            } else {
                cout << "  ";
            }


            if (j == width - 1)
                cout << " > "; //R.side
        }
        cout << endl;
    }

    for (int i = 0; i < width + 3; i++)
        cout << " ^"; //bottom
    cout << endl;
    cout << "Score: " << score << endl;

}

void Setup() {
    gameRunning = true;
    score = 0;
    direction = STATIONARY;
    // snake in middle
    snakeX = width / 5;
    snakeY = height / 5;
    foodX = rand() % width;
    foodY = rand() % height;

}

void GameLogic() {
    switch (direction) {
        case UP:
            snakeY++;
            break;
        case DOWN:
            snakeY--;
            break;
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
    }
    //hit boarder
    if (snakeX < 0 || snakeX > width || snakeY < 0 || snakeY > height) {
        cout << "GAME OVER";
        gameRunning = false;
    }
    //eat food
    if (snakeX == foodX && snakeY == foodY){
        score++;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main() {
    Setup();
    while (gameRunning) {
        GameLogic();
        Input();
        Draw();
        gameRunning = false;
        Sleep(10);
    }
    cout << "Snake Game" << std::endl;
    return 0;
}