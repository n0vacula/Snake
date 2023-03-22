#include "Snake.hpp"

int    wide = 20;
int    hight = 20;
int    event = 0;
int    lenth = 0;
char   derection;

int main(int argc, char const *argv[]){


    int pixcount = wide * hight;
    int lenth = 0;

    struct pixel pixels[pixcount];
    //std::string type[pixcount];
    int headindex = gameinit( &pixels[0]);
    struct snake *head = nullptr;
    head = new snake;
    head -> pixel = &pixels[headindex];
    head -> next = nullptr;
    head -> pre = nullptr;

    food(&pixels[0]);
    char ch;
    while (event != 99) {
        move(head,derection);
        switch (event){
        case 1:
            food(&pixels[0]);
            break;
        case 2:
            gameover();
            break;
        default:
            break;
        }
        display(&pixels[0]);
        if ( kbhit() ) {
            ch = getch();
            derection = ch;
            display(&pixels[0]);
        }
        Sleep(650);
    }
    return 0;
}