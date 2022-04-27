//◦
#pragma once
#include <functional>
namespace lambdaNS
{
	class testFunc
	{

	public:
		std::function<void()> _func;
		void SetFunc(std::function<void()>);
		void Execute();
		void ExecuteFunc(std::function<int(int a, int b)> F);
	};
}
