#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
    float score;
} Student;

// 打印单个学生
void print_student(Student s) {
    printf("%s  %d岁  %.1f分\n", s.name, s.age, s.score);
}

// 打印所有学生
void print_all(Student class[], int count) {
    // 任务 1：循环调用 print_student 打印每个学生
    // 使用 for 循环遍历数组，从 0 到 count-1
    for (int i = 0; i < count; i++) {
        print_student(class[i]); // 将当前学生传给打印函数
    }
}

// 修改分数
void update_score(Student class[], int index, float new_score) {
    // 任务 2：把 class[index] 的分数改成 new_score
    // 通过下标访问结构体成员，使用点运算符 (.) 赋值
    class[index].score = new_score; 
}

int main() {
    // 创建（Create）
    Student class[3] = {
        {"文",   20, 85.5},
        {"小杰", 22, 92.0},
        {"小明", 21, 78.0}
    };
    int count = 3;

    printf("=== 全部学生 ===\n");
    print_all(class, count);

    printf("\n=== 修改小杰的分数为 95.0 ===\n");
    update_score(class, 1, 95.0);
    print_all(class, count);

    printf("\n=== 删除小明（分数置0） ===\n");
    // 任务 3：直接把 score 置 0
    // 小明在数组中的下标是 2，直接通过点运算符修改
    class[2].score = 0.0f; 
    print_all(class, count);

    return 0;
}