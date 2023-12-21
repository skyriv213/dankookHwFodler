#include<stdio.h>

int main(){
    long arr [] ={1,3,4,2,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i,j,temp;
    i = 0; // t3
    outer:
        if(i >= n-1) goto outerExit; // bge j, n-1, outerExit

        j = 0; //t4
        inner:
            if(j >= n-1-i) goto innerExit; // bge j, n-1-i, innerExit

            if(arr[j] > arr[j+1]){ //slli 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            j++;
            goto inner;

        innerExit:
        i++;
    goto outer;

    outerExit:;
    

    for (int i=0; i < n; i++)
       printf("%ld ", arr[i]);
   printf("\n");
}