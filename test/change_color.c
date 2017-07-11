#include <stdio.h>
#include "../gammaru_game.h"

int main(){
    system("clear");
    int v = 0;
    int count = 0;
    while(1){
        count++;
        v++;
        v%=7;
        letter_color(v+30);
        if(count%300000 == 0){
            gotoxy(10,10);
            printf("(%d %d)",10,10);
            gotoxy(40,10);
            printf("(%d %d)",40,10);
            gotoxy(10,20);
            printf("(%d %d)",10,20);
            gotoxy(40,20);
            printf("(%d %d)",40,20);
        }


        color_clear();
    }
}
