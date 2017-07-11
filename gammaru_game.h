#ifndef GAMMARU_GAME_H_
#define GAMMARU_GAME_H_
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define BLACK       30
#define RED         31
#define GREEN       32
#define YELLOW      33
#define BLUE        34
#define PINK        35
#define LIGHT_BLUE  36
#define WHITE       37

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}
void gotoxy(int x, int y){
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}

void letter_color(int code){
    assert(BLACK<= code && code <= WHITE);
    printf("\x1b[%dm",code);
}
void background_color(int code){
    assert(BLACK<= code && code <= WHITE);
    printf("\x1b[%dm",code+10);
}
void color_clear(){
    printf("\x1b[0m");
}
#endif
