 # Exercises: Inheritance with Point3D & Particle

 Building on the `Point3D` class, these exercises introduce inheritance,
 virtual functions, polymorphism (via references), and object slicing in C++.

 ## Exercise 1: Base Class Point3D

 1. Create `Point3D.h`:
    ```cpp
    #pragma once
    #include <iostream>

    class Point3D {
    protected:
        double x_, y_, z_;
    public:
        Point3D();
        Point3D(double x, double y, double z);
        virtual ~Point3D() = default;
        virtual void print() const;  // prints "(x, y, z)"
    };
    ```
 2. Implement `Point3D.cpp`:
    ```cpp
    #include "Point3D.h"

    Point3D::Point3D() : x_(0), y_(0), z_(0) {}
    Point3D::Point3D(double x, double y, double z)
      : x_(x), y_(y), z_(z) {}

    void Point3D::print() const {
        std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
    }
    ```
 3. In `main.cpp`, include `Point3D.h`, construct:
    ```cpp
    Point3D p(1.0, 2.0, 3.0);
    p.print();  // expect: (1, 2, 3)
    ```

 ## Exercise 2: Derived Class Particle

 1. Create `Particle.h`:
    ```cpp
    #pragma once
    #include "Point3D.h"

    class Particle : public Point3D {
        double mass_;
    public:
        Particle(double x, double y, double z, double mass);
        void print() const override;  // prints position and mass
    };
    ```
 2. Implement `Particle.cpp`:
    ```cpp
    #include "Particle.h"
    #include <iostream>

    Particle::Particle(double x, double y, double z, double mass)
      : Point3D(x,y,z), mass_(mass) {}

    void Particle::print() const {
        Point3D::print();
        std::cout << ", mass=" << mass_;
    }
    ```
 3. In `main.cpp`, add:
    ```cpp
    Particle part(4.0, 5.0, 6.0, 1.23);
    part.print();  // expect: (4, 5, 6), mass=1.23
    ```

 ## Exercise 3: Specialization with ChargedParticle

 1. Create `ChargedParticle.h`:
    ```cpp
    #pragma once
    #include "Particle.h"

    class ChargedParticle : public Particle {
        double charge_;
    public:
        ChargedParticle(double x, double y, double z,
                        double mass, double charge);
        void print() const override;  // prints position, mass, and charge
    };
    ```
 2. Implement `ChargedParticle.cpp`:
    ```cpp
    #include "ChargedParticle.h"
    #include <iostream>

    ChargedParticle::ChargedParticle(double x, double y, double z,
                                     double mass, double charge)
      : Particle(x,y,z,mass), charge_(charge) {}

    void ChargedParticle::print() const {
        Particle::print();
        std::cout << ", charge=" << charge_;
    }
    ```
 3. In `main.cpp`, add:
    ```cpp
    ChargedParticle cp(7.0, 8.0, 9.0, 2.0, -1.6e-19);
    cp.print();  // expect: (7, 8, 9), mass=2, charge=-1.6e-19
    ```

 ## Exercise 4: Polymorphism via References

 1. Write a helper in `main.cpp`:
    ```cpp
    void printAny(const Point3D& obj) {
        obj.print();
        std::cout << std::endl;
    }
    ```
 2. In `main.cpp`, construct three objects:
    ```cpp
    Point3D base(1,2,3);
    Particle p(4,5,6, 1.0);
    ChargedParticle cp(7,8,9, 2.0, 1.0);
    ```
 3. Call:
    ```cpp
    printAny(base);
    printAny(p);
    printAny(cp);
    ```
    Observe that each call uses the correct `print()` implementation.

 ## Exercise 5: Object Slicing

 1. Write another helper:
    ```cpp
    void printByValue(Point3D obj) {
        obj.print();
        std::cout << std::endl;
    }
    ```
 2. Call:
    ```cpp
    printByValue(p);
    printByValue(cp);
    ```
    Notice that only `Point3D::print()` runs because of slicing.
 3. Explain why slicing occurred when passing by value.

 ## Quiz Questions

 - Why do we declare `print()` as `virtual` in the base class?  
 - How does passing by reference enable polymorphism?  
 - What is object slicing, and when does it happen?  
 - Why is it important for a base class to have a virtual destructor, even if we’re not using pointers yet?  
 - When would you prefer inheritance over composition in a design?  