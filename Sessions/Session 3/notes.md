# C++ Session 03 — Loops 🔁

> _"A loop is your program's engine. Get it wrong, and you've built a car that drives in circles forever."_

---

## 📋 Table of Contents

1. [The Four Loop Types](#loop-types)
2. [Loop Control: break & continue](#loop-control)
3. [The Infinite Loop](#infinite-loop)
4. [Quick Reference Cheat Sheet](#cheat-sheet)
5. [Key Style Rules](#style-rules)
6. [Session Exercise: FizzBuzz](#fizzbuzz)

---

## 1. Loop Types <a name="loop-types"></a>

### `while` — The Sentinel

Checks condition **before** executing. May never run if condition is false from the start.

```cpp
int fuel = 5;

while (fuel > 0) {
    std::cout << "Flying... fuel remaining: " << fuel << "\n";
    --fuel;
}
```

```
Condition? ──► FALSE ──► Skip body
    │
   TRUE
    │
   Body
    │
    └──► back to Condition
```

**Use when:** Number of iterations is unknown. You're waiting for something to change.

---

### `for` — The Precision Engineer

Init, condition, and increment **in one line**. Best when you know exactly how many times to iterate.

```cpp
for (int i = 5; i > 0; --i) {
    std::cout << i << "...\n";
}
std::cout << "🚀 Liftoff!\n";
```

```
for ( [init] ; [condition] ; [increment] )
       │            │             │
  Runs ONCE    Checked each   Runs after
  at start      iteration     each body
```

> 💡 The loop variable `i` is scoped **inside** the `for`. It dies when the loop ends — preventing accidental reuse.

**Use when:** You know the exact iteration count. You need an index.

---

### `do...while` — Ask Forgiveness, Not Permission

Runs body **first**, checks condition **after**. Guaranteed at least one execution.

```cpp
int attempts = 0;

do {
    ++attempts;
    std::cout << "Attempting connection... (" << attempts << ")\n";
} while (attempts < 3);
```

```
   Body  ◄──────────┐
    │                │
   Condition? ──TRUE─┘
    │
   FALSE ──► Exit
```

> ⚠️ The semicolon after `while(condition);` is **mandatory**.

**Use when:** You must run the body at least once (e.g., show a menu, then ask to continue).

---

### Range-Based `for` ✨ — The Modern C++ Crown Jewel

Introduced in C++11. Iterates over every element in a collection. No index juggling.

```cpp
#include <vector>
#include <string>

std::vector<std::string> crew = {"Shepard", "Garrus", "Liara"};

for (const auto& member : crew) {
    std::cout << "Crew member: " << member << "\n";
}
```

**Breaking down `const auto&`:**

| Keyword | Meaning                                       |
| ------- | --------------------------------------------- |
| `const` | "I promise not to modify this element"        |
| `auto`  | Compiler infers the type for you              |
| `&`     | Reference — borrow the element, don't copy it |

> 💡 `const auto&` is a reflex to build. For large objects, copying each element on every iteration is expensive — like photocopying a 500-page book per loop.

**Use when:** Iterating over any collection (vector, array, string, etc.) without needing an index.

---

## 2. Loop Control <a name="loop-control"></a>

### `break` — Emergency Exit

Immediately terminates the loop.

### `continue` — Skip This Round

Skips the rest of the current iteration, jumps to the next condition check.

```cpp
for (int i = 1; i <= 10; ++i) {
    if (i == 4) continue;  // skip 4
    if (i == 8) break;     // stop at 8
    std::cout << i << " ";
}
// Output: 1 2 3 5 6 7
```

---

## 3. The Infinite Loop <a name="infinite-loop"></a>

Not always a bug — every game engine, OS kernel, and server uses one intentionally.

```cpp
while (true) {
    // accept connection
    // process request
    // if shutdown_signal: break
}
```

`for(;;)` is equivalent and preferred in some embedded/kernel codebases.

---

## 4. Quick Reference Cheat Sheet <a name="cheat-sheet"></a>

| Loop         | When to Use                     | Runs if condition false? |
| ------------ | ------------------------------- | ------------------------ |
| `while`      | Unknown iterations, check first | No                       |
| `for`        | Known count, index needed       | No                       |
| `do...while` | Must run at least once          | **Yes (once)**           |
| range-`for`  | Iterating collections           | No                       |

---

## 5. Key Style Rules <a name="style-rules"></a>

### ✅ Use `"\n"` over `std::endl`

```cpp
// ❌ Avoid — flushes buffer every time (slow in loops)
std::cout << "Hello" << std::endl;

// ✅ Prefer — just a newline, no flush overhead
std::cout << "Hello" << "\n";
```

### ✅ Avoid `using namespace std;`

Always use the `std::` prefix explicitly. Prevents naming collisions in large codebases.

### ✅ Use `const auto&` in range-based `for`

Unless you intentionally need a copy or need to modify the element.

---

## 6. Session Exercise: FizzBuzz ✅ <a name="fizzbuzz"></a>

### Version 1 — Classic `for` loop

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz" << "\n";
        }
        else if (i % 3 == 0) {
            std::cout << "Fizz" << "\n";
        }
        else if (i % 5 == 0) {
            std::cout << "Buzz" << "\n";
        }
        else {
            std::cout << i << "\n";
        }
    }
    return 0;
}
```

### Version 2 — Range-Based `for` with `std::vector<int>`

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30
    };

    for (const auto& i : numbers) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz" << "\n";
        }
        else if (i % 3 == 0) {
            std::cout << "Fizz" << "\n";
        }
        else if (i % 5 == 0) {
            std::cout << "Buzz" << "\n";
        }
        else {
            std::cout << i << "\n";
        }
    }
    return 0;
}
```

> 🔮 **STL Teaser:** In the future, `std::iota` lets you fill a vector in one line:
>
> ```cpp
> #include <numeric>
> std::vector<int> numbers(30);
> std::iota(numbers.begin(), numbers.end(), 1); // fills 1 to 30
> ```

---

> **Key Insight — Why `FizzBuzz` condition comes first:**
> The most-specific case (`% 3 == 0 && % 5 == 0`) must be checked **before** the individual cases.
> If you check `% 3 == 0` first, the number 15 prints "Fizz" and never reaches "FizzBuzz". Always handle the most specific condition first.

---

_Next Session → **Memory & Pointers: The Stack vs. The Heap** 🧠_
