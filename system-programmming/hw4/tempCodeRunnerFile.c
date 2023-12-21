/*
This code is simple selection sort. 
I choose this code for my system programming task4 that optimize code
I modify this code step by step for optimization
If you read this and have questions, you can send to email for me
My email is gn1007@dankook.ac.kr or ip014767@gmail.com 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define SWAP(a, b, temp) {temp=a; a=b; b=temp;}

struct timeval stime, etime, gap;  // timeval 구조체 변수 선언

// 함수 프로토타입
void ver1(int n, int arr[]);

void ver2(int n, int arr[]);

void ver3(int n, int arr[]);

void ver4(int n, int arr[]);

void ver5(int n, int arr[]);

int main() {
    int n = 11;  // 고정된 입력값
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};  // 고정된 용액 배열

    gettimeofday(&stime, NULL);
    shuffle(arr, n);
    ver1(n, arr);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = etime.tv_usec - stime.tv_usec;
    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec = gap.tv_usec + 10000000000;
    }
    printf("ver1: %ldsec :%dusec\n", gap.tv_sec, gap.tv_usec);


    gettimeofday(&stime, NULL);
    shuffle(arr, n);
    ver2(n, arr);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = etime.tv_usec - stime.tv_usec;
    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec = gap.tv_usec + 10000000000;
    }
    printf("ver2: %ldsec :%dusec\n", gap.tv_sec, gap.tv_usec);



    return 0;
}
void shuffle(int *a, int n){ // 배열 랜덤하게 섞어준다
        srand(time(NULL));
        int t, i;
        int rn;

        for(i=0; i<n-1; i++){
                rn = rand()%(n-i)+i;
                SWAP(a[i], a[rn], t);
        }
}

void ver1(int n, int arr[]) {
    for(int i = 0; i<n-1;i++){
        int temp =  i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[temp]){
                temp = j;
            }
        }
        int tempValue = arr[i];
        arr[i] = arr[temp];
        arr[temp] = tempValue;
    }
}


void ver2(int n, int arr[]) {
   
}

