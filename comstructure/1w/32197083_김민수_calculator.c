#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

typedef struct
{
    /* data */
    int mag[MAX_SIZE] ;
    int length;
}BigInt;


void init(BigInt *num){
    for(int i =0; i<MAX_SIZE;i++){
        num->mag[i]=0;
    }
    num->length=0;
}

void inputValue(char *str, BigInt *num){
    init(num);
    int len = strlen(str);
    for (int i = 0; i<len;i++){
        num->mag[i]=str[len-i-1]-'0';
    }
    num->length=len;
}

void printBI(BigInt *num){
     for (int i = num->length - 1; i >= 0; i--){
        printf("%d", num->mag[i]);
        }
    printf("\n");
}

void add(BigInt *num1, BigInt *num2,BigInt *res){
    int carry = 0;
    int len = (num1->length > num2->length ? num1->length: num2->length);
    
    for(int i = 0; i<len;i++){
        // printf("%d\t%d\t%d\n",num1->mag[i],num2->mag[i],carry);
        int tmp = num1->mag[i]+num2->mag[i] +carry;
        carry = tmp/10;
        tmp= tmp%10;
        res->mag[i] = tmp;
    }
    if (carry>0){
        res->mag[len]=carry;
        res->length+=1;
    }
    else{
        res->length=len;
    }
    printBI(res);
}

void sub(BigInt *num1, BigInt *num2,BigInt *res){
    int len = (num1->length >num2->length?num1->length:num2->length);
    for(int i = 0; i<len;i++){
        if(num1->mag[i]>num2->mag[i]){
            res->mag[i]= num1->mag[i]-num2->mag[i];
        }
        else if (num1->mag[i]==num2->mag[i])
        {
             res->mag[i]=0;
        }
        else{
            num1->mag[i+1]-=1;
            res->mag[i]= num1->mag[i]-num2->mag[i]+10;
        }
    }
    int cnt = 0;
    for(int i = len-1; i>=0;i--){
        if(res->mag[i]==0){
            cnt+=1;
        }else{
            break;
        }
    }
    res->length=len-cnt;
    printBI(res);
}


void mul(BigInt *num1, BigInt *num2,BigInt *res){
    int len = num1->length + num2 ->length+1;
    init(res);
    int carry = 0;
    res->length=len;
    for(int i = 0;i<num2->length;i++){
        for(int j = 0; j<num1->length;j++){
            res->mag[i+j]+=num1->mag[j]*num2->mag[i];
        }
    }

    for(int i = 0;i<len;i++){
        if(res->mag[i]>10){
            res->mag[i+1]+=(res->mag[i]/10);
            res->mag[i]%=10;
        }
    }
    int cnt = 0;
    for(int i = len-1; i>=0;i--){
        if(res->mag[i]==0){
            cnt+=1;
        }else{
            break;
        }
    }
    res->length=len-cnt;
    printBI(res);

}

void div(){
    unsigned long long num1,num2;

    printf("첫번째 숫자를 다시 입력해주세요: ");
    scanf("%llu", &num1);
    printf("두번째 숫자를 다시 입력해주세요: ");
    scanf("%llu", &num2);

    printf("%llu", num1/num2);

}

int main(){
    char num1[MAX_SIZE];
    char num2[MAX_SIZE];
    char op;
    printf("계산 가능한 자릿수는 20자리까지 가능합니다.");
    printf("첫번째 숫자를 입력해주세요: ");
    scanf("%s", num1);
    printf("두번째 숫자를 입력해주세요: ");
    scanf("%s", num2);
    
    printf("구하고자하는 연산의 연산자를 입력해주세요 (+, -, *, /): ");
    scanf(" %c", &op);

    BigInt bigint1, bigint2, result;
    inputValue(num1, &bigint1);
    inputValue(num2, &bigint2);

    if (op == '+') {
        printf("결과는: ");
        add(&bigint1, &bigint2, &result);
    } else if (op == '-') {
        printf("결과는: ");
        sub(&bigint1, &bigint2, &result);
    } else if (op == '*') {
        printf("결과는: ");
        mul(&bigint1, &bigint2, &result);
    } else if (op == '/') {
        div();
    } else {
        printf("올바른 연산자를 입력하세요.");
    }



}