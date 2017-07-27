
#include <cstdio>
#include <cstring>

//Prototyp
class IPrototype
{
	public:
	
		virtual IPrototype * Klonuj() const = 0;
		virtual void Wypisz() const = 0;
		virtual ~IPrototype() { }
};

//Konkretny Prototyp
class CMyPrototype1 : public IPrototype
{
	private:
	
		int m_iLiczba;
		char * m_pNapis;
		
	public:
	
		CMyPrototype1( int iLiczba, const char * sNapis ): m_iLiczba( iLiczba ), m_pNapis( new char[ strlen( sNapis ) + 1 ] )
		{
			strcpy( m_pNapis, sNapis );
		}
	   
		CMyPrototype1( const CMyPrototype1 & kopia ): m_iLiczba( kopia.m_iLiczba ), m_pNapis( new char[ strlen( kopia.m_pNapis ) + 1 ] )
		{
			strcpy( m_pNapis, kopia.m_pNapis );
		}
	   
		virtual ~CMyPrototype1()
		{
			delete[] m_pNapis;
		}
	   
		virtual IPrototype * Klonuj() const
		{
			//INFO: Przykładowa implementacja klonowania
			return new CMyPrototype1( * this );
		}
	   
		virtual void Wypisz() const
		{
			printf( "Liczba = %d\n", m_iLiczba );
			printf( "Komunikat = \"%s\"\n", m_pNapis );
		}
};

/*! Na podstawie jakiegos prototypa, tworzy sie obiekty, czyli musi
 * być jeden bazowy obiekt i jest nim zazwyczaj prototyp, lub już
 * z wykorzystaniem istniejacego obiektu, klonuje się, moim zdaniem
 * najbardziej orientujący sie wzór projektowy. */

int main()
{
	// pObiekt1 jest prototypem
    IPrototype * pObiekt1 = new CMyPrototype1( 123, "raz dwa trzy" );
    // W tym prototypie sa tworzone produkty
    IPrototype * pObiekt2 = pObiekt1->Klonuj();
    delete pObiekt1;
    pObiekt2->Wypisz();
    delete pObiekt2;
    return 0;
}
