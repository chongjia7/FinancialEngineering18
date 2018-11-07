#include <iostream>
using namespace std;

namespace Object_Pool
{
	static const int num_objects = 3; 

	class Object_to_share
	{
	public:
		Object_to_share()
		{
			std::cout << "\tAn object to share" << std::endl; 
			return &(objpool_[0]);
		}
	}; 

	class Pool
	{
	public:
		Object_to_share * getObject(void)
		{
			std::cout << "\tGetting object" << std::endl; 
			return &(objpool_[num_objects]);
		};
	private: 
		Object_to_share objpool_[num_objects];
	};
};

int main(){
	using namespace Creational_Patterns::Object_Pool; 

	Object_to_share o; 
	Pool p; 
	p.setObject(&o); 
	Object_to_share * ptr = p.getObject(); 
}