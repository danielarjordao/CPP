# 42 C++ Modules Projects

This repository contains all 10 C++ modules from the 42 curriculum, designed to progressively develop skills in C++ programming — from basic concepts to advanced techniques and the Standard Template Library (STL).

## Modules Overview

| Module           | Language | Status       | Description                                       |
|------------------|----------|--------------|-------------------------------------------------|
| [Module 00](#module-00) | C++      | Completed    | Basics of C++, classes, constructors, and OOP fundamentals. |
| [Module 01](#module-01) | C++      | Completed    | Memory management, pointers, references, and switch.          |
| [Module 02](#module-02) | C++      | Completed    | Overloading and canonical form (Rule of Three/Five).           |
| [Module 03](#module-03) | C++      | Completed    | Inheritance, access specifiers, and basic polymorphism.        |
| [Module 04](#module-04) | C++      | Completed    | Abstract classes, pure virtual functions, and interfaces.      |
| [Module 05](#module-05) | C++      | In Progress  | Exception handling with try/catch and custom exceptions.       |
| [Module 06](#module-06) | C++      | Not Started  | Casting operators: static, dynamic, const, reinterpret.         |
| [Module 07](#module-07) | C++      | Not Started  | Templates for generic programming.                             |
| [Module 08](#module-08) | C++      | Not Started  | STL containers, iterators, and algorithms.                      |
| [Module 09](#module-09) | C++      | Not Started  | Advanced container use and performance considerations.          |

---

## Module Details

### Module 00  

**Concepts Summary**

This module marks the beginning of the journey in C++ programming and focuses on transitioning from C to Object-Oriented Programming (OOP) using C++. The code must follow the C++98 standard to ensure compatibility and simplicity during the initial steps.

###### 🚀 Fundamentals and Structure

- C++ builds on C and introduces new paradigms such as OOP.
- Programs start with `main`, just like in C, but C++ supports a more robust syntax for working with objects, classes, and methods.

###### 📦 `namespace std`

- Standard library objects and functions (e.g., `cout`, `cin`, `endl`, `string`) are in the `std` namespace.
- Use the `std::` prefix to access them.

###### 💬 Input and Output

- `<iostream>` enables input/output operations:
  ```cpp
  std::cin >> variable;
  std::cout << "Output" << std::endl;
  ```
- `std::endl` is safer than `\n` as it flushes the output buffer.
- `getline(std::cin, stringVar)`: reads a full line including spaces.
- `cin.clear()`: resets the input state after a failed input operation.

###### 📚 `string` Library

- The `string` class simplifies string manipulation compared to C-strings.
  ```cpp
  std::string name = "Daniela";
  ```

###### ⚙️ Compilation

Compile using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

- `-Wall -Wextra -Werror`: enable warnings and treat them as errors.
- `-std=c++98`: enforce the use of the C++98 standard.

###### 🧱 Classes and OOP

- A **class** defines attributes (variables) and behaviors (methods).
- **Objects** are instances of classes.

Access control:
- `private`: members are accessible only within the class.
- `public`: members can be accessed from outside.

Example:

```cpp
class Student {
public:
    Student();
    ~Student();
    void setName(std::string name);
    void printName();
private:
    std::string name;
};
```

###### 🧠 Additional Class Concepts

- **Constructor/Destructor**: Special methods triggered during object creation/destruction.
- **Copy constructor**: Used when an object is copied.
- `this->`: A pointer to the current object, often used to resolve naming conflicts.

###### 🧾 Architecture

- Headers (`.hpp`) contain class definitions.
- Implementation goes into `.cpp` files.
- Use `#ifndef`, `#define`, `#endif` to prevent multiple inclusions.

###### ⚖️ Constants and `const`

- Use `const` to prevent modifications to variables or class methods.
- Const methods ensure the internal state of the object isn't changed.

###### 🧰 Extra Tools and Concepts

- `setw`: From `<iomanip>`, formats output width for aligned printing.
- `exit(statusCode)`: Immediately terminates the program with a status code.

- `_displayTimestamp()`

A utility function to print the current timestamp, useful for logging or debugging. It demonstrates usage of time-related standard library components:

- `time_t`: represents the current calendar time.
- `struct tm`: holds a calendar time broken down into its components.
- `time()`: gets the current time.
- `localtime()`: converts `time_t` to local time.
- `strftime()`: formats time into a human-readable string.

```cpp
void Account::_displayTimestamp() {
    time_t currentTime;
    struct tm *localTime;
    char formattedTime[16];

    time(&currentTime);
    localTime = localtime(&currentTime);
    strftime(formattedTime, sizeof(formattedTime), "%Y%m%d_%H%M%S", localTime);
    std::cout << "[" << formattedTime << "] ";
}
```

### Module 01  
**Memory Management and Pointers**  
Focuses on memory handling and references, including:  
- Use of pointers and references in C++  
- Pointers to class members (methods and attributes)  
- Control flow with the `switch` statement  
- Differences in memory management compared to C  

### Module 02  
**Ad-hoc Polymorphism and Canonical Form**  
Covers ad-hoc polymorphism through:  
- Function and operator overloading for customized behavior  
- Implementation of the canonical form (Rule of Three/Five): copy constructor, copy assignment operator, destructor, move constructor, and move assignment operator  
- Proper resource management to avoid shallow copies and other issues  

### Module 03  
**Inheritance and Basic Polymorphism**  
Explores core inheritance concepts, including:  
- Creation of base and derived classes  
- Access specifiers (`public`, `protected`, `private`) and their effects on inheritance  
- Introductory static and dynamic polymorphism  
- Use of virtual functions  

### Module 04  
**Subtype Polymorphism and Interfaces**  
Deepens the understanding of polymorphism by introducing:  
- Abstract classes and pure virtual functions  
- Interfaces to enforce implementation contracts  
- Flexible and extensible code design using inheritance and dynamic polymorphism  
- Interface-oriented design for decoupling  

