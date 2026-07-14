# gpio-blink — GPIO 输出控制与 LED 闪烁模拟

模拟 MCU GPIO 输出行为，演示寄存器地址映射、引脚电平控制、延时循环等嵌入式基础操作。

## 功能

- 模拟 GPIO 端口寄存器读写
- 单引脚高低电平控制
- 周期性 LED 闪烁（1Hz）
- 可配置引脚号和闪烁频率

## 构建

```bash
make
./gpio-blink
```

## 输出示例

```
[GPIO] Pin 5 输出高电平 (GPIOB_ODR = 0x0020)
[GPIO] Pin 5 输出低电平 (GPIOB_ODR = 0x0000)
```
