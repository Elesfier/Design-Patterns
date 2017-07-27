
#include <iostream>
#include <string>
#include <list>

//Obserwator
class Obserwator 
{
	public:
	
		virtual void update() = 0;
		virtual ~Obserwator(){};
};

//Obserwowany
class Obserwowany 
{
	protected:
	
		std::list <Obserwator*> obserwatorzy;
		
	public:
	
		void dodaj(Obserwator *o) 
		{
			obserwatorzy.push_back (o);
		}
		
		void usun(Obserwator *o) 
		{
			obserwatorzy.remove (o);
		}
	 
		void powiadom () 
		{
			std::list<Obserwator *>::iterator it;
			for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
			{
				(*it)->update ();
			}
		}
};


class Miod 
{
	protected:
	
		int ilosc;
		
	public:
	
		Miod (int q) 
		{
			ilosc = q;
		}
	 
		int pobierzIlosc () 
		{
			return ilosc;
		}
	 
		void ustawIlosc (int q) 
		{
			ilosc = q;
		}
};

//Obserwowany konkretny
class ObserwowanyMiod : public Obserwowany, public Miod 
{
		std::string stan;
		
	public:
	
		ObserwowanyMiod (int q) : Miod(q) 
		{
			
		}
	 
		std::string pobierzStan () 
		{
			return stan;
		}
	 
		void ustawStan (const std::string& s) 
		{
			stan = s;
			std::cout << "Stan: " << stan << std::endl;
			powiadom();
		}
};

//Obserwator konkretny
class ObserwatorMis : public Obserwator 
{
	protected:
	
		int misId;
		ObserwowanyMiod *miod;
		
	public:
	
		ObserwatorMis (ObserwowanyMiod *h, int id) 
		{
			miod = h;
			misId = id;
		}
		
		void update () 
		{
			std::string stan = miod->pobierzStan();
			if (!stan.compare ("Sa ludzie blisko miodu")) 
			{
				std::cout << "Mis" << misId << ": Czekam w ukryciu" << std::endl;
			} 
			else if (!stan.compare ("Nie ma ludzi blisko miodu")) 
			{
				std::cout << "Mis" << misId << ": Kradne miod" << std::endl;
				miod->ustawIlosc(miod->pobierzIlosc()-1);
			} 
			else if (!stan.compare ("Ida ludzie")) 
			{
				std::cout << "Mis" << misId << ": Uciekam" << std::endl;
			}
		}
};

int main() 
{
    ObserwowanyMiod miod (5);
    Obserwator *mis1 = new ObserwatorMis(&miod, 1);
    Obserwator *mis2 = new ObserwatorMis(&miod, 2);
 
    miod.dodaj(mis1);
    miod.dodaj(mis2);
 
    std::cout << "Ilosc miodu: " << miod.pobierzIlosc() << std::endl;
 
    miod.ustawStan("Sa ludzie blisko miodu");
    miod.ustawStan("Nie ma ludzi blisko miodu");
    miod.ustawStan("Ida ludzie");
 
    std::cout << "Ilosc miodu: " << miod.pobierzIlosc() << std::endl;
    delete mis1;
    delete mis2;
    return 0;
}
