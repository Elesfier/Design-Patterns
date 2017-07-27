
#include <iostream>
#include <string>
using namespace std;

/* Standardowy nieudekorowany samochod */
class Samochod 
{
protected:

	string samochod;
	double wartosc;
	 
public:

	Samochod()
	{
		samochod = "Samochod podstawowy";
		wartosc=0;
	}
	 
	virtual string about()
	{
		return samochod;
	}
	 
	virtual double cena()
	{
		return wartosc;
	}
};
 
/* abstrakcyjny dekorator */
class Dekorator : public Samochod 
{ 
public:

	virtual string about()
	{
		return "hmm";
	}
};
	 
/* teraz mamy 2 przykladowe marki samochodow */
class Mercedes : public Samochod
{
	 
public:
 
	Mercedes():Samochod()
	{
		samochod = "Mercedes";
		wartosc=500000;
	}
	 
};
	 
class Fiat : public Samochod 
{
	public: Fiat():Samochod()
	{
		samochod = "Fiat";
		wartosc=100000;
	}
};
 
/* czas na same dodatki */
class Klimatyzacja : public Dekorator 
{
	Samochod *car;
	 
public:
 
	Klimatyzacja(Samochod *samochod):Dekorator()
	{
		car = samochod;
	}
	 
	string about()
	{
		return car->about() + " + klimatyzacja";
	}
	 
	double cena()
	{
		return car->cena()+1111;
	}
};
 
class OponyZimowe : public Dekorator 
{
	Samochod *car;
	 
	public: OponyZimowe(Samochod *samochod):Dekorator()
	{
		car = samochod;
	}
	 
	string about()
	{
		return car->about() + " + opony zimowe";
	}
	 
	/* niech ceny beda takie same */
	double cena()
	{
		return car->cena() + 31234;
	}
};

/*! Bardzo przydatny wrzorzec ktory dodaje nowa funkcjonalnosci,
 * jakiemus obiektowi */
 
int main()
{
	Samochod *s1 = new Mercedes();
	Samochod *s2 = new Fiat();
	 
	cout<<"\nBez wyposazenia"<<endl;
	cout<<s1->about()<<" "<<s1->cena()<<endl;
	cout<<s2->about()<<" "<<s2->cena()<<endl;
	 
	//dodajemy po klimie
	s1 = new Klimatyzacja(s1);
	s2 = new Klimatyzacja(s2);
	cout<<"\nZ Klima"<<endl;
	cout<<s1->about()<<" "<<s1->cena()<<endl;
	cout<<s2->about()<<" "<<s2->cena()<<endl;
	 
	// i opony
	 
	s1 = new OponyZimowe(s1);
	s2 = new OponyZimowe(s2);
	cout<<"\nZ oponami"<<endl;
	cout<<s1->about()<<" "<<s1->cena()<<endl;
	cout<<s2->about()<<" "<<s2->cena()<<endl;
	 
	//odrazu tworzymy wyposazony samochod
	cout<<"\nPelne wyposazenie"<<endl;
	Samochod *s3 =  new OponyZimowe( new Klimatyzacja( new Mercedes()));
	cout<<s3->about()<<" "<<s1->cena()<<endl;
	 
	return 0;
}
