
#include <iostream>

using namespace std;
 
// Przykład Wrappera Klasowego

//Implementacja Interfejsu Klasy Klienta
class Circle
{
	public:
		virtual void draw() = 0;
};

//Klasa adaptowana
class StandardCircle
{
	public:
		StandardCircle(double radius)
		{
		  radius_ = radius;
			cout << "StandardCircle:  create. radius = "<< radius_ << endl;
		}
		void oldDraw()
		{
			cout << "StandardCircle:  oldDraw. " << radius_ << endl;
		}
	private:
		double radius_ ;
};
 
//Klasa Adatera
class CAdapter : public Circle, private StandardCircle 
{
	public:
		CAdapter( double diameter)
			: StandardCircle(diameter/2)
		{
			cout << "CAdapter: create. diameter = " << diameter << endl;
		}
		//łączenie się metod
		virtual void draw()
		{
			cout << "CAdapter: draw." << endl;
			oldDraw();
		}
};

int main()
{
    Circle*  c = new CAdapter(14);
    c->draw();
    return(0);
}
