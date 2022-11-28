#include <stdio.h>

int main(void)
{
    int numsandchars[1000];
    int i=0,turn=1;

    do{
            if(turn==1){scanf("%d",&numsandchars[i]);++i;turn=0;}
            else {scanf("%s",&numsandchars[i]);++i;turn=1;}
    }while(getchar()==32);

    int result=numsandchars[0];
    for(int z=1;z<i;z+=2){
            switch (numsandchars[z]){
                case 42: result*=numsandchars[z+1];break;
                case 43: result+=numsandchars[z+1];break;
                case 45: result-=numsandchars[z+1];break;
                case 47: result/=numsandchars[z+1];break;
            }
    }

    printf("%d",result);
    return 0;
}
