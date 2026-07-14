# bitmanip — 位操作工具库

嵌入式开发中最常用的位操作封装：置位、清位、读取、掩码构造、多 bit 域操作。

## API 概览

| 宏/函数 | 说明 |
|---------|------|
| `SET_BIT(reg, n)` | 将寄存器的第 n 位置 1 |
| `CLR_BIT(reg, n)` | 将寄存器的第 n 位置 0 |
| `GET_BIT(reg, n)` | 读取寄存器的第 n 位 (返回 0 或 1) |
| `BIT_MASK(n)` | 构造只有第 n 位为 1 的掩码 |
| `BIT_RANGE_MASK(h, l)` | 构造第 l 位到第 h 位全为 1 的掩码 |

## 构建

```bash
make
./bitmanip
```
