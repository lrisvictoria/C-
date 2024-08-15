//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//#include<mutex>
//#include<thread>
//#include<chrono>
//
//////#ifdef _WIN32
//////CreateThread()
//////#else
//////pthread_create()
//////#endif
//////
////void Print1(size_t n, const string& s, mutex& m, int& rx)
////{
////	for (size_t i = 0; i < n; i++)
////	{
////		m.lock();
////
////		cout <<this_thread::get_id()<<s<<":" << i << endl;
////		++rx;
////
////		m.unlock();
////
////		this_thread::sleep_for(chrono::milliseconds(300));
////	}
////}
////
////int main()
////{
////	mutex mtx;
////	int x = 0;
////	thread t1(Print1, 100,  "我是鹏哥", ref(mtx), ref(x));
////	thread t2(Print1, 200, "我是蛋哥", ref(mtx), ref(x));
////
////	//thread t3(t1);
////
////	cout <<"线程1：" << t1.get_id() << endl;
////	cout <<"线程2："<< t2.get_id() << endl;
////
////	t1.join();
////	t2.join();
////
////	cout << x << endl;
////
////	return 0;
////}
//
////void Print2(size_t n, const string& s)
////{
////	for (size_t i = 0; i < n; i++)
////	{
////		cout << this_thread::get_id() << s << ":" << i << endl;
////	}
////}
////
//
////void Print2(size_t n, const string& res)
////{
////	cout << this_thread::get_id() << res << ":" << endl;
////}
////
////int main()
////{
////	size_t n;
////	cin >> n;
////
////	//创建n个线程执行Print
////	vector<thread> vthd(n);
////	size_t j = 0;
////	for (auto& thd : vthd)
////	{
////		// 移动赋值
////		/*thread t1(Print2, 10, "线程" + to_string(j++));
////		thd = move(t1);*/
////		thd = thread(Print2, 10, "线程" + to_string(j++));
////	}
////
////	for (auto& thd : vthd)
////	{
////		thd.join();
////	}
////
////	/*thread t1(Print2, 100, 1, "我是鹏哥");
////	thread t2(move(t1));*/
////
////	//t2.join();
////
////	return 0;
////}
//
////int main()
////{
////	size_t n1 = 0;
////	size_t n2 = 0;
////	cin >> n1 >> n2;
////	mutex mtx;
////	
////
////	size_t x = 0;
////
////	thread t1([n1, &x, &mtx]() {
////		for (size_t i = 0; i < n1; i++)
////		{
////			mtx.lock();
////			++x;
////			mtx.unlock();
////			//cout << this_thread::get_id() << ":" << i << endl;
////		}
////	});
////
////	thread t2([n2, &x, &mtx]() {
////		for (size_t i = 0; i < n2; i++)
////		{
////			mtx.lock();
////			++x;
////			mtx.unlock();
////			//cout << this_thread::get_id() << ":" << i << endl;
////		}
////	});
////
////	t1.join();
////	t2.join();
////
////	cout << x << endl;
////
////	return 0;
////}
//
//using namespace std;
//
//void func()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw exception("异常");
//	}
//	else
//	{
//		cout << "func()" << endl;
//	}
//}
//
//int main()
//{
//	mutex mtx;
//	size_t n1 = 5;
//	size_t n2 = 5;
//	
//	size_t x = 0;
//
//	thread t1([n1, &x, &mtx]() {
//		try {
//			for (size_t i = 0; i < n1; i++)
//			{
//				mtx.lock();
//			
//				++x;
//				func();
//
//				mtx.unlock();
//			}
//		}
//		catch (const exception& e)
//		{
//			cout << e.what() << endl;
//		}
//	});
//	
//	thread t2([n2, &x, &mtx]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			mtx.lock();
//			++x;
//			mtx.unlock();
//		}
//	});
//
//	t1.join();
//	cout << "t1 wait success" << endl;
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}
