#include<stdio.h>
#include<stdbool.h>

#define PASS 60

typedef struct Course{
    int sid;
    int student_id;
    int course_id;
    int score;
    int numTests;
    int average;
}Course;


bool findStudent(int studentNum, int length, Course arr[]);
bool findStudentNum(int studentNum, int length, int arr[]);
int findSid(int sid, int length, Course arr[]);

int main(){
    int studentCount = 0;
    int failedCount = 0;
    int sid, score;
    int courseNum;
    int scoreNum;

    scanf("%d %d", &courseNum, &scoreNum);
    Course courses[courseNum];
    int failures[courseNum];

    for(int i = 0; i < courseNum; i++){
        scanf("%d %d %d", &courses[i].sid, &courses[i].student_id, &courses[i].course_id);
        //check previous records for existing student
        courses[i].score = 0;
        courses[i].numTests = 0;
        courses[i].average = 0;
        if (!findStudent(courses[i].student_id, i, courses)){
            studentCount++;
        }
    }

    for(int i = 0; i < scoreNum; i++){
        scanf("%d %d", &sid, &score);
        int index = findSid(sid, courseNum, courses);
        courses[index].score += score;
        courses[index].numTests++;
        courses[index].average = courses[index].score / courses[index].numTests;
    }

    for(int i = 0; i < courseNum; i++){
        if (courses[i].average < PASS){
            if(!(findStudentNum(courses[i].student_id, i, failures))){
                failures[failedCount] = courses[i].student_id;
                failedCount++;
            }
        }
    }

    printf("%d %d", studentCount, failedCount);

    return 0;
}

bool findStudent(int studentNum, int length, Course arr[]){
    for(int i = 0; i < length; i++){
        if (arr[i].student_id == studentNum) return true;
    }
    return false;
}

int findSid(int sid, int length, Course arr[]){
    for(int i = 0; i < length; i++){
        if(arr[i].sid == sid) return i;
    }
    return - 1;
}

bool findStudentNum(int studentNum, int length, int arr[]){
    for(int i = 0; i < length; i++){
        if (arr[i] == studentNum) return true;
    }
    return false;
}
