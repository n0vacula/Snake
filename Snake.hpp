#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdio.h>
#include <iostream>
#include <functional>
#include <random>
#include <conio.h>
#include <windows.h>
#include <ctime>

void display(struct pixel* pixels);
int gameinit(struct pixel* pixels);
void food(struct pixel* pixels);
int randint(int max, int min);
int getindex(int x, int y);
void move(struct snake* head, char ch);
void gameover();
char keydetect();

extern int wide;
extern int hight;
extern int lenth;
extern int event;
extern char derection;

  

struct pixel{
    std::string type ;
};

struct snake
{
    struct pixel * pixel;
    struct snake * next;
    struct snake * pre;
};


#endif



