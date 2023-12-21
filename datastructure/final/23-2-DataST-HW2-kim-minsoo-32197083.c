#include <stdio.h>
#include <string.h>

struct result_type{
    unsigned int student_number;
    char *name;
    int grading[4];
};

struct result_type std_array[4];

void insert_student(struct result_type *std_array, int idx, struct result_type *r1){
    // std_array[idx] = r1[idx];
    std_array[idx].student_number=r1->student_number;
    std_array[idx].name= r1->name;
    memcpy(std_array[idx].grading, r1->grading,sizeof(r1->grading));
}

void print_students(struct result_type *std_array){
    for(int i = 0 ;i<4;i++){
        printf("학번: %d, 이름: %s, 4과목 점수: %d, %d, %d, %d, 합계: %d\n",
        std_array[i].student_number,std_array[i].name,
        std_array[i].grading[0],std_array[i].grading[1],std_array[i].grading[2],std_array[i].grading[3],
        std_array[i].grading[0]+std_array[i].grading[1]+std_array[i].grading[2]+std_array[i].grading[3]
        );
    }
}

int main(){
   struct result_type r1[] = {
        { 1001, "name 1", 99, 88, 77, 66 },
        { 1002, "name 2", 96, 86, 73, 65 },
        { 1002, "name 3", 93, 83, 72, 63 },
        { 1004, "name 4", 94, 84, 74, 64 }
   };

    for(int i =0;i<4;i++){
        struct result_type *ps =&r1[i];
        insert_student(std_array,i, ps);

    }
    // for (int i = 0; i<4;i++){
    //     printf("이름: %s \n",std_array[i].name);
    // }
   print_students(std_array);
   return 0;

};

