# Glossary

The C++ community uses various acronyms and terms that may not be familiar to
everyone. This glossary provides definitions for some of the most commonly used
terms in C++ programming.

Note that this is work in progress, new terms are added as I come across them.

ABI: Application Binary Interface. A set of rules and conventions that dictate how
different binary components of a program interact at the machine code level. This
includes aspects such as data type sizes, alignment, calling conventions, and
name mangling.

ADL: Argument-Dependent Lookup. A C++ feature that allows the compiler to
consider functions in the namespaces of the argument types when resolving
function calls.

ALU: Arithmetic Logic Unit. A digital circuit within the CPU that performs
arithmetic and logical operations on binary data.

AOP: Aspect-Oriented Programming. A programming paradigm that aims to increase
modularity by allowing the separation of cross-cutting concerns, such as logging
or security, from the main business logic.

AoS: Array of Structures. A data layout where multiple structures are stored in
an array, with each structure containing multiple fields.

API: Application Programming Interface. A set of functions, classes, or
protocols that allow different software components to communicate with each other.

BLAS: Basic Linear Algebra Subprograms. A specification that defines a set of
low-level routines for performing common linear algebra operations such as
vector and matrix multiplication.

constexpr: A keyword in C++ that indicates that a function or variable can be
evaluated at compile time, allowing for optimizations and improvements in
performance.

core: A single processing unit within a CPU that can independently execute
instructions. Modern CPUs often have multiple cores to enable parallel processing.

CPU: Central Processing Unit. The primary component of a computer that performs
most of the processing tasks.

CRTP: Curiously Recurring Template Pattern. A C++ programming technique where a
class template derives from a specialization of itself, enabling static polymorphism
and code reuse.

D-cache: Data Cache. A small, fast memory located within the CPU that stores
frequently accessed data to improve performance.

DRAM: Dynamic Random Access Memory. A type of volatile memory used in computers
to store data that is being actively used or processed.

DRY: Don't Repeat Yourself. A software development principle that emphasizes
the importance of reducing code duplication by abstracting common functionality
into reusable components.

GoF: Gang of Four. A term commonly used to refer to the four authors of the
book "Design Patterns: Elements of Reusable Object-Oriented Software" (Erich
Gamma, Richard Helm, Ralph Johnson, and John Vlissides), which introduced
23 classic design patterns.

GPU: Graphics Processing Unit. A specialized processor designed to accelerate
the rendering of images and videos, often used for parallel processing tasks.

HBM: High Bandwidth Memory. A type of memory technology that provides higher
bandwidth and lower power consumption compared to traditional memory types,
often used in high-performance computing and graphics applications.

HDD: Hard Disk Drive. A traditional data storage device that uses spinning disks
to read and write data.

HDF5: Hierarchical Data Format version 5. A file format and
set of tools for managing complex data, commonly used in scientific computing
for storing large datasets.

I-cache: Instruction Cache. A small, fast memory located within the CPU that
stores frequently accessed instructions to improve performance.

IIFE: Immediately Invoked Function Expression. A programming pattern where a
function is defined and immediately called, often used to create a new scope
and avoid polluting the global namespace.

I/O: Input/Output. The communication between a computer system and the outside
world, including devices such as keyboards, mice, displays, and storage devices.

L1, L2, L3 Cache: Levels of CPU cache memory that store frequently accessed data
to improve performance. L1 is the smallest and fastest, while L3 is larger and
slower.

LAPACK: Linear Algebra PACKage. A software library that provides routines for
solving systems of linear equations, eigenvalue problems, and singular value
decompositions.

LLC: Last Level Cache. The largest and slowest cache level in a CPU, typically
shared among multiple cores. This is almost always the L3 cache.

LTO: Link Time Optimization. A compiler optimization technique that performs
optimizations across multiple translation units during the linking phase, leading
to improved performance and reduced code size.

Lvalue: An expression that refers to a memory location and allows taking the
address of that location. Lvalues can appear on the left side of an assignment.

MMU: Memory Management Unit. A hardware component responsible for handling
virtual memory and memory protection in a computer system.

MPI: Message Passing Interface. A standardized and portable message-passing
system designed to function on parallel computing architectures, enabling
communication between processes.

ODR: One Definition Rule. A rule in C++ that states that an object or function
can have only one definition in a program, but can be declared multiple times.

OpenACC: Open Accelerators. An open standard for parallel programming of
heterogeneous systems, allowing developers to write code that can run on CPUs,
GPUs, and other accelerators using compiler directives.

OpenMP: Open Multi-Processing. An API that supports multi-platform shared memory
parallel programming in C, C++, and Fortran, allowing developers to write
parallel code using compiler directives.

Pimpl: Pointer to Implementation. A design pattern used to hide implementation
details of a class from its interface, reducing compilation dependencies and
improving encapsulation.

POD: Plain Old Data. A term used to describe simple data structures that are
compatible with C-style structs, meaning they have no user-defined
constructors, destructors, or virtual functions.

RAII: Resource Acquisition Is Initialization. A programming idiom where
resource allocation is tied to object lifetime, ensuring that resources are
properly released when the object goes out of scope.

RAM: Random Access Memory. A type of computer memory that allows data to be
accessed in any order, providing fast read and write operations.

RTTI: Run-Time Type Information. A mechanism that allows the type of an object
to be determined at runtime. It is used for dynamic casting and type
identification.

Rvalue: An expression that does not refer to a memory location and cannot have
its address taken. Rvalues typically appear on the right side of an assignment.

SFINAE: Substitution Failure Is Not An Error. A C++ template metaprogramming
technique that allows the compiler to ignore certain template instantiations
that would result in errors, enabling more flexible and powerful template code.
In modern C++, SFINAE is often replaced by concepts and requires-clauses for
better readability and error messages.

SIMD: Single Instruction, Multiple Data. A parallel computing architecture that
allows a single instruction to be executed on multiple data points simultaneously,
improving performance for certain types of computations.

SoA: Structure of Arrays. A data layout where each field of a structure is stored
in a separate array, which can improve cache performance and enable better
vectorization.

SOLID: A set of five design principles for object-oriented programming that
aim to create more maintainable and understandable software. The principles are:
  - Single Responsibility Principle
  - Open/Closed Principle
  - Liskov Substitution Principle
  - Interface Segregation Principle
  - Dependency Inversion Principle

SSD: Solid State Drive. A type of data storage device that uses flash memory
to store data, providing faster access times and improved durability compared
to traditional hard disk drives.

STL: Standard Template Library. A collection of C++ template classes and
functions that provide general-purpose data structures and algorithms.

TBB: Threading Building Blocks. A C++ library developed by Intel that provides
high-level abstractions for parallel programming, making it easier to write
efficient multi-threaded applications.

TDD: Test-Driven Development. A software development approach where tests are
written before the actual code, guiding the design and implementation of the
software.

TLB: Translation Lookaside Buffer. A cache used by the CPU to improve the speed
of virtual-to-physical address translation.

UB: Undefined Behavior. A situation in C++ where the behavior of the program is
not defined by the C++ standard, often leading to unpredictable results.
