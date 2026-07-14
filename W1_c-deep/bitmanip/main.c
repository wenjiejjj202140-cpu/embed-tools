/**
 * bitmanip — 位操作功能演示
 *
 * 演示 bit_utils.h 中各种宏的使用方法和预期输出。
 * 覆盖：置位、清位、读取、切换、位段操作。
 *
 * 编译: gcc -Wall -Wextra -o bitmanip main.c bit_utils.c
 * 运行: ./bitmanip
 */

#include <stdio.h>
#include <stdint.h>
#include "bit_utils.h"

/* 辅助函数：以二进制形式打印 8 位数值 */
void print_bin8(const char *label, uint8_t val)
{
    printf("%-30s = 0x%02X  (二进制: ", label, val);
    for (int i = 7; i >= 0; i--) {
        putchar((val >> i) & 1 ? '1' : '0');
    }
    printf(")\n");
}

int main(void)
{
    uint8_t reg = 0x00;

    printf("===== 位操作工具库演示 =====\n\n");

    /* ---- 1. 置位 ---- */
    printf("--- 1. 置位操作 (SET_BIT) ---\n");
    reg = 0x00;
    SET_BIT(reg, 2);        /* 第 2 位置 1 */
    print_bin8("SET_BIT(reg, 2):", reg);

    SET_BIT(reg, 5);        /* 第 5 位置 1 */
    print_bin8("SET_BIT(reg, 5):", reg);

    SET_BIT(reg, 0);        /* 第 0 位置 1 */
    print_bin8("SET_BIT(reg, 0):", reg);
    printf("\n");

    /* ---- 2. 清位 ---- */
    printf("--- 2. 清位操作 (CLR_BIT) ---\n");
    reg = 0xFF;
    print_bin8("初始值:", reg);
    CLR_BIT(reg, 3);        /* 第 3 位清 0 */
    print_bin8("CLR_BIT(reg, 3):", reg);
    CLR_BIT(reg, 7);        /* 第 7 位清 0 */
    print_bin8("CLR_BIT(reg, 7):", reg);
    printf("\n");

    /* ---- 3. 读取位 ---- */
    printf("--- 3. 读取位操作 (GET_BIT) ---\n");
    reg = 0b10101010;
    print_bin8("测试值:", reg);
    for (int i = 7; i >= 0; i--) {
        printf("  GET_BIT(reg, %d) = %d\n", i, GET_BIT(reg, i));
    }
    printf("\n");

    /* ---- 4. 位掩码 ---- */
    printf("--- 4. 掩码构造 (BIT_MASK) ---\n");
    for (int i = 0; i < 8; i++) {
        printf("  BIT_MASK(%d) = 0x%02X\n", i, BIT_MASK(i));
    }
    printf("\n");

    /* ---- 5. 位段操作 ---- */
    printf("--- 5. 位段掩码 (BIT_RANGE_MASK) ---\n");
    printf("  BIT_RANGE_MASK(5, 2) = 0x%02X\n", BIT_RANGE_MASK(5, 2));
    printf("  BIT_RANGE_MASK(7, 4) = 0x%02X\n", BIT_RANGE_MASK(7, 4));
    printf("\n");

    /* ---- 6. 综合应用：寄存器配置演示 ---- */
    printf("--- 6. 综合: GPIO 寄存器配置模拟 ---\n");
    uint16_t gpio_config = 0x0000;

    /* 假设寄存器第 0-1 位 = 引脚模式 (00:输入, 01:输出10MHz, 10:输出2MHz) */
    /* 第 2-3 位 = 输出类型 */
    WRITE_BITS(gpio_config, 1, 0, 0x01);   /* 模式 = 输出 10MHz */
    WRITE_BITS(gpio_config, 3, 2, 0x02);   /* 类型 = 推挽输出 */

    printf("  GPIO 配置寄存器 = 0x%04X\n", gpio_config);
    printf("  模式 (bit1-0)   = %d (01=输出10MHz)\n", (gpio_config >> 0) & 0x03);
    printf("  类型 (bit3-2)   = %d (10=推挽输出)\n", (gpio_config >> 2) & 0x03);

    printf("\n===== 演示结束 =====\n");
    return 0;
}
