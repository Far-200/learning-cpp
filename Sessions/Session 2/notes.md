# Session 02 — The Stack vs. The Heap

> **Compiler flags (always):** `g++ -std=c++20 -Wall -Wextra -o output main.cpp`

---

## Concepts

### 🏨 The Hotel Analogy

|            | Stack                           | Heap                                      |
| ---------- | ------------------------------- | ----------------------------------------- |
| Analogy    | Pre-booked hotel rooms          | Infinite parking lot you rent manually    |
| Speed      | ⚡ ~1 ns (just moves a pointer) | 🐢 ~100+ ns (OS system call)              |
| Management | Automatic (scope-based)         | Manual (`new`/`delete`) or Smart Pointers |
| Size limit | ~1–8 MB                         | GBs available                             |
| Lifetime   | Tied to scope                   | You decide                                |
| Use for    | Local variables, function args  | Large/dynamic/long-lived data             |

### 📋 The Stack

- Every function call creates a **stack frame** pushed onto the stack
- Frame holds: local variables, function arguments, return address
- When function returns → frame is **popped and destroyed instantly**
- Managed by the CPU via the **stack pointer** — zero overhead

```
STACK (grows downward ↓)
┌──────────────────────┐
│   add() frame        │  ← pushed when add() is called
│   a      = 10        │
│   result = 30        │
├──────────────────────┤
│   main() frame       │  ← always at the bottom while main() runs
│   x   = 10           │
│   sum = 30           │
└──────────────────────┘
         ↑ add() frame wiped the instant it returns
```

### 🏗️ The Heap

- You request memory from the OS explicitly
- The **pointer variable** lives on the stack
- The **data it points to** lives on the heap

```
STACK                        HEAP
┌────────────────┐           ┌──────────────┐
│ smart_ptr ─────┼──────────►│   [99]       │
└────────────────┘           └──────────────┘
  (small, auto)               (your data, manual/smart)
```

### 🔑 References and `const`

- A reference is a **read-only alias** — no copy is made, no new memory allocated
- Use `const&` when passing large objects into functions

```
// ❌ copies entire string onto the stack
void print(std::string name)

// ✅ zero copy, zero cost
void print(const std::string& name)
```

**Rule of thumb:**

- Small primitives (`int`, `bool`, `double`) → pass **by value**
- Large objects (`std::string`, `std::vector`) → pass **by `const&`**

---

## Code Patterns

### Stack vs. Heap

```cpp
#include <iostream>
#include <memory>

int main() {
    // STACK — automatic, zero cost
    int x = 42;

    // HEAP: OLD WAY (avoid in modern C++)
    int* raw_ptr = new int(42);
    delete raw_ptr;      // YOU must free it — forget = leak 🚰
    raw_ptr = nullptr;   // always null after delete

    // HEAP: MODERN WAY (prefer this always)
    auto smart = std::make_unique<int>(99);
    std::cout << *smart << "\n";  // dereference with *
    // no delete needed — cleans up when scope ends ✅

    return 0;
}
```

---

## Mistakes Made

_(Session 02 exercise pending — will update after submission)_

---

## Insights

- The pointer itself is tiny and lives on the stack. The actual data it points to lives
  on the heap. Two different locations, one logical connection.
- Stack allocation is basically free — the CPU just moves a single register (the stack
  pointer). Heap allocation involves an OS call, which is ~100x slower.
- A dangling pointer (using memory after `delete`) doesn't always crash immediately —
  it's undefined behavior, meaning it might silently corrupt data elsewhere. That's
  worse than a crash.
- Smart pointers don't add runtime overhead. They're a compile-time abstraction —
  the cleanup code gets baked in by the compiler automatically.

### 🗿 War Story — Ariane 5 Rocket (1996)

A 16-bit integer overflow caused the rocket to self-destruct 37 seconds after launch.
Cost: $370 million. Lesson: wrong data type = real consequences. Size matters.
