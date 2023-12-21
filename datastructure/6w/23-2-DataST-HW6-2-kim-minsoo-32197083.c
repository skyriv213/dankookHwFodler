#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

typedef struct{
    Node *front, *rear;
}Queue;

void init(Queue *q){
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q){
    return (q->front==NULL);
}

void enqueue(Queue *q, int data){
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data= data;
    temp->link= NULL;
    if(isEmpty(q)){ // Queue가 비어져있으면 front, rear 모두 새로운 노드 가리키기
        q->front= temp;
        q->rear = temp;
    }
    else{
        q->rear->link= temp;
        q->rear=temp;
    }
}

int dequeue(Queue *q){
    Node *temp;
    int data;
    if(isEmpty(q)){
        printf("error");
    }
    else{
        temp= q->front;
        data= temp->data;
        q->front = temp->link;
        if(q->front==NULL){
            q->rear=NULL;
        }
        free(temp);
    }
    return data;
}

int peek(Queue *q){
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1; // 예외 상황을 나타내는 값 반환
    }
    return q->front->data;
}

typedef struct{
    Node *top;
}Stack;

void init_s(Stack *s){
    s->top =NULL;
}

int isEmpty_s(Stack *s){
    return (s->top ==NULL);
}

void push(Stack *s, int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = s->top;
    s->top=temp;
}

int pop(Stack *s){
    int num;
    if(isEmpty_s(s)){
       printf(
        "error\n"
       );
    }else{
        Node *temp=s->top;
        num= temp->data;
        s->top=s->top->link;
        free(temp);
    }
    return num;
}
int peek_s(Stack *s){
    if (isEmpty_s(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}


void problem_6_1(){
    // 변수 입력
    int n,k;
    printf("n과 k를 입력하시오");
    scanf("%d %d",&n,&k);
    
    //선언 및 초기화
    Queue q;
    init(&q);
    for(int i =1;i<=n;i++){
        enqueue(&q,i);
    }
   
    int cnt = 1;
    while (!isEmpty(&q)) {
        int num = dequeue(&q);
        if (cnt == k) {
            printf("%d ", num);
            cnt =1;
        } else {
            enqueue(&q, num);
            cnt+=1;
        }
        // cnt = (cnt == k) ? 1 : cnt + 1;
    }
}

void problem_6_2(){
    
    // 동적할당
    int n;
    printf("숫자 n을 입력하시오: ");
    scanf("%d",&n);
    // 작성
    Queue rq,lq;
    Stack ms;
    init(&rq);
    init(&lq);
    init_s(&ms);
    for(int i =1;i<=n;i++){
        enqueue(&rq,i);
    }
   
    int *num= (int *)malloc(sizeof(int)*n);

    printf("테스트할 수열을 입력하시오");
    for (int i =0; i<n;i++){
        scanf("%d", &num[i]);
    }
    int i = 0;
    while(1){
        //rq에서 맨 앞 숫자 확인
        int num1 =  peek(&rq);
        //확인 후 현재 주어진 num 배열과 비교
        if(num1==num[i]){
            //만약 rq와 num[i]의 수가 같다면
            //rq에서 dequeue,가져온 수를 lq에 입력 후 i++ 
            enqueue(&lq,dequeue(&rq));
            i+=1;
        }
        else{
            //아닌 경우
            //rq의 front 숫자를 비교했을때 num[i]보다 큰 경우
            if(num1>num[i]){
                //스택에서 top에 위치하는 숫자가 num[i]와 같은가
                int num2 = peek_s(&ms);
                if(num2==num[i]){
                    // 스택에서 지우고 lq에 입력 후 i++ 다음인덱스로 진행
                    enqueue(&lq, pop(&ms));
                    i+=1;
                }else{
                    // 아닌경우
                    // impossible 출력
                    printf("IMPOSSIBLE");
                    free(num);
                    return;
                }
            }else{
                // 아닌경우
                // rq에서 숫자 삭제 후 스택에 입력
                push(&ms,dequeue(&rq));
            }
        }
        if(i==n){
            break;
        }
    }

    // 스택이 공백인가
        //possible
    // impossible
    free(num);
    if(isEmpty_s(&ms)){
        printf("POSSIBLE");
    }else{
        printf("IMPOSSIBLE");
    }
}
int main(){
    problem_6_1();
    printf("\n");
    problem_6_2();
    return 0;
}