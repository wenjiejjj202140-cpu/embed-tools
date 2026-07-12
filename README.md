# embed-tools

嵌入式底层工具合集。包含 GPIO 控制、位操作等嵌入式开发中常用的基础模块。

## 目录

| 模块 | 说明 |
|------|------|
| `gpio-blink/` | GPIO 输出控制与 LED 闪烁模拟 |
| `bitmanip/` | 位操作工具库：置位、清位、读取、掩码构造 |

## 环境

- 编译器: gcc (支持 C99/C11)
- 平台: Linux / WSL
- 构建: 每个模块独立 Makefile，`make` 即可编译
