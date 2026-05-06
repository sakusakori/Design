#include <iostream>
#include "PlainPizza.h"
#include "Farmhouse.h"
#include "TandooriPaneerDelight.h"
#include "ChickenDominator.h"
#include "ExtraCheeseTopping.h"
#include "MushroomTopping.h"
#include "PepperoniTopping.h"
#include "VeggiesTopping.h"
using namespace std;

// Step 5: Client Demonstration
int main() {
    cout << "======= Decorator Design Pattern ======" << endl;

    // Create a plain pizza
    PlainPizza plain;
    BasePizza* pizza1 = &plain;
    cout << "Order 1: " << pizza1->getDescription() << " = Rs." << pizza1->getCost() << endl;

    // Add toppings to the PlainPizza - Extra Cheese Only
    PlainPizza plain2;
    ExtraCheeseTopping pizza2(&plain2);
    cout << "Order 2: " << pizza2.getDescription() << " = Rs." << pizza2.getCost() << endl;

    // Add toppings to the PlainPizza - Extra Cheese and Veggies
    PlainPizza plain3;
    ExtraCheeseTopping cheese3(&plain3);
    VeggiesTopping pizza3(&cheese3);
    cout << "Order 3: " << pizza3.getDescription() << " = Rs." << pizza3.getCost() << endl;

    // Add toppings to the PlainPizza - Extra Cheese and Pepperoni
    PlainPizza plain4;
    ExtraCheeseTopping cheese4(&plain4);
    PepperoniTopping pizza4(&cheese4);
    cout << "Order 4: " << pizza4.getDescription() << " = Rs." << pizza4.getCost() << endl;

    // Add toppings to the PlainPizza - Extra Cheese, Mushroom and Pepperoni
    PlainPizza plain5;
    ExtraCheeseTopping cheese5(&plain5);
    PepperoniTopping pepperoni5(&cheese5);
    MushroomTopping pizza5(&pepperoni5);
    cout << "Order 5: " << pizza5.getDescription() << " = Rs." << pizza5.getCost() << endl;

    // Farmhouse Pizza
    Farmhouse pizza6;
    cout << "Order 6: " << pizza6.getDescription() << " = Rs." << pizza6.getCost() << endl;

    // Farmhouse Pizza with Extra Cheese and Mushroom
    Farmhouse farm7;
    ExtraCheeseTopping cheese7(&farm7);
    MushroomTopping pizza7(&cheese7);
    cout << "Order 7: " << pizza7.getDescription() << " = Rs." << pizza7.getCost() << endl;

    // Tandoori Paneer Delight Pizza
    TandooriPaneerDelight pizza8;
    cout << "Order 8: " << pizza8.getDescription() << " = Rs." << pizza8.getCost() << endl;

    // Chicken Dominator
    ChickenDominator pizza9;
    cout << "Order 9: " << pizza9.getDescription() << " = Rs." << pizza9.getCost() << endl;

    // Chicken Dominator with Mushroom
    ChickenDominator chicken10;
    MushroomTopping pizza10(&chicken10);
    cout << "Order 10: " << pizza10.getDescription() << " = Rs." << pizza10.getCost() << endl;

    return 0;
}
