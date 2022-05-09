//◦
#include <string>

class testDel
{
public:
	std::string m_str;
	testDel()
	{
		std::cout << " testDel" << " : " << m_str << std::endl;
	}
	testDel(std::string test)
	{
		
		m_str = test;
		std::cout << " testDel" << " : " << m_str << std::endl;
	}
	~testDel()
	{
		std::cout << "~testDel" << " : " << m_str << std::endl;
	}
};