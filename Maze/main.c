#define SZ 5
#include <stdio.h>
#include <string.h>
#include "maze.h"

void print_solution(char* matrix,int sz){
    for (int i = 0; i < sz * sz; i++){
        printf("%c ",matrix[i]);
        if (i % sz == (sz-1)){
            printf("\n");
        }
    }
}

int main(){
    char tmaze[SZ+1][SZ+1]={
        "*x   ",
        "  x  ",
        "  x  ",
        "  x  ",
        "     ",
    };
    char maze[SZ*SZ];
    memset(maze,' ',SZ*SZ);
    for (int i= 0; i < SZ; i++){
        for (int j= 0; j < SZ; j++){
            if (tmaze[i][j] == 'x'){
                maze[i*SZ+j] = 'x';
            }
        }
    }
    int r = solve_maze(maze,SZ);
    if (!r){
        printf("Nenasiel som riesenie\n");
    }
    print_solution(maze,SZ);

    return 0;
}