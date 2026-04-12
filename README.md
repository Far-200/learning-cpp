# 🔩 cpp-mastery

A personal C++ learning journal — from Hello World to systems-level programming.  
Structured, session-by-session. No fluff.

---

## 🗺️ Roadmap

| #   | Topic                                                       | Status  |
| --- | ----------------------------------------------------------- | ------- |
| 01  | Foundations — Syntax, Data Types, I/O, Compilation Pipeline | ✅ Done |
| 02  | Memory — Stack vs. Heap, Pointers, References, `const`      | ✅ Done |
| 03  | OOP & RAII — Classes, Constructors, Encapsulation           | 🔜      |
| 04  | The STL — Containers, Iterators, `<algorithm>`              | 🔜      |
| 05  | Templates — Generic Programming                             | 🔜      |
| 06  | Advanced — Move Semantics, Multithreading, Profiling        | 🔜      |

---

## 📁 Structure

```
cpp-mastery/
├── notes.md          ← session notes, patterns, pitfalls
├── README.md         ← this file
└── sessions/
    ├── session_01/
    │   └── main.cpp
    ├── session_02/
    │   └── main.cpp
    └── ...
```

---

## ⚙️ Setup

**Compiler:** g++ with C++20  
**Build command:**

```bash
g++ -std=c++20 -Wall -Wextra -o output main.cpp
./output
```

**.gitignore — never commit these:**

```
*.o
*.exe
build/
a.out
```

---

## 📖 Notes

Notes are maintained per session to keep learning contextual and focused.

Each `notes.md` includes:

- Concepts explained in simple terms
- Code patterns worth reusing
- Mistakes made (and fixed)
- Insights gained during learning

→ Check inside each session folder for details.
