#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

namespace threadsNS
{
	void Example01();
	void Example02();
	void Example03();
	void Example04();
	void Example05();
}

void ExecuteThreadsTestCode()
{
	//threadsNS::Example01();
	//threadsNS::Example02();
	//threadsNS::Example03();
	//threadsNS::Example04();
	threadsNS::Example05();

}

namespace threadsNS
{
	std::mutex mut;
	void test(bool bMutex)
	{
		if (bMutex)
			mut.lock();
		static int testInt = 1;
		testInt++;
		std::cout << testInt <<" " << std::endl;
		if (bMutex)
			mut.unlock();
	}

	void Example01()
	{
		/*
		* ��� ������ ����������� � ������ �������� �������
		* std::thread::join ���� ��������� ���������� ������
		* �������� tr1.join() - � ���� ������ ����� ���������� �� ���������
		* ������ ����� ����� �������� ��������
		*/

		std::vector<std::thread> vecThread;
		int threadCount = 100;
		for (int i = 0; i < threadCount; i++)
		{
			vecThread.emplace_back(test, false);
			vecThread.back().detach();
		}
		//if (false)
		for (int i = 0; i < threadCount; i++)
			vecThread[i].join();

	}

	void Example02()
	{
		/*
		value++ ����������� � 3 ��������
		1) �������� �������� value
		2) ������������ ���������� ��������
		3) �������� ����� ��������

		��������� ������� ����� ������������ �������� ���� � ���� �������� value
		��� ��� ������������� � ���� � ���� ����� � �������

		� ����� ���� ���
		value = 1000
		����� 1 �������� value = 1000
		����� 2 �������� value = 1000
		����� 2 ����������� ����� � �������� 1001
		����� 2 ����� � value = 1001
		����� 2 �������� value = 1001
		����� 2 ����������� ����� � �������� 1002
		����� 2 ����� � value = 1002
		����� 1 ����������� � �������� 1001
		����� 1 ����� � value = 1001

		����� ����� 3� ����������� value ����������� ������ �� 1
		
		*/
		int value = 0;
		int Count = 100000;
		bool bMutex = false;
		std::mutex mut;
		auto func = [&]
		{
			for (int i = 0; i < Count; i++)
			{
				if (bMutex)
					mut.lock();
				value++;
				if (bMutex)
					mut.unlock();
			}
		};

		std::thread t1(func);

		std::thread t2(func);

		std::cout << value << std::endl;

		t1.join();
		t2.join();

		std::cout << value << std::endl;
	}

	void Example03()
	{
		std::atomic<int> value = 0;
		//int value = 0;
		int Count = 100000;
		bool bFetch = false;
		auto func = [&]
		{
			for (int i = 0; i < Count; i++)
			{
				if (bFetch)
				{
					//value.fetch_add(1);
				}
				else
				{
					value++;
				}

			}
		};

		std::thread t1(func);

		std::thread t2(func);

		std::cout << value << std::endl;

		t1.join();
		t2.join();

		std::cout << value << std::endl;
	}

	void Example04()
	{
		/* ������, ��� ������ ����������� ���� �����*/

		bool bDeadLock = false;
		std::mutex m1;
		std::mutex m2;
		
		auto f1 = [&]
		{
			std::lock_guard<std::mutex> g1(m1);
			std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
			std::lock_guard<std::mutex> g2(m2);
		};

		auto f2 = [&]
		{
			std::lock_guard<std::mutex> g1(m2);
			std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
			std::lock_guard<std::mutex> g2(m1);
		};

		std::thread tr1(f1);
		
		std::unique_ptr<std::thread> tr2;
		if (bDeadLock)
			tr2.reset(new std::thread(f2));
		else
			tr2.reset(new std::thread(f1));


		tr1.join();
		tr2->join();
	}

	class background_task
	{
	public:
		/*static*/ int value;
		background_task()
		{
			value = 0;
			writeValue();
		}
		background_task(const background_task& task)
		{
			value = task.value + 10;
			writeValue();
		}
		//void operator=(const background_task& task)
		//{
		//	value = task.value + 2;
		//}

		void writeValue() const
		{
			std::cout << value << std::endl;
		}

		void operator()() const
		{
			writeValue();
		}

		
	};
	
	void Example05()
	{
		/*
		* � ������ � ���������, ���������� ��� ����������� ��� �������� ������
		*/
		background_task f;
		std::thread my_thread(f);
		my_thread.join();

	}
}