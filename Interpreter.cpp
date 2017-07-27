
 #include <string>  
 #include <iostream>  
 #include <stdexcept>  
  
 using namespace std;  
   
 class CInterpreter  
 {  
     public:  
        template<typename It>  
        void m_run(It from, It to)  
        {  
            for(It i=from; i!=to; ++i)  
            {  
                switch(*i)  
                {  
                    case 'h':  
                        cout << "Hello";    
                        break;  
                    case ' ':   
                        cout << ' ';     
                        break;  
                    case 'w':   
                        cout << "world";    
                        break;  
                    case '!':   
                        cout << '!';     
                        break;  
                    case 'n':   
                        cout << endl;   
                        break;  
                    default:    
                    throw runtime_error("Unknown command");  
                }  
            }  
        }  
 };  
  
 void helloworld(const string & script)  
 {  
	CInterpreter().m_run(script.begin(), script.end());  
 }  
  
 int main()  
 {  
	 helloworld("h w!n");  
	 return 0;  
 }  
