#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

/* Łańcuch zobowiązań (ang. Chain of responsibility, niekiedy 
 * tłumaczony także jako Łańcuch odpowiedzialności) – czynnościowy 
 * wzorzec projektowy, w którym żądanie może być przetwarzane przez 
 * różne obiekty, w zależności od jego typu. */

/*! Wzorzec Łańcuch zobowiązań zakłada utworzenie oddzielnej 
 * klasy dla każdej procedury obsługi żądania dziedziczącej 
 * po pewnej klasie bazowej AbstrakcyjnaObsluga. Obiekt każdej 
 * z procedur może posiadać wskazanie na następnik, tworząc w ten
 * sposób łańcuch procedur przetwarzania. Aby przetworzyć żądanie,
 * wykonujemy metodę operacja() na pierwszym elemencie łańcucha. 
 * Jeśli nie potrafi on przetworzyć żądania, powinien przekazać je 
 * swojemu następnikowi: */

class Base
{
		Base *next; // 1. "next" pointer in the base class
		
	  public:
	  
		Base()
		{
			next = 0;
		}
		void setNext(Base *n)
		{
			next = n;
		}
		void add(Base *n)
		{
			if (next)
			  next->add(n);
			else
			  next = n;
		}
		// 2. The "chain" method in the base class always delegates to the next obj
		virtual void handle(int i)
		{
			next->handle(i);
		}
};

class Handler1: public Base
{
	  public:
	  
		 /*virtual*/void handle(int i)
		{
			if (rand() % 3)
			{
				// 3. Don't handle requests 3 times out of 4
				cout << "H1 passsed " << i << "  ";
				Base::handle(i); // 3. Delegate to the base class
			}
			else
			  cout << "H1 handled " << i << "  ";
		}
};

class Handler2: public Base
{
	  public:
	  
		 /*virtual*/void handle(int i)
		{
			if (rand() % 3)
			{
				cout << "H2 passsed " << i << "  ";
				Base::handle(i);
			}
			else
			  cout << "H2 handled " << i << "  ";
		}
};

class Handler3: public Base
{
	  public:
	  
		 /*virtual*/void handle(int i)
		{
			if (rand() % 3)
			{
				cout << "H3 passsed " << i << "  ";
				Base::handle(i);
			}
			else
			  cout << "H3 handled " << i << "  ";
		}
};

int main()
{
	  srand(time(0));
	  Handler1 root;
	  Handler2 two;
	  Handler3 thr;
	  root.add(&two);
	  root.add(&thr);
	  thr.setNext(&root);
	  for (int i = 1; i < 10; i++)
	  {
		root.handle(i);
		cout << '\n';
	  }
}
