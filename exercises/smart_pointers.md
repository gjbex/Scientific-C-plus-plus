 # Exercises: Smart Pointers & Non-Owning Pointers

 These exercises cover modern C++ memory management with `std::unique_ptr`,
 `std::shared_ptr`, `std::weak_ptr`, and passing raw pointers or references
 when ownership is not transferred.

 ## Exercise 1: Basic unique_ptr Usage

 1. Include `<memory>`. In `main()`, create a `std::unique_ptr<int>`:
    ```cpp
    auto p1 = std::make_unique<int>(42);
    ```
 2. Print the value via `*p1`.
 3. Write a function:
    ```cpp
    std::unique_ptr<int> increment(std::unique_ptr<int> p) {
        ++*p;
        std::cout << "Inside increment: " << *p << "\n";
        return p;
    }
    ```
 4. In `main()`, call:
    ```cpp
    p1 = increment(std::move(p1));
    ```
    Show that after `std::move(p1)` you must reassign the return value to regain ownership.

 ## Exercise 2: unique_ptr in a Container

 1. Define a small class `Thing` with an `int id_` and a member `void print() const;`.
 2. Create a vector:
    ```cpp
    std::vector<std::unique_ptr<Thing>> things;
    ```
 3. Populate it with several `Thing` objects:
    ```cpp
    things.push_back(std::make_unique<Thing>(1));
    things.push_back(std::make_unique<Thing>(2));
    // ...
    ```
 4. Loop over `things` and call `print()` on each.

 ## Exercise 3: Basic shared_ptr Usage

 1. In `main()`, create:
    ```cpp
    auto s1 = std::make_shared<int>(100);
    std::cout << "use_count before: " << s1.use_count() << "\n";
    auto s2 = s1;
    std::cout << "use_count after copy: " << s1.use_count() << "\n";
    s1.reset();
    std::cout << "use_count after reset: " << s2.use_count() << "\n";
    ```
 2. Explain how `shared_ptr` tracks the number of owners and destroys the managed object when the count reaches zero.

 ## Exercise 4: Avoiding Cycles with weak_ptr

 1. Create two classes `A` and `B` where:
    ```cpp
    struct B;
    struct A { std::shared_ptr<B> bptr; };
    struct B { std::shared_ptr<A> aptr; };
    ```
 2. Instantiate `auto a = std::make_shared<A>(); auto b = std::make_shared<B>();` and set `a->bptr = b; b->aptr = a;`.
    Observe that this cycle prevents both destructors from running.
 3. Change `B::aptr` to `std::weak_ptr<A>` and use `lock()` to access the `A` object safely.

 ## Exercise 5: Non-Owning Raw Pointers & References

 1. Write a class `Data`:
    ```cpp
    class Data {
        int value_;
    public:
        explicit Data(int v) : value_(v) {}
        int get() const { return value_; }
    };
    ```
 2. Write two functions:
    ```cpp
    void process(const Data* d) {
        std::cout << "Pointer version: " << d->get() << "\n";
    }
    void process(const Data& d) {
        std::cout << "Reference version: " << d.get() << "\n";
    }
    ```
 3. In `main()`, do:
    ```cpp
    Data d(123);
    process(&d);
    process(d);
    ```
 4. Explain why these functions do not take ownership and why raw pointers or references are appropriate here.

 ## Quiz Questions

 - When should you use `std::unique_ptr` instead of `std::shared_ptr`?  
 - What is a `std::weak_ptr` for, and how do you obtain a `std::shared_ptr` from it?  
 - What happens if you copy a `std::unique_ptr`?  
 - Why pass by raw pointer or reference for functions that don’t own their arguments?  
 - How do custom deleters work with smart pointers?  