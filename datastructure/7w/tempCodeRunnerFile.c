#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct CL{
    char data;
    struct CL *node;
    
}cl;

typedef struct{
    cl* head;
}cl_h;

cl_h* createCL_h(void){
    cl_h* CL;
    CL=(cl_h*)malloc(sizeof(cl_h));
    CL->head=NULL;
    return CL;
}

void printList(cl_h* CL){
    cl* p;
    printf(" CL =( ");
    p=CL->head;
    if(p==NULL){
        printf(" )\n ");
    }
    do{
        printf("%c ", p->data);
        p=p->node;
        if(p!=CL->head){
            printf(" ");
        }
    }while(p!=CL->head);
    printf(") \n");
}


void insertFirstNode(cl_h *CL, char x){
    cl* new, *temp;
    new =(cl*)malloc(sizeof(cl));
    new->data=x;
    if(CL->head==NULL){
        CL->head = new;
        new-> node= new;
    }else{
        temp = CL->head;
        while(temp->node !=CL->head){
            temp= temp->node;
        }
        new->node= temp->node;
        temp->node= new;
    }
}

void insertMiddleNode(cl_h *CL, cl *pre, char x){
    cl* new;
    new = (cl*)malloc(sizeof(cl));
    CL->head = new;
    if(CL-> head == NULL){
        CL->head = new;
        new->node= new;
    }else{
        new->node= pre->node;
        pre-> node= new;
    }
}

void deleteNode(cl_h *CL, cl *old){
    cl *pre;
    if(CL->head==NULL){
        return;
    }
    if(CL->head->node== CL->head){
        free(CL->head);
        CL->head=NULL;
        return;
    }
    else if(old == NULL){
        return;
    }
    else{
        pre = CL->head;
        while (pre->node!=old){
            pre=pre->node;
        }
        pre ->node=old->node;
        if(old==CL->head){
            CL->head= old->node;
        }
        free(old);
    }
}
cl* searchNode(cl_h *CL, char x){
    cl *temp;
    temp = CL->head;
    if(temp==NULL){
        return NULL;
    }
    do{
        if(strcmp(temp->data,x)==0)return temp;
        else temp = temp->node;
    }while (temp!= CL->head);
   return NULL;
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
   cl_h *first;
   cl *p;
   first=createCL_h();

   int i;
   for(i = 0; i<26;i++){
    insertFirstNode(&first,i+65);
    }
   for(i=26 ; i<52;i++){
    insertFirstNode(&first,i+71);
    }
   printList(&first);
}

void problem_7_2(){


}

int main(){

    problem_7_1();
    problem_7_2();

    return 0;
}