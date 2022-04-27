//◦
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <condition_variable>

namespace otherNS
{
	void Example01();
}

void ExecuteOtherTestCode()
{
	otherNS::Example01();

}

namespace otherNS
{
	void Example01()
	{
		

	}


}