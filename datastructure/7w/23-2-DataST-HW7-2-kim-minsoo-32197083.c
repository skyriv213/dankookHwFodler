#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char element;

typedef struct Node{
    element data;
    struct Node *node;
}Node;

typedef struct {
    Node *head;
}Circle;

Circle* createCircle(){
    Circle *c;
    c = (Circle*)malloc(sizeof(Circle));
    c->head = NULL;
    return c;
}

int getNode(Circle *c, char x){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = c->head;
    do{
        if(x==temp->data){
            return 1;
        }
        temp=temp->node;
    }while(temp->node!=c->head);
    return 0;
}

void printCircle(Circle *h){
    Node *n;
    n = h->head;
    do{
        printf("%c ", n->data);
        n= n->node;
    }
    while(n!=h->head);
    printf("\n");
}

void insert(Circle *c,element x){
    Node *new,*temp;
    new = (Node *)malloc(sizeof(Node));

    new->data = x;
    new->node = NULL;
    if(c->head == NULL){
        c->head = new;
        new->node= new;
    }else{
        temp = c->head;
        while(temp->node != c->head){
            temp= temp->node;
        }
        temp->node= new;
        new->node=c->head;
    }
}


void problem_7_1(){
    /*
    나만의 플레이리스트 만들기
    수 많은 노래 중 선택한 노래만 순서대로 반복해서 듣기
    음악 제목은 A-Z,a-z로 이루어져있음
    첫째 줄 : 음악 목록에 있는 음악의 개수 N, 반복 재생을 할 음악 개수 K
    둘째 줄 : 연속 재생할 음악 제목 K개 주어짐

    입력
    15 4
    H A N B

    출력 첫째 줄에 바복 재생 목록에 있는 노래 제목 출력
    H A N B
    */
    /*
    음악 목록은 언제든지 추가와 삭제가 가능해야함 -> 순차리스트가 아닌 연결리스트 구성
    연속 재생할 음악 K개에 대한 노드 주소 K개를 찾아서 원형 연결 리스트로 구성하면 반복 재생 목록이 된다

    주어진 순서도
    음악 N개에 대한 연결리스트 구성
    playlist에서 주어진 음악 찾기
    첮운 움억울 원형 연결 리스트의 마지막 노드로 삽입
    selectList의 노드갯수가 K개인지 확인
    if true:
        selectlist 출력
    else:
        다시 음악 찾기
    */

    // 음악 리스트 만들기
    int n, k;
    printf("음악 개수 n 과 반복 재생할 음악 k 입력");
    scanf("%d %d", &n, &k);

    printf("\n음악 리스트를 입력하시오 : ");
    char *s = (char *)malloc(k*sizeof(char));
    scanf("%s", s);
 
    char *arr = (char *)malloc(sizeof(char)*n);
    for(int i =0 ;i<n;i++){
        arr[i]= 65+i;
    }

    if(n>26){
        for(int i =26;i<n;i++){
        arr[i] = 71+i;
        }
    }

    Circle *c= createCircle();

    for(int i = 0 ;i<k;i++){
        for(int j = 0;j<sizeof(arr);j++){
            if(arr[j]==s[i]){
                insert(c,arr[j]);
                printf("%c",s[i]);
            }
        }
    }
    printCircle(c);

}

void problem_7_2(){


}

int main(){
    problem_7_1();
    problem_7_2();
    return 0;
}