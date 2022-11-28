#include <stdio.h>
#include <stdlib.h>
#define true  1
#define false 0


//0 means walkable, 1 means wall, 2 means visited
int solve(int start_r, int start_c, int size);

int maze[1000][1000];
int recursion_counter;
int main()
{

    int size;

    //read size and maze

    scanf("%d",&size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j<size; j++){
            scanf("%d",&maze[i][j]);
            //maze[i][j] = 0;
        }
    }

    if(maze[0][0] == 1){
        printf("No");
        //printf("\n%d",recursion_counter);
    }
    else if(solve(0,0,size)){
        printf("Yes");
        //printf("\n%d",recursion_counter);
    }
    else{
        printf("No");
        //printf("\n%d",recursion_counter);
    }


}


int solve(int start_r, int start_c, int size){

    if(start_r == size-1 && start_c == size-1){
        return true;
    }
    maze[start_r][start_c] = 2;//When it walks it marks the spaces where it stands
    if(start_c+1 < size && maze[start_r][start_c+1] == 0){//right
        if(solve(start_r, start_c+1, size)){
            recursion_counter++;
            return true;
            }
        }
    if(start_r+1 < size && maze[start_r+1][start_c] == 0){//down
        if(solve(start_r+1, start_c, size)){
            recursion_counter++;
            return true;
            }
        }
   if(start_r-1 >= 0 && maze[start_r-1][start_c] == 0){//up
        if(solve(start_r-1, start_c, size)){
            recursion_counter++;
            return true;
            }
        }
    if(start_c-1 >= 0 && maze[start_r][start_c-1] == 0){//left
        if(solve(start_r, start_c-1, size)){
            recursion_counter++;
            return true;
            }
        }

    //maze[start_r][start_c] = 0;//When it backtracks, it cleans the 2 [already visited spaces]

    return false;
}
