#include <stdio.h>

int add(int num1, int num2){
    return num1 + num2;
}

int sub(int num1, int num2){
    return num1-num2;
}

int mul(int num1, int num2){
    return num1*num2;
}

int div(int num1, int num2){
    return num1/num2;
}


int main(){
    // char exp[100];
    // scanf("%s", exp);
    char op;
    int num1, num2;
    printf("연산을 진행하는 식을 입력해주시오");
    scanf("%d%c%d",&num1,&op,&num2);

    // for(int i = 0 ;i <sizeof(exp);i++){

    // }
    if (op=='+')
    {
        printf("결과는 %d 입니다",add(num1,num2));
    }
    else if (op=='-')
    {
        printf("결과는 %d 입니다",sub(num1,num2));
    }
    else if(op=='*'){
        printf("결과는 %d 입니다",mul(num1,num2));
    }
    else if (op=='/')
    {
        printf("결과는 %d 입니다",div(num1,num2));
    }
    else{
        printf("처음부터 다시 실행해주세요");
    }

}