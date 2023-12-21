#include <stdio.h>

struct * namestruct
{
    /* data */
};


int main(){
    char* arr [2];
    char** arrarr= arr;
    int i;

    arr[0]="first";
    arr[1]="second";
    int ar1 = strlen(arr[0]);
    int ar2 = strlen(arr[1]);


    printf("%u", &arr[1]);
    printf("%u", arr[1]);

    printf("%c", *arr[1]);
    printf("%s", *(arr+1)+5);
  
    };
    
// 2000
// 13
// second string
// --
// typedef
// struct test
// char *
// struct namestruct *
// namestruct_tyoe
// --
//namestruct * char [] 
//--


