# Memory Pool Allocator

🔥 A lightweight, fast, and straightforward memory pool allocator written in pure C 🔥

**Born from the great battle for Memory Mastery.**

---

## 📜 Description

This project is a handcrafted implementation of an efficient memory pool allocator:

- Fixed-size memory block allocation.
- Instant allocation and deallocation without search overhead.
- Free list management inside raw memory.

✅ Simple logic.  
✅ Direct raw memory manipulation.  
✅ Ideal for embedded systems, game engines, and low-level programming training.

---

## 📚 Project Structure

| File | Description |
|:-----|:------------|
| `memory_pool.h` | Memory pool interface and data structure |
| `memory_pool.c` | Implementation of memory pool creation, allocation, and deallocation |
| `main.c` | Example usage |

---

## ⚡ How to Build

```bash
gcc src/memory_pool.c src/main.c -o memory_pool
./memory_pool