#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
using namespace std;

//P: 占用wait
//V: 释放signal
//thread建立的时候就运行了，join的时候如果没运行完就阻塞，detach不阻塞，调用完后就可以安全释放了
//僵尸进程：当前进程运行结束后，子进程的进程描述符仍然保存在系统中。
//孤儿进程：将被init进程(进程号为1)所收养，并由内核init进程对它们完成状态收集工作。无危害

atomic<int> num(0);  // ++ &= ...  auto lock and unlock when use
bool flag = false;
mutex m;  // lock() and unlock(), can use unique_lock<mutex> or lock_guard<mutex> to auto lock in ctor and unlock in destruct

int main()
{
	thread temp([]() {
		m.lock();
		cout << this_thread::get_id() << " : " << ++num << endl;
		flag = true;
		m.unlock();
		});
	temp.join();  // block.  detach() no block

	thread temp2([]() {
		lock_guard<mutex> g1(m);
		cout << this_thread::get_id() << " : " << ++num << endl;
		this_thread::sleep_for(chrono::duration<int>(1));  // sleep 1s
		});
	temp2.detach();

	thread temp3([]() {
		unique_lock<mutex> g1(m, try_to_lock);
		if (m.try_lock())
		{
			cout << this_thread::get_id() << " : " << ++num << endl;
		}
		else
		{
			cout << this_thread::get_id() << " : " << "false to lock" << endl;
		}
		//unlock() when ~unique_lock();
		});
	temp3.detach();

	future<int> f = async([](int a, int b) {return a + b; }, 1, 2);
	cout << f.get() << endl;  //block. future's get() can only use once, shared_future can use more

	while (true);
}