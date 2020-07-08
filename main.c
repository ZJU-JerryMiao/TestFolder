#include "acllib.h"
#include <stdio.h>
#include "linkedlist.h"
#define width 800
#define height 600
#define charheight 25
#define charwidth  12

int  mode = 0;
int  nowX = 0, nowY = 0;
int  calX(int X);
int  calY(int Y);

void PrintText(void);
void PrintPointer(void);
void PrintTOConsole(void);

void keyListener(int key, int event);
void mouseListener(int x, int y, int bottom, int status);
void timerListener(int id);
void charListener(char c);

List list;

int Setup(
{
    list = list_create();
    initWindow("lineditor",200,200,width,height);
    initConsole();

    registerMouseEvent(mouseListener);
    registerKeyboardEvent(keyListener);
    registerTimerEvent(timerListener);
    registerCharEvent(charListener);

    startTimer(0, 500);

    endPaint();
}

void keyListener(int key, int event)
{
    //printf("%d\n",key);
    if(event == 0){
        switch (key){
            case 8: //backspace
                if(nowX > 0){
                    list_remove(&list, nowX);
                    nowX--;
                }
                PrintPointer();
                break;
            case 13: //enter
                PrintTOConsole();
                break;
            case 37: //left
                if(nowX > 0){
                    nowX--;
                }
                break;
            case 39: //right
                if(nowX < list.length){
                    nowX++;
                }
                break;
            case 45: //ins
                mode = 1 - mode;
                if(nowX != 0){
                    nowX--;
                }
                break;
            case 46: //del
                if(nowX < list.length){
                    list_remove(&list, nowX + 1);
                }
                break;
            default:
                return;
        }
        PrintPointer();
    }
}

void mouseListener(int x, int y, int bottom, int status)
{
    //printf("%d %d\n",bottom , status);
    if(status == 2){
        int temp;
        if(mode == 0){
            temp = (x + charwidth/2) / charwidth;
        }else{
            temp = x / charwidth;
        }
        if(temp >= 0 && temp <= list.length){
            nowX = temp;
            PrintPointer();
        }
    }
}

void timerListener(int id)
{
    static int flag = 0;
    if(id == 0){flag = 1 - flag;}

    if(flag == 1){
        PrintPointer();
    }
    if(flag == 0){
        beginPaint();
        clearDevice();
        endPaint();
        PrintText();
    }
    //printf("%d %d\n",id, flag);
}

void charListener(char c)
{
    if(c != 8 && c != 13) {
        if (nowX > list.length) {
            nowX = list.length;
        }
        if(mode == 1 && nowX != list.length){ //insert case
            list_remove(&list, nowX + 1);
        }
        list_insert(&list, nowX, c);
        nowX++;
        PrintPointer();
    }
}

int  calX(int X)
{
    return X * charwidth;
}
int  calY(int Y)
{
    return Y * charheight;
}

void PrintText(void)
{
    int x = 0, y = 0;
    beginPaint();
    setTextFont("Consolas");
    setTextSize(25);
    for(Node* temp = list.head->next ; temp; temp = temp->next){
        paintText(calX(x), calY(y) ,temp->c);
        x++;
    }
    endPaint();
}

void PrintPointer(void)
{
    beginPaint();
    clearDevice();
    endPaint();

    PrintText();

    beginPaint();
    if(mode == 0){
        setPenWidth(3);
        line(calX(nowX), calY(nowY), calX(nowX), calY(nowY) + charheight);
    }else{
        rectangle(calX(nowX)+2, charheight-10, calX(nowX) + charwidth -2, charheight-2);
    }
    endPaint();
}

void PrintTOConsole(void)
{
    Node* temp = list.head->next;
    while( temp ){
        printf("%c",temp->c[0]);
        temp = temp->next;
    }
    printf("\n");
}