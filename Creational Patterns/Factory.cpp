#include <iostream>
using namespace std;

namespace Factory_Method 
{
	class Base 
	{
	public:
		virtual void what_to_do() = 0; 
	}; 

	class A: public Base
	{
	public:
		A() {std::cout << "\tClass A" << std::endl;}
		void what_to_do() {}; 
	}; 

	class B: public Base
	{
	public:
		B() {std::cout << "\tClassA" << std::endl;}
		void what_to_do{}; 
	}; 

}; 

int main()
{
	using namespace Creational_Patterns::Factory_Method; 

	Base *b = new A(); 
	b-> what_to_do(); 
	delete b; 
	b = new B(); 
	b-> what_to_do(); 
	delete b; 
	return 0; 
}
