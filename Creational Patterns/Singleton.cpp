#include <iostream>
using namespace std;

namespace Singleton
{
	class Single
	{
	public:
		static Single * getInstance(void)
		{
			if(!instance_)
			{ 
				instance_ = new Single(); 

			}
			return instance_; 
		}; 

	private: 
		Single() { std::cout << "\tSingle" <<std::endl;};
		static Single* instance_; 
	}; 

	Single *Single::instance_; 

}

int main()
{
	using namespace Creational_Patterns::Singleton; 

	Single * s = Single::getInstance(); 
	delete s; 
}

// in multithreaded-environment mandatory lock() before 
//accesing singleton instance for not incurring in risks of conflicts across threads

Singleton* Singleton::instance()
{
	Lock lock; 
	if (pInstance == 0) { pInstance = new Singleton;}
	return pInstance; 
}

Singleton* Singleton::instance()
{
	if (pInstance ==0)
	{
		Lock lock; 
		if (pInstance == 0)
		{
			pInstance = new Singletonl 
		}
	}

	return pInstance; 
}