# 💻 Computer Architecture & System Design (CSE 306)

<div align="center">
  <img src="https://img.shields.io/badge/Course-CSE306-blue.svg?style=for-the-badge&logo=electron" alt="Course" />
  <img src="https://img.shields.io/badge/Level-3%20Term--I-success.svg?style=for-the-badge" alt="Level" />
  <img src="https://img.shields.io/badge/Institution-BUET-red.svg?style=for-the-badge&logo=academia" alt="Institution" />
  <img src="https://img.shields.io/badge/Architecture-MIPS%20%7C%20AVR-orange.svg?style=for-the-badge" alt="Architecture" />
</div>

<br/>

Welcome to the **Computer Architecture (CSE 306)** master repository. This project chronicles a complete bottom-up hardware design journey—starting from fundamental bare-metal 7400-series logic gates and culminating in a fully integrated, multi-microcontroller **MIPS Processor Simulation**. 

This portfolio demonstrates expertise in digital logic, hierarchical datapaths, FPU constraints, and complex instruction set simulations, combining low-level hardware circuit design with high-level system integration.

---

## 🛠️ Tech Stack & Tools

*   **Circuit Design & Simulation:** Logisim, Proteus ISIS
*   **Microcontroller & Firmware:** Atmel / Microchip Studio, AVR (C language)
*   **Compiler & Assembler Construction:** Flex (`lexer.lex`), Bison (`parser.y`), C++
*   **Hardware paradigms:** 7400-series TTL ICs, IEEE-754 FPU Arithmetic, MIPS multi-cycle datapaths.

---

## 🚀 Design Milestones

Our system architecture is divided into three major iterative milestones, each contained within its own module:

### 1. 🔬 [4-Bit Arithmetic Logic Unit (7400-Series)](./ALU/)
An implementation of a 4-bit ALU utilizing off-the-shelf 7400-series ICs. It establishes foundational concepts like operation multiplexing, full-adders, and 2's complement subtractions without higher-level abstraction.
*   **Concepts:** TTL Logic, Combinational Circuits, Parallel Addition.
*   **Tools:** Logisim
*   👉 **[Explore ALU Design](./ALU/)**

### 2. 📈 [Floating Point Unit & 32-Bit ALU](./FPA/)
A massive structural step up, moving from 4-bit TTL logic to custom **32-Bit scalable architecture**. This module features a 32-bit ALU built from cascading 1-bit ALU slices and a custom-designed **Floating Point Adder (FPA)** implementing IEEE-754 logic for floating-point arithmetic.
*   **Concepts:** Cascading architectures, Bit-slicing, Floating-Point mantissa/exponent logic, Overflow handling.
*   **Tools:** Logisim
*   👉 **[Explore FPA & 32-Bit ALU](./FPA/)**

### 3. 🧠 [MIPS Processor Simulation (AVR & Proteus)](./MIPS/)
The capstone project: a fully functional multi-controller processor simulation. Individual components of a MIPS datapath (ALU, Control Unit, Registers, RAM, ROM, PC) are programmed onto independent **AVR microcontrollers** in C, which communicate over a shared simulation bus in Proteus. 
*   **Bonus:** Includes a custom Lex/Yacc assembler that compiles MIPS assembly code (`code.asm`) directly into machine code arrays for the simulated instruction memory!
*   **Concepts:** Datapath Control, Memory Mapped I/O, Firmware Integration, Lexical Parsing, Microarchitecture.
*   **Tools:** Proteus, Atmel Studio (C), Lex/Yacc, C++
*   👉 **[Explore MIPS Processor](./MIPS/)**

---

## 🎯 How to Navigate

Feel free to browse through each directory to find specific `.circ` files for Logisim or `.pdsprj` files for Proteus. Each module has its own dedicated `README.md` detailing the operational schematics, integrated hardware images, and execution instructions.

```text
📁 Computer-Architecture
├── 📂 ALU/      # Milestone 1: 4-Bit TTL ALU
├── 📂 FPA/      # Milestone 2: 32-Bit ALU & Floating Point Adder
├── 📂 MIPS/     # Milestone 3: AVR-based MIPS Simulator + Assembler
└── 📄 README.md # You are here
```

<div align="center">
  <i>Designed and developed by Group 4 for a comprehensive understanding of complex hardware architecture.</i>
</div>
