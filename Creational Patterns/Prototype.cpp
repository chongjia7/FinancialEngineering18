#include <iostream>
using namespace std;

namespace Protopye
{
	class Base 
	{
	public:
		virtual Base* clone() = 0; 
		virtual void doSomething() = 0; 
	};

	class Factory 
	{
	public: 
		static Base* makeBase(int choice); 
	private:
		static Base* s_prototypes[3]; 
	}; 

	class A : public Base 
	{
	public:
		Base* clone() {return new A;}
		void doSomething() {std::cout << "A is now doing\n"; }
	};

	class B : public Base 
	{
	public:
		Base* clone() {return new B;}
		void doSomething() {std::cout << "B is now doing\n"; }
	};

	Base* Factory::s_prototypes[] = { 0, new A, new B}; 
	Base* Factory::makeBase(int choice) { return s_prototypes[choice]-> clone();}
}; 

int main()
{
	using namespace Creational_Patterns::Protopye; 
	Base *b = Factory::makeBase(1); 
	b-> doSomething(); 
	delete b; 
}