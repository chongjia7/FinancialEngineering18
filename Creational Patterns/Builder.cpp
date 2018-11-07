#include <iostream>
using namespace std;

namespace Builder 
{
	class Build 
	{
	public:
		virtual void configure() = 0; 

	protected:
		int configuration_1_; 
		int configuration_2_; 
		int configuration_3_; 
		int configuration_4_; 
		//..
		int configuration_n_; 
	};

	class SimpleBuilder: public Build
	{
	public:
		SimpleBuilder()
		{
			std::cout << "/tSimple Builder" << std::endl;
		};

		void configure() {}; 
	};

	class AdvancedBuilder(): public Build
	{
	public:
		AdvancedBuilder()
		{
			std::cout << "\tAdvanced Builder" << std::endl; 
		};

		void configure() {}; 
		
	};

	class ClientClass
	{
	public: 
		ClientClass(Build * builder): builder_(builder){}; 

	private:
		Build * builder_; 
	}; 

}; 


int main(){
	using namespace Creational_Patterns::Builder; 
	Build * builder = new AdvancedBuilder();
	Client c(builder); 
	delete builder; 
}