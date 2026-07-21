#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct {
    int id;                  // 学号（自动递增）
    char name[50];           // 姓名
    float scores[3];         // 3门课：语文 数学 英语
    float average;           // 平均分（添加/修改时自动计算）
} Student;

typedef struct {
    Student *students;       // 动态数组
    int count;               // 当前人数
    int capacity;            // 容量
    int next_id;             // 下一个学号
} Class;

int main(){
    // ① 添加学生	结构体赋值、malloc/realloc、安全字符串拷贝
    // 输入姓名和三科成绩，自动分配学号+计算平均分
    Class class;
    class.count = 0;
    class.capacity = 10;
    class.next_id = 1;
    class.students = NULL;
    class.students = (Student*)malloc(class.capacity*sizeof(Student));

    int choice = 0;
    while (1){
        printf("\n===============================\n");
        printf("1.添加用户\n");
        printf("2.显示所有学生\n");
        printf("3.按姓名查找\n");
        printf("4.修改成绩\n");
        printf("9.退出\n");
        printf("6.按平均分排序并显示\n");
        scanf("%d",&choice);
        if(choice == 1){
            //添加用户功能
            //扩容检查
            if(class.count >= class.capacity){
                class.capacity = class.capacity*2;
                class.students = (Student*)realloc(class.students,class.capacity*sizeof(Student));  
            }
            //填数据
            class.students[class.count].id = class.next_id;
            printf("请输入姓名\n");
            scanf("%49s",class.students[class.count].name);
            printf("请输入语文成绩：");
            scanf("%f", &class.students[class.count].scores[0]);
            printf("请输入数学成绩：");
            scanf("%f", &class.students[class.count].scores[1]);
            printf("请输入英语成绩：");
            scanf("%f", &class.students[class.count].scores[2]);
            printf("学号：%d\n",class.students[class.count].id);
            float avg = (class.students[class.count].scores[0] + class.students[class.count].scores[1] + class.students[class.count].scores[2]) / 3;
            class.students[class.count].average = avg;
            printf("平均分：%.2f\n", avg);
            class.count++;
            class.next_id++;
        }


        else if (choice == 2){
            //显示所有学生功能实现
            int i = 0;
            printf("学号  | 姓名  | 语文 | 数学 | 英语 | 平均分\n");
            while(i<class.count){
                printf("%d   | %s   | %.1f  | %.1f  | %.1f  | %.2f\n",class.students[i].id,
                    class.students[i].name,
                    class.students[i].scores[0],
                    class.students[i].scores[1],
                    class.students[i].scores[2],
                    class.students[i].average);
                i++;
            }
        }


        else if(choice == 3){
            char search_name[50];
            int found = 0;
            printf("请输入需要查找的姓名：\n");
            scanf("%49s",search_name);
            for (int i = 0; i < class.count; i++){
                if(strcmp(search_name, class.students[i].name) == 0){
                    printf("找到！学号：%d  姓名：%s  平均分：%.2f\n",
                        class.students[i].id,
                        class.students[i].name,
                        class.students[i].average);
                    found = 1;    
                    break;
                    
                }
                
            }
            if(!found){
                printf("未找到姓名为「%s」的学生\n", search_name);
            }
            
        }

        else if(choice == 4){
            int search_id;
            int found = -1;
            printf("请输入要修改的学号：");
            scanf("%d", &search_id);
            
            for(int i = 0; i < class.count; i++){
                if(class.students[i].id == search_id){
                    found = i;
                    break;
                }
            }
            
            if(found == -1){
                printf("未找到学号为 %d 的学生\n", search_id);
            } else {
                printf("当前成绩：语文 %.1f  数学 %.1f  英语 %.1f\n",
                    class.students[found].scores[0],
                    class.students[found].scores[1],
                    class.students[found].scores[2]);
                
                int sub;
                printf("选择要修改的科目（1=语文 2=数学 3=英语）：");
                scanf("%d", &sub);
                
                if(sub < 1 || sub > 3){
                    printf("无效科目编号\n");
                } else {
                    float new_score;
                    printf("请输入新成绩：");
                    scanf("%f", &new_score);
                    
                    class.students[found].scores[sub - 1] = new_score;
                    
                    // 重新计算平均分
                    class.students[found].average = (
                        class.students[found].scores[0] +
                        class.students[found].scores[1] +
                        class.students[found].scores[2]) / 3;
                    
                    printf("修改成功！新平均分：%.2f\n", class.students[found].average);
                }
            }
        }
        
        else if(choice == 5){
            int del_id;
            printf("请输入要删除的学号：");
            scanf("%d", &del_id);
            int found = -1;
            for(int i = 0; i < class.count; i++){
                if(class.students[i].id == del_id){
                    found = i;
                    break;
                }
            }
            
            if(found == -1){
                printf("未找到学号为 %d 的学生\n", del_id);
            } else {
                // 从 found 开始，后面的往前移一位
                for(int i = found; i < class.count - 1; i++){
                    class.students[i] = class.students[i + 1];
                }
                class.count--;
                printf("已删除学号 %d 的学生\n", del_id);
            }
        }
        
                

       
        else if(choice == 6){
            for(int i = 0; i < class.count - 1; i++){
                for(int j = 0; j < class.count - 1 - i; j++){
                    if( class.students[j].average < class.students[j+1].average/* 如果 j 的均分比 j+1 的均分小 */){
                        // 交换 students[j] 和 students[j+1]
                        Student temp = class.students[j];
                        class.students[j] = class.students[j+1];
                        class.students[j+1] = temp;
                    }
                }
                
            }
            printf("排序完成！%d 名学生按平均分降序排列\n", class.count);
            printf("学号  | 姓名  | 语文 | 数学 | 英语 | 平均分\n");
            for(int i = 0; i < class.count; i++){
                printf("%d   | %s   | %.1f  | %.1f  | %.1f  | %.2f\n",
                class.students[i].id,
                class.students[i].name,
                class.students[i].scores[0],
                class.students[i].scores[1],
                class.students[i].scores[2],
                class.students[i].average);
            }
        }
        else if (choice == 9){
            //退出
            free(class.students);
            break;
        }




    }
    return 0;
}