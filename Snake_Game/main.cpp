#include <iostream>
#include <conio.h>
using namespace std;

enum dir{
    STOP=0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

const int width = 10;
const int height = 5;
int x,y,fx,fy,score;

dir d;
bool gameOver;


void setup(){
    gameOver = false;
    d = RIGHT;
    score = 0;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
}

void draw(){
    system("clear");
    for(int i = 0;i < width;i++) cout << "#";
    cout << "\n";
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            if(j == 0 || j == width - 1) cout << "#";
            else if(i == fy & j == fx) cout << "0";
            else if(i == y && j == x) cout << "s";
            else cout << " ";
        }
        cout << "\n";
    }
    for(int i = 0;i < width;i++) cout << "#";
    cout << "\n";
}

void update(){
    // if(x == width || y == height || x < 0 || y < 0) gameOver = true;
    switch (d){
    case STOP:
        gameOver = true;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if(x == fx && y == fy){
        score++;
        fx = rand() % (width + 1);
        fy = rand() % (height + 1);
    }
}

void input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            d = LEFT;
            break;
        case 'd':
            d = RIGHT;
            break;
        case 'w':
            d = UP;
            break;
        case 's':
            d = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}


int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        update();
        // sleep(10);
    }
    cout << score << "\n";
    return 0;
}