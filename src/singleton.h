#pragma once
#include <memory>
#include <mutex>

template<class T>
class Singleton
{
public:
	static std::shared_ptr<T> Instance()
	{
		std::call_once(s_flag, []() {
			instance_ptr_.reset(new T);
		});
		return instance_ptr_;
	}

	Singleton()
	{

	}

	~Singleton()
	{

	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	static std::once_flag s_flag;
	static std::shared_ptr<T> instance_ptr_;
};
template<class T>
std::once_flag Singleton<T>::s_flag;
template <class T>
std::shared_ptr<T> Singleton<T>::instance_ptr_;
