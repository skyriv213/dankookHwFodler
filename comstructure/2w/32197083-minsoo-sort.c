#include <stdio.h>



int main(){
    int v[]= {6,3,2,4,1,5};
    int n = sizeof(v)/sizeof(v[0]);

    int i,j,temp;

    i=1; // init
    if(i>=n){
        goto outerExit;
    }
    outer:
        //body
        j=i-1; // init
        if(!(j>=0 && v[j]>v[j+1])){
            goto innerExit;
        }
        inner:
            //body
            temp = v[j];
            v[j]=v[j+1];
            v[j+1]=temp;
            //update
            j--;
        if(j>=0 && v[j]>v[j+1]){
            goto inner;
        }
        //update
        i++;
        innerExit:  
            if(i<n){
                goto outer;
            }
    outerExit:
        for(i=0;i<n;i++){
            printf("%d ",v[i]);
        }
        return 0;
}