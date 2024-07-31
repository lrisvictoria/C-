#pragma once

#include <iostream>
#include <functional>

using namespace std;

namespace lx
{
	template <class T>
	class auto_ptr
	{
	public:
		//构造函数保存资源 - RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		auto_ptr(auto_ptr<T>& ap)//非常荒唐的一种做法，委员会不知道怎么想的
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//析构函数释放资源
		~auto_ptr()
		{
			delete _ptr;
		}

		//像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		
	private:
		T* _ptr;
	};

		template<class T>
		class unique_ptr
		{
		public:
			unique_ptr(T* ptr)
				:_ptr(ptr)
			{}
			~unique_ptr()
			{
				if (_ptr)
					delete _ptr;
			}
			T& operator *()
			{
				return *_ptr;
			}
			T* operator ->()
			{
				return _ptr;
			}

			unique_ptr(const unique_ptr<T>& ptr) = delete;
			unique_ptr<T>& operator = (unique_ptr<T>& ptr) = delete;

		private:
			T* _ptr;
		};

		template<class T>
		class shared_ptr
		{
		public:
			shared_ptr(T* ptr = nullptr)
				:_ptr(ptr)
				,_pcount(new int(1))
			{}

			template<class D>
			shared_ptr(T* ptr, D del)
				:_ptr(ptr)
				,_pcount(new int(1))
				,_del(del)
			{}

			~shared_ptr()
			{
				if (--(*_pcount) == 0)
				{
					//delete _ptr;
					_del(_ptr); 
					delete _pcount;
				}
			}

			T& operator *()
			{
				return *_ptr;
			}
			T* operator ->()
			{
				return _ptr;
			}

			// sp3(sp1)
			// sp3 和 sp1 指向同一块资源和引用计数
			shared_ptr(const shared_ptr<T>& sp)
				:_ptr(sp._ptr)
				, _pcount(sp._pcount)
			{
				++(*_pcount);
			 }

			shared_ptr<T>& operator=(const shared_ptr<T>& sp)
			{
				if (_ptr == sp._ptr) return *this;

				// 赋值前，先对引用计数进行 --, _pcount 为 0 时，需要把引用计数和资源都释放
				if (--(*_pcount) == 0)
				{
					delete _ptr;
					delete _pcount;
				}

				_ptr = sp._ptr;
				_ptr = sp._pcount;
				++(*_pcount);

				return *this;
			}

			// 获取引用计数
			int use_count() const
			{
				return *_pcount;
			}

			// 获取原生指针
			T* get() const
			{
				return _ptr;
			}

			T* _ptr;
			int* _pcount;

			function<void(T*)> _del = [](T* ptr) {delete ptr; };
		};


			template<class T>
			class weak_ptr
			{
			public:
				weak_ptr()
					:_ptr(nullptr)
				{}

				T& operator *()
				{
					return *_ptr;
				}
				T* operator ->()
				{
					return _ptr;
				}

				// 
				weak_ptr(shared_ptr<T>& sp)
					:_ptr(sp.get())
				{}

				weak_ptr<T>& operator=(const shared_ptr<T>& sp)
				{
					_ptr = sp.get();
					return *this;
				}

				
			private:
				T* _ptr;
			};


}
