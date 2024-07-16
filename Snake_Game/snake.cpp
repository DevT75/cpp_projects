#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;

int N = 30,M = 20,size = 16,num = 1,dir,score = 0;
int w = size * N ,h = size * M;
bool gameOver = false;

struct Snake{
    int x,y;
}s[100];

struct Fruit{
    int x,y;
}f;

void Tick(){
    int j = num;
    while(j > 0){
        s[j].x = s[j - 1].x;
        s[j].y = s[j - 1].y;
        j--;
    }
    if(dir == 0) s[0].y++;
    if(dir == 1) s[0].x++;
    if(dir == 2) s[0].y--;
    if(dir == 3) s[0].x--;

    if(s[0].x == f.x && s[0].y == f.y){
        score += 10;
        num++;
        f.x = rand() % N;
        f.y = rand() % M;
    }
    if(s[0].x > N) s[0].x = 0;if(s[0].x < 0) s[0].x = N;
    if(s[0].y > M) s[0].y = 0;if(s[0].y < 0) s[0].y = M;

    for(int i = 1;i < num;i++){
        if(s[0].x == s[i].x && s[0].y == s[i].y) num = i;
    }

}

int main(){
    srand(time(0));
    RenderWindow window(VideoMode(w, h), "Snake Game");
    Texture t1,t2;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    Sprite s1,s2;
    s1.setTexture(t1);
    s2.setTexture(t2);
    Clock c;
    float timer = 0,delay = 0.08;
    f.x = 10;f.y = 10;
    while (window.isOpen()){
        float time = c.getElapsedTime().asSeconds();
        c.restart();
        timer += time;
        Event e;
        while(window.pollEvent(e)){
            if(e.type  == Event::Closed) window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
        if(Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
        if(Keyboard::isKeyPressed(Keyboard::Up)) dir = 2;
        if(Keyboard::isKeyPressed(Keyboard::Down)) dir = 0;

        if(timer > delay){
            timer = 0;
            Tick();
        }
        window.clear();
        if(!gameOver){
            for(int i = 0;i < N;i++){
                for(int j = 0;j < M;j++){
                    s1.setPosition(i*size,j*size);
                    window.draw(s1);
                }
            }
            for(int i = 0;i < num;i++){
                s2.setPosition(s[i].x*size,s[i].y*size);
                window.draw(s2);
            }
            s2.setPosition(f.x*size,f.y*size);
            window.draw(s2);            
        }
        else{

        }
        window.display();
    }

    return 0;
}