&lt;div align="center"&gt;

&lt;!-- BANNER --&gt;
&lt;img width="100%" src="https://capsule-render.vercel.app/api?type=venom&color=0:0D0221,50:0A0A2E,100:000000&height=180&section=header&text=OOPS%20IN%20C%2B%2B&fontSize=70&fontColor=00FFD1&fontAlignY=55&desc=Object-Oriented%20Programming%20%7C%20UET%20Mardan&descSize=14&descAlignY=80&descColor=FF2D78&stroke=00FFD1&strokeWidth=2&animation=twinkling"/&gt;

&lt;/div&gt;

&lt;div align="center"&gt;

[![Typing SVG](https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=700&size=18&duration=2500&pause=600&color=00FFD1&center=true&vCenter=true&width=700&lines=Encapsulation+%C2%B7+Inheritance+%C2%B7+Polymorphism;Operator+Overloading+%C2%B7+Templates+%C2%B7+File+Handling;Built+from+scratch+in+C%2B%2B)](https://git.io/typing-svg)

&lt;/div&gt;

&lt;br&gt;

&lt;!-- DIVIDER --&gt;
&lt;img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"&gt;

&lt;br&gt;

## `cat repo.txt`

A structured collection of **Object-Oriented Programming concepts** implemented in **C++**, built during my 2nd semester at **UET Mardan**. This isn't copy-pasted code from tutorials — every folder contains programs I wrote, debugged, and refactored to actually understand how OOP works under the hood.

&gt; **Note:** The repo name says "OPPS" because I was in a hurry when I created it. We're keeping it — mistakes that ship are features.

---

## 📁 Repository Structure

| Folder | Concept Covered | What's Inside |
|--------|---------------|---------------|
| [`Abstraction`](./Abstraction) | Data hiding & abstract classes | Interfaces, pure virtual functions, implementation hiding |
| [`Error Handling`](./Error Handling) | Exceptions & robustness | `try-catch`, `throw`, custom exception classes |
| [`File Handling`](./File Handling) | Persistence & streams | `fstream`, binary/text I/O, serialization patterns |
| [`Inheritance`](./Inheritance) | IS-A relationships | Single, multilevel, multiple, hierarchical, hybrid |
| [`Lab Code`](./Lab Code) | Weekly lab submissions | UET coursework — constructors, destructors, basic classes |
| [`Math in cpp`](./Math%20in%20cpp) | Numerical computing | Operator overloading for complex numbers, matrix ops |
| [`Mingled`](./Mingled) | Mixed concepts | Programs combining multiple OOP pillars in one |
| [`OOP Assignments of my University`](./OOP%20Assignments%20of%20my%20University) | Semester deliverables | Complete assignment solutions with documentation |
| [`Operator Overloading`](./Operator%20Overloading) | Custom operators | `+`, `-`, `&lt;&lt;`, `&gt;&gt;`, `[]`, `()` overloading for user-defined types |
| [`PRACTICE`](./PRACTICE) | Muscle memory | Repeated drills — the boring stuff that makes you fast |
| [`Polymorphism`](./Polymorphism) | Runtime & compile-time | Function overloading, virtual functions, vtables, RTTI |
| [`Streams`](./Streams) | I/O architecture | `iostream` internals, stream manipulators, buffer handling |
| [`Templates`](./Templates) | Generic programming | Function templates, class templates, STL-style containers |
| [`headerfiles`](./headerfiles) | Modular design | `.h` / `.hpp` separation, include guards, forward declarations |

---

## 🛠️ Build & Run

Most programs are single-file or small multi-file projects. Compile with **g++**:

```bash
# Single file
g++ -std=c++17 -o output filename.cpp
./output

# Multi-file (with headers)
g++ -std=c++17 main.cpp class.cpp -o output
./output
