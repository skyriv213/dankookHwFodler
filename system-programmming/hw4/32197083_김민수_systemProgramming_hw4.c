/*
The corresponding code is the 4th code for my system programming task. 
I used some codes for this task. 

If you have any questions after reading the corresponding code, 
please send me an email. 
You can send the email address to gn1007@dankook.ac.kr or ip014767@gmail.com .
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>

#define MAX_COURSES 20
#define SWAP(a, b, temp) {temp=a; a=b; b=temp;}

struct timeval stime, etime, gap;  // timeval 구조체 변수 선언

// 함수 프로토타입
void sort_ver1(int n, int arr[]);
void sort_ver2(int n, int arr[]);
void shuffle(int *a, int n);  // Function prototype for shuffle
void printArr(int n, int arr[]);
void measureTime(void (*sortFunc)(int, int[]), int n, int arr[], const char* sortName);

void ver1(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]);
void ver2(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]);
void ver3(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]);
void ver4(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]);
void measureTime2(void (*solveFunc)(char [][50], char [][3], double []), char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES], const char* solName);


int main() {
    int n = 5000;  // 고정된 입력값
    int arr[n];
    int arr2[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    shuffle(arr,n);

    for(int i = 0;i<n;i++){
        arr2[i]=arr[i];
    }

    char names[MAX_COURSES][50] = {
        "ObjectOrientedProgramming1", "IntroductiontoComputerEngineering", "ObjectOrientedProgramming2",
        "CreativeComputerEngineeringDesign", "AssemblyLanguage", "InternetProgramming",
        "ApplicationProgramminginJava", "SystemProgramming", "OperatingSystem",
        "WirelessCommunicationsandNetworking", "LogicCircuits", "DataStructure", "MicroprocessorApplication",
        "EmbeddedSoftware", "ComputerSecurity", "Database", "Algorithm", "CapstoneDesigninCSE",
        "CompilerDesign", "ProblemSolving"
    };

    double credits[MAX_COURSES] = {
        3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.0
    };


    char grades[MAX_COURSES][3] = {
        "A+", "A+", "A0", "A+", "A+", "B0", "A0", "B0", "B0", "C+", "B0", "A+", "B+", "C0", "D+", "C+", "B0", "B+", "D0", "P"
    };


    printf("code efficient\n");
    measureTime(sort_ver1,n,arr,"sort_ver1");
    measureTime(sort_ver2,n,arr2,"sort_ver2");
    printf("loop unrolling\n");
    measureTime2(ver1, names, grades, credits, "ver1");
    measureTime2(ver2, names, grades, credits, "ver2");
    measureTime2(ver3, names, grades, credits, "ver3");
    measureTime2(ver4, names, grades, credits, "ver4");


    return 0;
}


void shuffle(int *a, int n) { // 배열 랜덤하게 섞어준다
    srand(time(NULL));
    int t, i;
    int rn;

    for (i = 0; i < n - 1; i++) {
        rn = rand() % (n - i) + i;
        SWAP(a[i], a[rn], t);
    }
}

void measureTime(void (*sortFunc)(int, int[]), int n, int arr[], const char* sortName) {
    gettimeofday(&stime, NULL);
    sortFunc(n, arr);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = etime.tv_usec - stime.tv_usec;
    
    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec = gap.tv_usec + 1000000;
    }
    
    printf("%s: %ldsec :%dusec\n", sortName, gap.tv_sec, gap.tv_usec);
}

void measureTime2(void (*solveFunc)(char [][50], char [][3], double []), char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES], const char* solName) {
    gettimeofday(&stime, NULL);
    solveFunc(names, grades, credits);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = etime.tv_usec - stime.tv_usec;

    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec = gap.tv_usec + 1000000;
    }

    printf("%s: %ldsec :%dusec\n", solName, gap.tv_sec, gap.tv_usec);
}


void sort_ver1(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[temp]) {
                temp = j;
            }
        }
        int tempValue;
        SWAP(arr[i],arr[temp],tempValue);
    }
}

void sort_ver2(int n, int arr[]) {
    int i,temp, j,tempValue;
    for (i = 0; i < n - 1; i++) {
        temp = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[temp]) {
                temp = j;
            }
        }
        tempValue = arr[i];
        arr[i] = arr[temp];
        arr[temp] = tempValue;
    }
}


void ver1(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]) {
    double sumCredit = 0.0;
    double res = 0.0;

    for (int i = 0; i < MAX_COURSES; i++) {
        double temp;
        if (grades[i][0] == 'P') continue;

        sumCredit += credits[i];
        if (grades[i][0] == 'F') continue;

        if (grades[i][0] == 'A')
            temp = 4;
        else if (grades[i][0] == 'B')
            temp = 3;
        else if (grades[i][0] == 'C')
            temp = 2;
        else
            temp = 1;

        if (grades[i][1] == '+') temp += 0.5;

        res += credits[i] * temp;
    }
    printf("%lf\n", res / sumCredit);
    
}

void ver2(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]) {
    double sumCredit = 0.0;
    double res = 0.0;
    double temp1, temp2;

    for (int i = 0; i < MAX_COURSES; i += 2) {

        if (grades[i][0] == 'P') continue;
        sumCredit += credits[i];
        if (grades[i][0] == 'F') continue;

        if (grades[i][0] == 'A') temp1 = 4;
        else if (grades[i][0] == 'B') temp1 = 3;
        else if (grades[i][0] == 'C') temp1 = 2;
        else temp1 = 1;

        if (grades[i][1] == '+') temp1 += 0.5;

        res += credits[i] * temp1;

        // Process the next iteration
        if (i + 1 < MAX_COURSES) {
            if (grades[i + 1][0] == 'P') continue;
            sumCredit += credits[i + 1];
            if (grades[i + 1][0] == 'F') continue;

            if (grades[i + 1][0] == 'A') temp2 = 4;
            else if (grades[i + 1][0] == 'B') temp2 = 3;
            else if (grades[i + 1][0] == 'C') temp2 = 2;
            else temp2 = 1;

            if (grades[i + 1][1] == '+') temp2 += 0.5;

            res += credits[i + 1] * temp2;
        }
    }

    printf("%lf\n", res / sumCredit);
}


void ver3(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]) {
    double sumCredit = 0.0;
    double res = 0.0;
    double temp1, temp2, temp3;


    for (int i = 0; i < MAX_COURSES; i += 3) {

        if (grades[i][0] == 'P') continue;
        sumCredit += credits[i];
        if (grades[i][0] == 'F') continue;

        if (grades[i][0] == 'A') temp1 = 4;
        else if (grades[i][0] == 'B') temp1 = 3;
        else if (grades[i][0] == 'C') temp1 = 2;
        else temp1 = 1;

        if (grades[i][1] == '+') temp1 += 0.5;

        res += credits[i] * temp1;

        // Process the next iteration
        if (i + 1 < MAX_COURSES) {
            if (grades[i + 1][0] == 'P') continue;
            sumCredit += credits[i + 1];
            if (grades[i + 1][0] == 'F') continue;

            if (grades[i + 1][0] == 'A') temp2 = 4;
            else if (grades[i + 1][0] == 'B') temp2 = 3;
            else if (grades[i + 1][0] == 'C') temp2 = 2;
            else temp2 = 1;

            if (grades[i + 1][1] == '+') temp2 += 0.5;

            res += credits[i + 1] * temp2;
        }

        // Process the next iteration
        if (i + 2 < MAX_COURSES) {
            if (grades[i + 2][0] == 'P') continue;
            sumCredit += credits[i + 2];
            if (grades[i + 2][0] == 'F') continue;

            if (grades[i + 2][0] == 'A') temp3 = 4;
            else if (grades[i + 2][0] == 'B') temp3 = 3;
            else if (grades[i + 2][0] == 'C') temp3 = 2;
            else temp3 = 1;

            if (grades[i + 2][1] == '+') temp3 += 0.5;

            res += credits[i + 2] * temp3;
        }
    }

    printf("%lf\n", res / sumCredit);
}

void ver4(char names[MAX_COURSES][50], char grades[MAX_COURSES][3], double credits[MAX_COURSES]) {
    // Implement your code for version 4 here
    double sumCredit = 0.0;
    double res = 0.0;
    double temp1, temp2, temp3, temp4;

    for (int i = 0; i < MAX_COURSES; i += 4) {

        if (grades[i][0] == 'P') continue;
        sumCredit += credits[i];
        if (grades[i][0] == 'F') continue;

        if (grades[i][0] == 'A') temp1 = 4;
        else if (grades[i][0] == 'B') temp1 = 3;
        else if (grades[i][0] == 'C') temp1 = 2;
        else temp1 = 1;

        if (grades[i][1] == '+') temp1 += 0.5;

        res += credits[i] * temp1;

        // Process the next iteration
        if (i + 1 < MAX_COURSES) {
            if (grades[i + 1][0] == 'P') continue;
            sumCredit += credits[i + 1];
            if (grades[i + 1][0] == 'F') continue;

            if (grades[i + 1][0] == 'A') temp2 = 4;
            else if (grades[i + 1][0] == 'B') temp2 = 3;
            else if (grades[i + 1][0] == 'C') temp2 = 2;
            else temp2 = 1;

            if (grades[i + 1][1] == '+') temp2 += 0.5;

            res += credits[i + 1] * temp2;
        }

        // Process the next iteration
        if (i + 2 < MAX_COURSES) {
            if (grades[i + 2][0] == 'P') continue;
            sumCredit += credits[i + 2];
            if (grades[i + 2][0] == 'F') continue;

            if (grades[i + 2][0] == 'A') temp3 = 4;
            else if (grades[i + 2][0] == 'B') temp3 = 3;
            else if (grades[i + 2][0] == 'C') temp3 = 2;
            else temp3 = 1;

            if (grades[i + 2][1] == '+') temp3 += 0.5;

            res += credits[i + 2] * temp3;
        }

        // Process the next iteration
        if (i + 3 < MAX_COURSES) {
            if (grades[i + 3][0] == 'P') continue;
            sumCredit += credits[i + 3];
            if (grades[i + 3][0] == 'F') continue;

            if (grades[i + 3][0] == 'A') temp4 = 4;
            else if (grades[i + 3][0] == 'B') temp4 = 3;
            else if (grades[i + 3][0] == 'C') temp4 = 2;
            else temp4 = 1;

            if (grades[i + 3][1] == '+') temp4 += 0.5;

            res += credits[i + 3] * temp4;
        }
    }

    printf("%lf\n", res / sumCredit);
}
