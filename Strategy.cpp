#include <string>
#include <iostream>
#include <vector>
using namespace std;
 

/* Strategia – czynnościowy wzorzec projektowy, który definiuje 
 * rodzinę wymiennych algorytmów i kapsułkuje je w postaci klas. 
 * Umożliwia wymienne stosowanie każdego z nich w trakcie
 * działania aplikacji niezależnie od korzystających z nich klientów.*/
 

/*! Rozważmy program generujący statystyki dotyczące podanego na 
 * wejściu kodu źródłowego takie, jak liczba wierszy, liczba klas
 * itd. W mechanizmie generowania statystyk możemy wyróżnić część
 * kodu specyficzną dla języka programowania, w którym napisany 
 * został kod oraz ogólną, niezależną od języka. Chcielibyśmy, aby 
 * nasz program był uniwersalny i obsługiwał wiele języków 
 * programowania, a także by w przyszłości istniała możliwość 
 * dodawania nowych. 
 * Rozwiązaniem jest zastosowanie wzorca Strategia, gdzie algorytmy 
 * specyficzne dla języków programowania wydzielimy jako osobne klasy 
 * ze wspólnym interfejsem, który umożliwi programowi wyciąganie
 * określonych informacji o kodzie źródłowym. */ 
 

/* Reprezentuje rycerza
 */
class Knight 
{
    private:
    
        unsigned int age;
        string name;
 
    public:
    
        Knight(unsigned int ag, string nm) : age(ag), name(nm) {}
 
        unsigned int getAge() const 
        {
            return age;
        }
 
        string getName() const 
        {
            return name;
        }
};
 
 
/* Interfejs validatora
 */
class KnightValidator 
{
    public:
        virtual ~KnightValidator() {}
        
        virtual bool validate(Knight const&) = 0;
};
 
 
/* Przyjmuje tylko rycerzy w wieku ponad 60 lat
 */
class OldKnightsValidator : public KnightValidator 
{
    public:
    
        bool validate(Knight const& kn) 
        {
            return kn.getAge() > 60;
        }
};
 
 
/* Przyjmuje tylko rycerzy o imionach brzmiących męsko
 * (pomijamy Barnabę itp.)
 */
class MaleKnightsValidator : public KnightValidator 
{
    public:
    
        bool validate(Knight const& kn) 
        {
            string name = kn.getName();
            return name.at(name.length() - 1) != 'a';
        }
};
 
 
/* Reprezentuje arenę
 */
class Arena 
{
    private:
    
        vector<Knight> knights;
        KnightValidator* validator;
 
    public:
    
        Arena(KnightValidator* valptr) : validator(valptr) {}
 
        void addKnight(Knight const& kn) 
        {
            if (validator->validate(kn)) 
            {
                knights.push_back(kn);
            }
        }
 
        void printKnights() const 
        {
            for (vector<Knight>::const_iterator it = knights.begin(); it != knights.end(); ++it) 
            {
                cout << it->getName() << '\n';
            }
        }
};
 
 
// Przykład użycia
int main() 
{
		Knight anna(20, "Anna");
		Knight zbyszko(40, "Zbyszko");
		Knight dobromil(70, "Dobromil");
		OldKnightsValidator ovalid;
		MaleKnightsValidator mvalid;
		Arena eldersArena(&ovalid);
		Arena malesArena(&mvalid);
	 
		eldersArena.addKnight(anna);
		eldersArena.addKnight(zbyszko);
		eldersArena.addKnight(dobromil);
	 
		malesArena.addKnight(anna);
		malesArena.addKnight(zbyszko);
		malesArena.addKnight(dobromil);
	 
		cout << " === Arena seniorow ===\n";
		eldersArena.printKnights();
		cout << " === Arena bez rownoupranienia ===\n";
		malesArena.printKnights();
}
