#include <iostream>
#include <string>

// Abstract Product - Car
class Car {
public:
    virtual void displayInfo() const = 0;
    virtual void drive() const = 0;  // New drive method
    virtual ~Car() {}
};

// Concrete Product - SmallCar
class SmallCar : public Car {
public:
    void displayInfo() const override {
        std::cout << "This is a Small Car." << std::endl;
    }

    void drive() const override {
        std::cout << "The Small Car is driving smoothly in the city." << std::endl;
    }
};

// Concrete Product - BigCar
class BigCar : public Car {
public:
    void displayInfo() const override {
        std::cout << "This is a Big Car." << std::endl;
    }

    void drive() const override {
        std::cout << "The Big Car is driving powerfully on the highway." << std::endl;
    }
};

// Abstract Factory
class CarFactory {
public:
    virtual Car* createCar() const = 0;
    virtual ~CarFactory() {}
};

// Concrete Factory - SmallCarFactory
class SmallCarFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new SmallCar();
    }
};

// Concrete Factory - BigCarFactory
class BigCarFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new BigCar();
    }
};

// Client Code
int main() {
    CarFactory* smallCarFactory = new SmallCarFactory();
    CarFactory* bigCarFactory = new BigCarFactory();

    Car* smallCar = smallCarFactory->createCar();
    Car* bigCar = bigCarFactory->createCar();

    // Display info and drive the cars
    smallCar->displayInfo();  // Output: This is a Small Car.
    smallCar->drive();        // Output: The Small Car is driving smoothly in the city.

    bigCar->displayInfo();    // Output: This is a Big Car.
    bigCar->drive();          // Output: The Big Car is driving powerfully on the highway.

    // Clean up
    delete smallCar;
    delete bigCar;
    delete smallCarFactory;
    delete bigCarFactory;

    return 0;
}
