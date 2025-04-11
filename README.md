
# 📝 Text Editor with Undo/Redo using Stack (C Project)

This project implements a basic **text editing system** in C that simulates **Undo** and **Redo** functionality using **Stacks**, mimicking how modern text editors manage editing history.

---

## 📌 Features
- Read and modify lines from a text file
- Perform undo and redo operations using a stack
- Dynamic input from user for runtime text editing
- Tracks total undo and redo operations performed
- Efficient LIFO-based stack management using linked lists

---

## 🧠 Concept

Stacks are used to simulate the editing process:
- **Undo**: Pops the last character and stores it on a stack.
- **Redo**: Pops from the undo stack and pushes it back to the string.

This behavior closely models the Last-In-First-Out (LIFO) nature of real-world undo/redo features.

---

## 📂 File Structure
| File | Description |
|------|-------------|
| `Application.c` | Main program file handling user interaction and action file |
| `stackFunctions.h` | Header file declaring stack functions and global variables |
| `stackOperations.c` | Implementation of stack operations for undo/redo |
| `project2_data.txt` | Contains lines of text to be edited |
| `project2_dataaction.txt` | Sequence of actions (`Type`, `Undo`, `Redo`) to apply to text |
| `Project2_report.pdf` | Full project report including background, design, and implementation |

---

## 🛠️ How It Works
1. **Initial Actions**: The system reads lines and performs `Type`, `Undo`, `Redo` based on `project2_dataaction.txt`.
2. **Dynamic Mode**: After file-based actions, the user can manually perform typing, undo, and redo from the console.
3. **Stack Operations**:
   - `undo_push(char line[])`: Removes the last character and stores it in stack.
   - `redo_pop(char line[])`: Re-adds the last removed character from the stack.
   - `user_undo(char sentence[])`: Runtime undo by the user.
   - `user_redo(char sentence[])`: Runtime redo by the user.

---

## 🚀 How to Run
```bash
gcc Application.c stackOperations.c -o editor
./editor
```

> Make sure the files `project2_data.txt` and `project2_dataaction.txt` are in the same directory.

---

## 📈 Example

**Given Actions File:**
```
Type
Undo
Redo
```

**Console Output:**
```
Type
Describe various fundamental and advanced data...
Undo
Describe various fundamental and advanced data..
Redo
Describe various fundamental and advanced data...
```

---

