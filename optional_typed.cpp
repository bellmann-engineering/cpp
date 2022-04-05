#include <string>
#include <iostream>

using namespace std;
 
class Optional
{  
public: 
  Optional()  
  {  
	m_hasValue = false;
  }
   
  Optional(int v) 
  { 
	m_value = v;
	m_hasValue = true;
  }
   
  void set(int v)
  {
    m_value = v;
    m_hasValue = true;
  }
   
  void clear()
  {
    m_hasValue = false;
  }
   
  int get()
  {
    if (!m_hasValue)
      std::cerr << "Fehler" << endl;

    return m_value;
  }
   
  bool hasValue()
  {
    return m_hasValue;
  }
 
private:
  int m_value;
  bool m_hasValue;
};
 
int main()
{
  Optional o;
   
  cout << "Wert von o:" << o.hasValue() << endl;
   
  o.set(100);
   
  cout << "Wert von o:" << o.hasValue() << endl;
  cout << "o = " << o.get() << endl;
   
  o.clear();
  cout << "Wert von o:" << o.hasValue() << endl;
}