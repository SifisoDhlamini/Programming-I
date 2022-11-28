#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "grade.txt"
#define MAX_REMIND 50
#define MSG_LEN 5

typedef struct{
    float avg;
    char stu_id[MSG_LEN];
    int c_class;
    int cs_class;
    int math_class;
}GradeRec;

int cmpfunc_1(const void *a, const void *b){
    GradeRec *x=(GradeRec *)a;
    GradeRec *y=(GradeRec *)b;

    return(y->avg - x->avg);
}

int main(void){
    FILE *fp;
    char str[30];
    char name[10];
    int i,j,k;
    GradeRec score_arr[MAX_REMIND]={0};
    int num_rec=0;

    fp = fopen(FILE_NAME, "r");
    if(fp==NULL){
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    while(fgets(str,sizeof(str),fp)!=NULL){
        sscanf(str,"%s%d%d%d",name,&i,&j,&k);
        printf("%s %3d %3d %3d\n",name,i,j,k);
        strcpy(score_arr[num_rec].stu_id,name);
        score_arr[num_rec].c_class=i;
        score_arr[num_rec].cs_class=j;
        score_arr[num_rec].math_class=k;
        score_arr[num_rec].avg=(i+j+k)/3.0;
        num_rec++;
    }

    fclose(fp);
    qsort(score_arr, MAX_REMIND, sizeof(GradeRec),cmpfunc_1);
    printf("Sorting by average: \n");

    int n=0;
    for(n = 0; n < num_rec; n++){
        //if(score_arr[n].avg!=0){
            printf("%s %d %d %d %3.1f\n", score_arr[n].stu_id,score_arr[n].c_class,score_arr[n].cs_class,score_arr[n].math_class,score_arr[n].avg);
        //}
    }
    return 0;
}
