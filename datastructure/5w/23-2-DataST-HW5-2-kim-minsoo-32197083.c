#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct stackNode{
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top; // 스택의 top 노드를 지정하기 위해 포인터 top 선언

// 해당 스택이 비어져있는지 확인
int isStackEmpty(void){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// 해당 스택에 item 삽입
void push(element item){
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

    temp->data=item;
    temp->link=top;
    top = temp;
}


// 최상단 원소 삭제
element pop(void){
    element item;
    stackNode* temp = top;

    if(isStackEmpty()){
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else{
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

// 연산자 구분 및 우선순위 측정
int isOperator(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

void fromInOrderToPostOrder(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (isOperator(ch)) { // 연산자가 맞을 경우
            while (!isStackEmpty() && isOperator(top->data) >= isOperator(ch)) { // 스택이 비어있지않을때까지, 연산자의 우선 순위가 스택 상단(top)에서 가져온게 더 높다면 계속해서 pop으로 연산자 꺼내오기
                printf("%c", pop());
            }
            push(ch); // while로 연산자를 스택에서 다 pop했다면 스택에 해당 연산자 push하기
        } else if (ch == '(') { // 문자열이 ( 라면 스택에 넣기
            push(ch);
        } else if (ch == ')') { // 문자열이 ) 라면 스택이 비어버리기 전, 그리고 top이 ( 가 아닐때까지 연산자 출력하기
            while (!isStackEmpty() && top->data != '(') {
                printf("%c", pop());
            }
            pop(); // 반복문으로 연산자가 다 출력이 되면 pop()으로 ( 빼내기
        }else{
             printf("%c", ch); // 연산자가 아니라면 그대로 출력하기
        }
    }

    while (!isStackEmpty()) {
        printf("%c", pop()); // 스택이 비어버릴때까지 스택에 남아있는 연산자 다 삭제, 출력하기
    }
    printf("\n");
}

int main(void){
   
    int max_length = 50;
    char *s = (char *)malloc(max_length*sizeof(char));
    strcpy(s,"A/(B+C)*D");

    fromInOrderToPostOrder(s);
    free(s);

    return 0;
}