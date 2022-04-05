#include <string>
#include <iostream>

using namespace std;
 
template <typename T> 
class Optional
{  
public: 
  Optional()  
  {  
	m_hasValue = false;
  }
   
  Optional(T const &v) 
  { 
	m_value = v;
	m_hasValue = true;
  }
   
  void set(T const& v)
  {
    m_value = v;
    m_hasValue = true;
  }
   
  void clear()
  {
    m_hasValue = false;
  }
   
  T const &get() const
  {
    if (!m_hasValue)
      std::cerr << "Fehler" << endl;

    return m_value;
  }
   
  bool hasValue() const
  {
    return m_hasValue;
  }
 
private:
  T m_value;
  bool m_hasValue;
};
 
int main()
{
  Optional<std::string> o;
   
  cout << "Wert von o:" << o.hasValue() << endl;
   
  o.set("Test");
   
  cout << "Wert von o:" << o.hasValue() << endl;
  cout << "o = " << o.get() << endl;
   
  o.clear();
  cout << "Wert von o:" << o.hasValue() << endl;
}