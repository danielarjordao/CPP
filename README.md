# 42 C++ Modules Projects

This repository contains all 10 C++ modules from the 42 curriculum, designed to progressively develop skills in C++ programming — from basic concepts to advanced techniques and the Standard Template Library (STL).

## Modules Overview

| Module           | Language | Status       | Description                                       |
|------------------|----------|--------------|-------------------------------------------------|
| [Module 00](https://github.com/danielarjordao/CPP/tree/d296601ee282196436ae88be01159e29146afcf6/CPP%20Module%2000) | C++      | Completed    | Basics of C++, classes, constructors, and OOP fundamentals. |
| [Module 01](https://github.com/danielarjordao/CPP/tree/d296601ee282196436ae88be01159e29146afcf6/CPP%20Module%2001) | C++      | Completed    | Memory management, pointers, references, and switch.          |
| [Module 02](https://github.com/danielarjordao/CPP/tree/d296601ee282196436ae88be01159e29146afcf6/CPP%20Module%2002) | C++      | Completed    | Overloading and canonical form (Rule of Three/Five).           |
| [Module 03](https://github.com/danielarjordao/CPP/tree/d296601ee282196436ae88be01159e29146afcf6/CPP%20Module%2003) | C++      | Completed    | Inheritance, access specifiers, and basic polymorphism.        |
| [Module 04](https://github.com/danielarjordao/CPP/tree/d296601ee282196436ae88be01159e29146afcf6/CPP%20Module%2004) | C++      | Completed    | Abstract classes, pure virtual functions, and interfaces.      |
| Module 05 | C++      | In Progress  | Exception handling with try/catch and custom exceptions.       |
| Module 06 | C++      | Not Started  | Casting operators: static, dynamic, const, reinterpret.         |
| Module 07 | C++      | Not Started  | Templates for generic programming.                             |
| Module 08 | C++      | Not Started  | STL containers, iterators, and algorithms.                      |
| Module 09 | C++      | Not Started  | Advanced container use and performance considerations.          |

---

## C++ Basic Concepts and Classes

### 📚 Index

- [Compilation Process](#-compilation-process)
- [Basics](#Basics)
  - [Input/Output](#inputoutput)
  - [Strings](#strings)
  - [`const`](#const)
  - [`static`](#static)
  - [Scope](#scope)
  - [Arrays](#arrays)
  - [For Loop](#for-loop)
  - [Do-While Loop](#do-while-loop)
  - [`continue` and `break`](#continue-and-break)
  - [Recursion](#recursion)
  - [Functions](#functions)
  - [Passing Variables](#passing-variables)
  - [Pointers](#pointers)
  - [Dynamic Memory](#dynamic-memory)
  - [Null Pointer](#null-pointer)
  - [Function Pointers](#function-pointers)
  - [Lvalue vs. Rvalue](#lvalue-vs-rvalue)
  - [Variable Sizes](#variable-sizes)
- [Interface vs Implementation](#-interface-vs-implementation)
- [Structs and Classes](#-structs-and-classes)
  - [Struct](#struct)
  - [Class](#class)
  - [Access Specifiers](#access-specifiers)
  - [Constructor / Destructor](#constructor--destructor)
  - [Copy Constructor](#copy-constructor)
  - [Rule of Three](#-rule-of-three)
  - [`this` Pointer](#this-pointer)
  - [Object](#object)
- [Classes Advanced Concepts](#classes-advanced-concepts)
  - [RAII](#raii-resource-acquisition-is-initialization)
  - [Copy Constructor and Assignment](#copy-constructor-and-copy-assignment-operator)
  - [Operator Overloading](#operator-overloading-example-vector3f-class)
  - [Inheritance and Access Specifiers](#inheritance-and-access-specifiers)
  - [Polymorphism and Virtual Functions](#polymorphism-and-virtual-functions)
  - [Virtual Tables (Vtables)](#virtual-tables-vtables-explained)
  - [Abstract Classes](#abstract-classes)
  - [Multiple Inheritance and Diamond Problem](#multiple-inheritance-and-the-diamond-problem)

### Compilation Process

#### Compilation Stages

C++ compilation involves multiple stages:

1. **Preprocessing** (`.cpp` → `.i`)
   - Handles `#include`, `#define`, and other directives.
   - Removes comments and expands macros.

2. **Compilation** (`.i` → `.s`)
   - Translates preprocessed code into assembly code.
   - Performs syntax analysis and optimizations.

3. **Assembly** (`.s` → `.o`)
   - Converts assembly to machine code (object file).
   - Code is not yet executable—no linking done.

4. **Linking** (`.o` + libs → executable)
   - Combines object files and libraries.
   - Resolves symbol references (functions, variables).

#### Example with `c++`:

```bash
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o main
```

### Basics

#### Input/Output

* `iostream` is a standard library in C++ that provides functionality for input and output operations.

  * `std::cout` is used to output data to the screen.
  * `std::endl` adds a newline and flushes the output buffer.

#### Strings

* `std::string` is used to work with text strings.

#### `const`

* Declares a variable as constant (immutable after initialization).
* By convention, constants are written in uppercase.

#### `static`

- Local `static`: retains value between calls, initialized once.
- `static` in classes: variable shared among objects, defined outside class; function callable without instance, accesses only static members.
- `static` in files: limits scope of variables/functions to the file, avoiding conflicts.

#### Scope

* Global variables are accessible from anywhere in the program.
* Variables declared inside a block are only accessible within that block.

#### Arrays

* Arrays are stored in a contiguous block of memory.
* Their size is fixed at compile time.
* Accessing an out-of-bounds index causes undefined behavior.
* When passed to functions, arrays are passed by reference (as a pointer).
* Pointer arithmetic can be used to access elements.

#### For Loop

```cpp
for (initialization; condition; increment) {
  // loop body
}
```

* Initialization runs once.
* Condition is checked before each iteration.
* Increment runs after each iteration.

#### Do-While Loop

```cpp
do {
  // loop body
} while (condition);
```

* Executes the loop body at least once.

#### `continue` and `break`

* `continue`: skips to the next iteration.
* `break`: exits the loop.

#### Recursion

* A function that calls itself.

```cpp
int factorial(int n) {
  if (n == 0) return 1;
  else return n * factorial(n - 1);
}
```

* Recursion uses the stack; improper base cases lead to stack overflow.

#### Functions

```cpp
return_type function_name(parameter_type parameter_name) {
  // body
  return value;
}
```

* Functions can be overloaded (same name, different parameters).
* Passed by value: copies the variable.
* Passed by reference: allows modification of original.
* Passed by pointer: passes memory address.

#### Passing Variables

* **By Value**

  * Copies data. Changes inside function don’t affect the original.
* **By Reference**

  ```cpp
  void modify(int &x) { x = 10; }
  ```
* **By Pointer**

  ```cpp
  void modify(int *x) { *x = 10; }
  ```

#### Pointers

* Variables that store memory addresses.
* Declared with `*`, dereferenced with `*`.
* Used for dynamic memory and advanced data structures.

#### Dynamic Memory

* `new` allocates memory, returns a pointer.
* `delete` frees memory.

```cpp
int* p = new int;
delete p;
```

* Use `delete[]` for arrays.
* Always deallocate to avoid memory leaks.

#### Null Pointer

* A pointer that points to no valid memory.

#### Function Pointers

* Store function addresses.
* Can use `typedef` for cleaner syntax.

#### Lvalue vs. Rvalue

* **Lvalue**: has a memory address, can be assigned.
* **Rvalue**: temporary, no address, cannot be assigned to.

#### Variable Sizes

Use `sizeof(type)`:

```cpp
sizeof(int); // typically 4
```

Common sizes (64-bit systems):

| Type   | Size (bytes) |
| ------ | ------------ |
| char   | 1            |
| int    | 4            |
| float  | 4            |
| double | 8            |
| bool   | 1            |
| void\* | 8            |

---

### Interface vs Implementation

#### Separation of Concerns

* **Header (.hpp)**: contains function/class declarations (interface).
* **Source (.cpp)**: contains the implementation.

#### Example

`calculator.hpp`

```cpp
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
int add(int a, int b);
#endif
```

`calculator.cpp`

```cpp
#include "calculator.hpp"
int add(int a, int b) { return a + b; }
```

`main.cpp`

```cpp
#include <iostream>
#include "calculator.hpp"
int main() {
  std::cout << add(3, 4);
}
```

* Use `"filename.hpp"` for user-defined headers.
* Include guards prevent multiple inclusion.

---

### Structs and Classes

#### Struct

```cpp
struct Point {
  int x, y;
  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }
};
```

* Public members by default.
* Good for grouping simple data.

#### Class

```cpp
class Student {
private:
  std::string name;
  int age;
public:
  Student(std::string name, int age) {
    this->name = name;
    this->age = age;
  }
  void display() {
    std::cout << name << ", " << age << std::endl;
  }
};
```

* Private members by default.
* Supports encapsulation and abstraction.

#### Access Specifiers

* `public`: accessible from anywhere.
* `private`: accessible only within the class.
* `protected`: accessible in class and subclasses.

#### Constructor / Destructor

* **Constructor**: runs on object creation.
* **Destructor**: runs on object destruction.

```cpp
class Book {
public:
  Book() { std::cout << "Book created!"; }
  ~Book() { std::cout << "Book destroyed!"; }
};
```

#### Copy Constructor

* Used when an object is copied.
* Default copy constructor performs shallow copy.

#### Rule of Three

If your class needs any of the following, it likely needs **all three**:

1. **Destructor**
2. **Copy Constructor**
3. **Copy Assignment Operator**

This is to **avoid shallow copies** and ensure proper memory/resource management.

##### Example:

```cpp
class MyClass {
private:
  int* data;
public:
  MyClass(int value) {
    data = new int(value);
  }

  // Destructor
  ~MyClass() {
    delete data;
  }

  // Copy Constructor
  MyClass(const MyClass& other) {
    data = new int(*other.data);
  }

  // Copy Assignment Operator
  MyClass& operator=(const MyClass& other) {
    if (this != &other) {
      delete data;
      data = new int(*other.data);
    }
    return *this;
  }
};
```

Without proper handling, a shallow copy of the `data` pointer would lead to **double delete** errors or memory leaks.

#### `this` Pointer

* Refers to the current object.

```cpp
this->name = name;
```

#### Object

* An instance of a class.

```cpp
Student s("John", 20);
```

### Classes Advanced Concepts

#### RAII (Resource Acquisition Is Initialization)
RAII is a programming idiom ensuring that resources such as memory, file handles, and network connections are properly acquired and released.
- The resource is acquired in a class constructor and released in its destructor.
- This guarantees resource cleanup automatically when objects go out of scope.

#### Copy Constructor and Copy Assignment Operator
- C++ provides a default copy constructor and assignment operator that perform shallow copies (copy pointer values, not the data).
- This can cause issues like double deletion or shared ownership of resources.
- Implementing deep copy versions avoids these problems by copying the actual data.
- The copy-and-swap idiom is a safe way to implement copy assignment, allowing exception safety and self-assignment protection.
- Sometimes, you can make copy constructors private to prevent copying outside the class, enforcing reference passing instead.

#### Operator Overloading (Example: Vector3f class)
- Overload operators to make custom classes behave like built-in types.
- Example operators:
  - operator+ to add vectors.
  - operator++ for incrementing values.
  - operator== to compare equality.
  - operator<< for output streaming (e.g., printing).

- Remember:
  - Use const where appropriate for safety.
  - Floating-point equality should use a tolerance because of precision issues (e.g., std::abs(a - b) < tolerance).

#### Inheritance and Access Specifiers
##### Types of Inheritance and Member Access
| Inheritance Type | Base `public` Members | Base `protected` Members | Base `private` Members |
| ---------------- | --------------------- | ------------------------ | ---------------------- |
| **public**       | public                | protected                | inaccessible           |
| **protected**    | protected             | protected                | inaccessible           |
| **private**      | private               | private                  | inaccessible           

- Derived classes inherit members according to inheritance type.
- Private members of the base class are never accessible directly by derived classes.

#### Polymorphism and Virtual Functions
- Virtual functions allow derived classes to override base class methods, enabling dynamic dispatch at runtime.
- A vtable (virtual table) is generated by the compiler for classes with virtual functions.
- Each object holds a pointer (vptr) to its class's vtable.
- Virtual destructors are essential in polymorphic base classes to ensure proper cleanup of derived objects.

#### Virtual Tables (Vtables) Explained
- The vtable is an array of pointers to virtual functions of the class.
- When a virtual function is called on an object pointer/reference, the vtable lookup resolves the correct function implementation based on the object's dynamic type.
- Example:

```cpp
class Base {
    virtual ~Base() {}
    virtual void foo();
};
class Derived : public Base {
    ~Derived() override {}
    void foo() override;
};
```
The Derived class's vtable overrides Base's entries for virtual functions it implements.

#### Abstract Classes
- Contain pure virtual functions (declared with = 0) and cannot be instantiated directly.
- Derived classes must implement all pure virtual functions to become concrete (instantiable).
- Provide an interface and can define common functionality and virtual destructors.
- Base class pointers to abstract classes allow calling only the base's declared methods (virtual dispatches to derived implementations).
- New methods in derived classes are not accessible through base class pointers.

#### Multiple Inheritance and the Diamond Problem
- Multiple inheritance allows a class to inherit from more than one base class.
- The diamond problem arises when two base classes inherit from a common ancestor, and a derived class inherits from both, causing ambiguity about which base class member to use.
- C++ solves this using virtual inheritance, which ensures only one copy of the common base is included.
