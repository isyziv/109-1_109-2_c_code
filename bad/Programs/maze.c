#include <stdio.h>
#include <stdlib.h> 

void visit(int, int);
int maze[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},
                  {2, 0, 2, 2, 0, 2, 2, 0, 2},
                  {2, 0, 2, 0, 0, 2, 0, 0, 2},
                  {2, 0, 2, 0, 2, 0, 2, 0, 2},
                  {2, 0, 0, 0, 0, 0, 2, 0, 2},
                  {2, 2, 0, 2, 2, 0, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},
                  {2, 2, 2, 2, 2, 2, 2, 2, 2}};

int startI = 1, startJ = 1;  // 入口
int endI = 7, endJ = 7;  // 出口

int main(void) { 
    int i, j; 

    printf("顯示迷宮：\n"); 
    for(i = 0; i < 9; i++) { 
        for(j = 0; j < 9; j++) 
            if(maze[i][j] == 2) 
                printf("█"); 
            else 
                printf("  "); 
        printf("\n"); 
    } 

    visit(startI, startJ);
    system("pause");
    return 0; 
} 

void visit(int i, int j) {
    int m, n;

    maze[i][j] = 1; 

    if(i == endI && j == endJ) {
        printf("\n顯示路徑：\n");
        for(m = 0; m < 9; m++) {
            for(n = 0; n < 9; n++)
                if(maze[m][n] == 2)
                    printf("█");
                else if(maze[m][n] == 1)
                    printf("◇");
                else
                    printf("  ");
            printf("\n");
        }
    }

    if(maze[i][j+1] == 0) visit(i, j+1); //right
    if(maze[i+1][j] == 0) visit(i+1, j); //down
    if(maze[i][j-1] == 0) visit(i, j-1); //left
    if(maze[i-1][j] == 0) visit(i-1, j); //up

    maze[i][j] = 0;
}  

