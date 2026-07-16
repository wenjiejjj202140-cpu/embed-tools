# GitHub 工作流规范

> 创建于 2026/7/16 · 文 的嵌入式学习 GitHub 使用计划

---

## 🎯 目的

1. 建立连贯的学习 commit 历史，面试时可作为工程能力证明
2. 版本控制保护代码安全，防止误删/误改
3. 后期公开后可展示"从零到嵌入式"的完整学习路径

---

## 📅 日常流程

```
每天学习结束前
    ↓
git add <当天练习的代码和笔记>
    ↓
git commit -m "Dn: <当天主题>"
    ↓
git push
```

### commit message 规范

| 类型 | 格式 | 示例 |
|------|------|------|
| 日常打卡 | `Dn: 主题` | `D5+D6: 结构体内存对齐 & 动态内存分配` |
| 补充/修复 | `fix: 说明` | `fix: score_manager free 后未置 NULL` |
| 笔记更新 | `docs: 说明` | `docs: 新增 GITHUB_WORKFLOW.md` |
| 结构调整 | `chore: 说明` | `chore: 统一目录结构` |

### 哪些提交 / 哪些不提交

| 提交 | 不提交 |
|------|--------|
| `W1_c-deep/*.c` — 自己写的代码 | 编译产物 `*.o` / 二进制文件 |
| `.github/` — 工作流配置（后期） | `入学指南.pdf` — 版权资料 |
| `GITHUB_WORKFLOW.md` — 本文件 | `.knowledge/` — 导师知识库 |
| `README.md`（面试前更新） | `notes/` — 个人笔记 |
| `LEARNING_PLAN.md`（⚠️含个人信息，暂不提交） | |

---

## 🗺 阶段目标

| 阶段 | 状态 | 说明 |
|------|------|------|
| **Phase 1: 私有积累** | 🟢 当前 | 私有仓库，每天 commit + push，不苛求完美 |
| **Phase 2: 整理门面** | 🔜 第4~6周 | 写 README、合并零散 commit、加项目描述 |
| **Phase 3: 公开** | 🔜 第8周或面试前 | 仓库切公开，补充 Projects / 标签 |

---

## ⚡ 操作命令备忘

```bash
# 查看当前状态
git status

# 添加当天代码
git add W1_c-deep/xxx.c

# 提交
git commit -m "Dn: 主题"

# 推送到 GitHub
git push

# 查看历史
git log --oneline
```

---

## 📌 注意事项

- **不 push 尚硅谷版权资料**（讲义 PDF、视频笔记截图等）
- **不 push 敏感信息**（如本机 IP、代理配置、WSL 路径等）
- **面试前整理 README**，但现在不需要花时间做这件事
- 坚持 **"每天至少一个 commit"** 原则，哪怕只是几行代码改动
