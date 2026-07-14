/**
 * gpio-blink — GPIO 输出控制与 LED 闪烁模拟
 *
 * 模拟 MCU 的 GPIO 寄存器操作：
 *   - 使用 volatile 模拟硬件寄存器
 *   - 通过指针直接操作寄存器地址
 *   - 延时循环模拟定时效果
 *
 * 编译: gcc -Wall -Wextra -o gpio-blink main.c
 * 运行: ./gpio-blink
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/* ================================================================
 * 模拟硬件寄存器定义
 *
 * 实际 STM32 芯片中，GPIO 寄存器通过 AHB/APB 总线映射到固定地址。
 * 这里用变量模拟寄存器的行为。
 * ================================================================ */

/* 模拟 GPIOB 端口的输出数据寄存器 (ODR)
 * 每位对应一个引脚：bit0 = Pin 0, bit5 = Pin 5, 依此类推
 * 写 1 → 引脚输出高电平，写 0 → 引脚输出低电平 */
static volatile uint16_t GPIOB_ODR = 0x0000;

/* 模拟 GPIOB 端口配置寄存器 */
static volatile uint16_t GPIOB_CRL = 0x0000;

/* ================================================================
 * GPIO 操作宏 —— 嵌入式三板斧
 * ================================================================ */

/* 置位：将指定引脚置为高电平 */
#define GPIO_SET_PIN(port, pin)     ((port) |= (1U << (pin)))

/* 清位：将指定引脚置为低电平 */
#define GPIO_CLR_PIN(port, pin)     ((port) &= ~(1U << (pin)))

/* 读取：获取指定引脚当前电平 (1=高, 0=低) */
#define GPIO_GET_PIN(port, pin)     (((port) >> (pin)) & 1U)

/* ================================================================
 * GPIO 驱动函数
 * ================================================================ */

/**
 * 初始化引脚为推挽输出模式
 * 在真实 MCU 中需要配置 GPIOx_CRL/CRH 寄存器
 */
void GPIO_Init(void)
{
    GPIOB_CRL = 0x4444;      /* 模拟配置为推挽输出 */
    printf("[GPIO] 端口初始化完成 (CRL = 0x%04X)\n", GPIOB_CRL);
}

/**
 * 将指定引脚输出高电平
 * @param pin  引脚号 (0-15)
 */
void GPIO_WriteHigh(uint8_t pin)
{
    GPIO_SET_PIN(GPIOB_ODR, pin);
    printf("[GPIO] Pin %d 输出高电平 (GPIOB_ODR = 0x%04X)\n",
           pin, GPIOB_ODR);
}

/**
 * 将指定引脚输出低电平
 * @param pin  引脚号 (0-15)
 */
void GPIO_WriteLow(uint8_t pin)
{
    GPIO_CLR_PIN(GPIOB_ODR, pin);
    printf("[GPIO] Pin %d 输出低电平 (GPIOB_ODR = 0x%04X)\n",
           pin, GPIOB_ODR);
}

/**
 * 切换指定引脚电平
 * @param pin  引脚号 (0-15)
 */
void GPIO_Toggle(uint8_t pin)
{
    if (GPIO_GET_PIN(GPIOB_ODR, pin)) {
        GPIO_WriteLow(pin);
    } else {
        GPIO_WriteHigh(pin);
    }
}

/* ================================================================
 * 主程序：LED 闪烁演示 (1Hz)
 * ================================================================ */

#define LED_PIN     5       /* 使用 Pin 5 控制 LED */
#define BLINK_MS    500000  /* 半秒切换一次 (单位: 微秒) */

int main(void)
{
    int cycle = 0;

    printf("===== GPIO LED 闪烁演示 =====\n");
    printf("LED 控制引脚: PB%d\n", LED_PIN);
    printf("闪烁频率: %d ms\n\n", BLINK_MS / 1000);

    GPIO_Init();

    /* 无限循环：LED 亮 → 等待 → LED 灭 → 等待 */
    while (1) {
        GPIO_WriteHigh(LED_PIN);     /* 点亮 LED */
        usleep(BLINK_MS);

        GPIO_WriteLow(LED_PIN);      /* 熄灭 LED */
        usleep(BLINK_MS);

        cycle++;
        printf("[主循环] 已完成 %d 次闪烁\n\n", cycle);

        /* 闪烁 5 次后退出，防止无限循环 */
        if (cycle >= 5) {
            printf("演示结束。\n");
            break;
        }
    }

    return 0;
}
