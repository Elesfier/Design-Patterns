
#include <iostream>
#include <memory>
#include <chrono>
#include <string>
using namespace std;
 
// Produkt
class Pizza
{
	private:
	
		std::string dough;
		std::string sauce;
		std::string topping;
	 
	public:

		Pizza() { }
		~Pizza() { }
	 
		void SetDough(const std::string& d) { dough = d; };
		void SetSauce(const std::string& s) { sauce = s; };
		void SetTopping(const std::string& t) { topping = t; }
	 
		void ShowPizza()
		{
			std::cout << " Yummy !!!" << std::endl
			<< "Pizza with Dough as " << dough
			<< ", Sauce as " << sauce
			<< " and Topping as " << topping
			<< " !!! " << std::endl;
		}
};

// Abstrakcyjny Budowniczy
class PizzaBuilder
{
	protected:
	
		std::auto_ptr<Pizza> pizza;
		
	public:
	
		PizzaBuilder() {}
		virtual ~PizzaBuilder() {}
		
		std::auto_ptr<Pizza> GetPizza() { return pizza; }
	 
		/* bazowa metoda to jest createNewPizzaProduct, a 
		 * szczegolowe metody to sa na dole, i okreslaja,
		 * specyfikacje produkty czyli pizzy. */
		void createNewPizzaProduct() { pizza.reset (new Pizza); }
	 
		virtual void buildDough()=0;
		virtual void buildSauce()=0;
		virtual void buildTopping()=0;
 
};
 
// Konkretny Budowniczy 1
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    HawaiianPizzaBuilder() : PizzaBuilder() {}
    ~HawaiianPizzaBuilder(){}
 
    void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }
};

// Konkretny Budowniczy 2
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    SpicyPizzaBuilder() : PizzaBuilder() {}
    ~SpicyPizzaBuilder() {}
 
    void buildDough() { pizza->SetDough("pan baked"); }
    void buildSauce() { pizza->SetSauce("hot"); }
    void buildTopping() { pizza->SetTopping("pepperoni and salami"); }
};
 
// Nadzorca
class Waiter
{
	private:
	
		PizzaBuilder* pizzaBuilder;
		
	public:
	
		Waiter() : pizzaBuilder(NULL) {}
		~Waiter() { }
	 
		void SetPizzaBuilder(PizzaBuilder* b) { pizzaBuilder = b; }
		std::auto_ptr<Pizza> GetPizza() { return pizzaBuilder->GetPizza(); }
		void ConstructPizza()
		{
			pizzaBuilder->createNewPizzaProduct();
			pizzaBuilder->buildDough();
			pizzaBuilder->buildSauce();
			pizzaBuilder->buildTopping();
		}
};

int main()
{ 
    Waiter waiter;
 
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    waiter.SetPizzaBuilder (&hawaiianPizzaBuilder);
    waiter.ConstructPizza();
    std::auto_ptr<Pizza> pizza = waiter.GetPizza();
    pizza->ShowPizza();
 
    SpicyPizzaBuilder spicyPizzaBuilder;
    waiter.SetPizzaBuilder(&spicyPizzaBuilder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza->ShowPizza();
 
    return EXIT_SUCCESS;
}
