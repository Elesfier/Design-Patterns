
#include <iostream>
using namespace std; 

//Abstrakcyjny Produkt
class Button 
{
	public:
	
    virtual void render() = 0;
};

//Konkretny Produkt 1
class WindowsButton: public Button 
{
	public:
    
		void render() 
		{
			cout << "Windows Button";
		}
};
 
//Konkretny Produkt 2
class LinuxButton: public Button 
{
	public:
  
		void render() 
		{
			cout << "Linux Button";
		}
};

//Abstrakcyjna Fabryka Produktów
class ButtonFactory 
{
	public:
  
		virtual Button* createButton() = 0;
};
 
//Konkretna Fabryka Produktów 1
class WindowsFactory: public ButtonFactory 
{
	public:
  
		Button* createButton() 
		{
			/* ten moment jest najwazniejszy konkretna fabryka 
			 * produkuje konkretny obiekt */
			return new WindowsButton();
		}
};
 
//Konkretna Fabryka Produktów 2
class LinuxFactory: public ButtonFactory 
{
	public:
  
		Button* createButton() 
		{
			/* ten moment jest najwazniejszy konkretna fabryka 
			 * produkuje konkretny obiekt */
			return new LinuxButton();
		}
};

//Nadzorca
class Application 
{
  public:
  
	int system;
 
    ButtonFactory* getButtonFactory() 
    {
		if(system == 1) return new WindowsFactory();
		else if(system == 2) return new LinuxFactory();
		return(NULL);
	}
};

/*! Fabryka abstrakcyjna różni się od Budowniczego, 
 * tym że kładzie nacisk na tworzenie produktów z konkretnej rodziny, 
 * a Budowniczy kładzie nacisk na sposób tworzenia obiektów. */

int main()
{
    Application* a = new Application();
    a->system = 2;
 
    ButtonFactory* b = a->getButtonFactory();
 
    Button* c = b->createButton();
    c->render();
}
