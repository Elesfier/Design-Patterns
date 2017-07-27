
#include <string>
#include <iostream>
#include <memory> // std::auto_ptr

class Pizza {
public:
    virtual void get_price() const = 0;
    virtual ~Pizza() {};
};
 
class HamAndMushroomPizza: public Pizza {
public:
    virtual void get_price() const {
        std::cout << "Ham and Mushroom: $8.5" << std::endl;
    }
};
 
class DeluxePizza : public Pizza {
public:
    virtual void get_price() const {
        std::cout << "Deluxe: $10.5" << std::endl;
    }
};
 
class HawaiianPizza : public Pizza {
public:
    virtual void get_price() const {
        std::cout << "Hawaiian: $11.5" << std::endl;
    }
};
 
class PizzaFactory {
public:
    static Pizza* create_pizza(const std::string& type) {
        if (type == "Ham and Mushroom")
            return new HamAndMushroomPizza();
        else if (type == "Hawaiian")
            return new HawaiianPizza();
        else
            return new DeluxePizza();
    }
};

//usage
int main() {
 
    std::auto_ptr<const Pizza> pizza(PizzaFactory::create_pizza("Default"));
    pizza->get_price();
 
    pizza.reset(PizzaFactory::create_pizza("Ham and Mushroom"));
    pizza->get_price();
 
    pizza.reset(PizzaFactory::create_pizza("Hawaiian"));
    pizza->get_price();
}
