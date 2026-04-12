# Session 01 — Foundations

> **Compiler flags (always):** `g++ -std=c++20 -Wall -Wextra -o output main.cpp`

---

## Concepts

### 🔧 The Compilation Pipeline

```
main.cpp → [Preprocessor] → [Compiler] → .o file → [Linker] → executable
```

| Stage        | What it does                                               |
| ------------ | ---------------------------------------------------------- |
| Preprocessor | Copy-pastes `#include` headers, resolves `#define` macros  |
| Compiler     | Translates C++ logic → Assembly → Machine code (`.o` file) |
| Linker       | Stitches all `.o` files together into the final binary     |

### 📦 Data Types

| Type           | Size    | Use for                                  |
| -------------- | ------- | ---------------------------------------- |
| `int`          | 4 bytes | General integers                         |
| `int64_t`      | 8 bytes | Large integers (include `<cstdint>`)     |
| `unsigned int` | 4 bytes | Non-negative integers only               |
| `double`       | 8 bytes | Floating point (prefer over `float`)     |
| `float`        | 4 bytes | Less precise, use only when size matters |
| `bool`         | 1 byte  | `true` / `false`                         |
| `char`         | 1 byte  | Single character                         |
| `std::string`  | varies  | Text (include `<string>`)                |

### ✅ Modern C++ Rules

- ❌ Never `using namespace std;` — pollutes global scope with 1000+ names
- ✅ Use `std::` explicitly, or import selectively: `using std::cout;`
- ✅ Use `auto` to let the compiler deduce types
- ✅ Use `std::string` — never `char*` for text
- ✅ Use `"\n"` over `std::endl` — `endl` flushes the buffer, slower

---

## Code Pattern — Variables & I/O

```cpp
#include <iostream>
#include <string>

int main() {
    std::string player_name = "Farhaan";
    auto player_level       = 21;       // compiler deduces int
    double health           = 85.5;
    bool in_combat          = false;

    std::cout << "Name:   " << player_name  << "\n";
    std::cout << "Level:  " << player_level << "\n";
    std::cout << "Health: " << health       << "%\n";
    std::cout << std::boolalpha             // prints true/false, not 1/0
              << "Combat: " << in_combat    << "\n";

    return 0;
}
```

---

## Mistakes Made

### ❌ Mistake 1 — `boolalpha` on `cin` instead of `cout`

```cpp
// What I wrote
cin >> boolalpha;   // wrong

// What it should be
std::cout << std::boolalpha << in_combat << "\n";  // correct
```

I thought `boolalpha` was something the _user_ would type in — like declaring the format
for input. So I put it on `cin`. But `boolalpha` is an output formatting flag — it only
affects how `cout` _displays_ a bool. `cin` and `cout` are completely separate pipes.
Input formatting ≠ output formatting.

### ❌ Mistake 2 — `using namespace std;`

```cpp
// What I wrote
using namespace std;   // wrong in anything beyond throwaway code
```

I'd seen this everywhere — lab programs, tutorials, small projects — so it felt normal.
It's not wrong in tiny isolated programs, but it's a bad habit to carry forward.
In real codebases it dumps 1000+ names into global scope and causes silent collisions.
The fix costs 5 characters: just write `std::`.

---

## Insights

- `cin` and `cout` are separate streams. Formatting flags on one don't affect the other.
- `using namespace std` is common in learning material because it reduces typing noise —
  but that's a teaching convenience, not a professional standard.
- `auto` doesn't mean "no type" — it means "compiler, you figure it out." The type is
  still fixed at compile time. It's not like Python's dynamic typing.
- Warnings (`-Wall -Wextra`) are basically free bug reports. Never ignore them.
