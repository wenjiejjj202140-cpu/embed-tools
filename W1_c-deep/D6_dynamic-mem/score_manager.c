#include <stdio.h>
#include <stdlib.h>

// 【D5任务】把这个结构体排列成最省内存的顺序
// 现有字段：c(1B) / int id(4B) / float score(4B) / char passed(1B)
// 目标：sizeof 最小
typedef struct {
    int id;
    float score;
    char passed;
    char grade;
} Record;

int main() {
    int n = 5;
    
    // 【D6任务①】动态分配 n 个 Record
    Record *records = (Record *)malloc(n*sizeof(Record));
    
    // 【D6任务②】检查分配是否成功
    if (records == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    
    // 填充数据（不用改）
    for (int i = 0; i < n; i++) {
        records[i].id = 1001 + i;
        records[i].score = 60.0f + i * 8.0f;
        records[i].grade = (records[i].score >= 90) ? 'A' :
                           (records[i].score >= 80) ? 'B' :
                           (records[i].score >= 70) ? 'C' : 'D';
        records[i].passed = (records[i].score >= 60) ? 1 : 0;
    }
    
    // 打印（不用改）
    printf("%-6s %-6s %-6s %s\n", "学号", "成绩", "等级", "通过");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-6.1f %-6c %s\n",
               records[i].id, records[i].score, records[i].grade,
               records[i].passed ? "✅" : "❌");
    }
    
    // 【D6任务③】释放内存
    free(records);
    
    // 【D6任务④】置 NULL
    records = NULL;//不知道
    
    return 0;
}