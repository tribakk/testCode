//◦
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <condition_variable>
#include <future>
#include "ThreadQueue.h"

namespace threadsNS
{
	void Example01();
	void Example02();
	void Example03();
	void Example04();
	void Example05();
	void Example06();
	void Example07();
	void Example08();
	void ExampleQueue();
}

void ExecuteThreadsTestCode()
{
	//threadsNS::Example01();
	//threadsNS::Example02();
	//threadsNS::Example03();
	//threadsNS::Example04();
	//threadsNS::Example05();
	//threadsNS::Example06();
	//threadsNS::Example07();
	//threadsNS::ExampleQueue();
	threadsNS::Example08();

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
		* код потока выполняется в момент создания объекта
		* std::thread::join ждет окончания выполнения потока
		* например tr1.join() - с этой строки уйдет управление на следующую
		* только когда поток закончит работать
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
		value++ выполняется в 3 операции
		1) получить значение value
		2) инкрементить полученное значение
		3) записать новое значение

		несколько потоков могут одновременно получить одно и тоже значение value
		оба его заинкриментят в одно и тоже число и запишут

		а может быть так
		value = 1000
		поток 1 получает value = 1000
		поток 2 получает value = 1000
		поток 2 инкрементит число и получает 1001
		поток 2 пишет в value = 1001
		поток 2 получает value = 1001
		поток 2 инкрементит число и получает 1002
		поток 2 пишет в value = 1002
		поток 1 инкрементит и получает 1001
		поток 1 пишет в value = 1001

		итого после 3х инкрементов value увеличилось только на 1
		
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
		/* дедлок, оба потока блокировали друг друга*/

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
		* в случае с функтором, происходит его копирование при создании потока
		*/
		background_task f;
		std::thread my_thread(f);
		my_thread.join();

	}

	void Example06()
	{
		std::mutex m1;
		//m1.lock();
		std::timed_mutex mutex;
		using sec = std::chrono::seconds;
		auto f1 = [&]()
		{
			mutex.lock();
			std::this_thread::sleep_for(sec(10));
			mutex.unlock();
			//m1.unlock();
		};

		auto f2 = [&]()
		{
			//m1.lock();
			for (int i = 0; i < 5; i++)
			if (mutex.try_lock_for(sec(4)))
			{
				std::cout << "try" << std::endl;
				mutex.unlock();
			}
			else
			{
				std::cout << "no try" << std::endl;
			}
		};
		
		std::thread t1(f1);
		std::thread t2(f2);

		t1.join();
		t2.join();

	}



	std::mutex m;
	std::condition_variable cv;
	std::string data;
	bool ready = false;
	bool processed = false;

	void worker_thread()
	{
		// Wait until main() sends data
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, []
			{
				return ready;
			});

		// after the wait, we own the lock.
		std::cout << "Worker thread is processing data\n";
		data += " after processing";

		// Send data back to main()
		processed = true;
		std::cout << "Worker thread signals data processing completed\n";

		// Manual unlocking is done before notifying, to avoid waking up
		// the waiting thread only to block again (see notify_one for details)
		lk.unlock();
		cv.notify_one();
	}

	void Example07()
	{
		std::thread worker(worker_thread);

		data = "Example data";
		// send data to the worker thread
		{
			std::lock_guard<std::mutex> lk(m);
			ready = true;
			std::cout << "main() signals data ready for processing\n";
		}
		cv.notify_one();

		// wait for the worker
		{
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, []
				{
					return processed;
				});
		}
		std::cout << "Back in main(), data = " << data << '\n';

		worker.join();
	}


	
	void printAlone(std::string text)
	{
		static std::mutex printLock;
		std::lock_guard<std::mutex> l(printLock);
		std::cout << text << std::endl;

	}

	void printAlone(std::string text, int value)
	{
		static std::mutex printLock;
		std::lock_guard<std::mutex> l(printLock);
		std::cout << text << " : "<< value << std::endl;

	}

	void prom_sum(int a, int b, int counter, std::promise<int> prom)
	{
		int result = a + b;
		printAlone("create", counter);
		//std::cout << "start wait sum" << std::endl;
		//std::cout << "end wait sum" << std::endl;
		prom.set_value(result);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		printAlone("1111 was set_value", counter);
	}

	void Example08()
	{
		
		for (int i = 0; i < 10; i++)
		{
			std::promise<int> prom;
			std::future<int> fut = prom.get_future();
		
			std::thread th(prom_sum, 10, 20, i, std::move(prom));
			//std::cout << "start wait get" << std::endl;
			int result = fut.get();
		
			//return;
			printAlone("2222 end wait get");
			//std::cout << "result = " << result << std::endl;
			printAlone("");
			th.detach();


		}
		std::this_thread::sleep_for(std::chrono::seconds(5));

	}


	void ExampleQueue()
	{

	}
}