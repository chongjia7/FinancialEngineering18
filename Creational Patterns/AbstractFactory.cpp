#include <iostream>
using namespace std;

namespace Abstract_Factory
{
	class Widget
	{
		virtual void draw() = 0; // pure virtual function 
	}; 

	class OSX_Button: public Widget 
	{
	public: 
		void draw()
		{
			std::cout << "\tOSX bottom" << std::endl;
		}
	}; 

	class Windows_Button: public Widget
	{
	public:
		{
			void draw() 
			{
				std::cout<< "\tWindows button" << std::endl; 
			}
		}
	};
};

int main()
{
	using namespace Creational_Patterns::Abstract_Factory; 

	Widget * W = new OSX_Button(); 
	w->draw(); 
	delete w;
	return 0;
}