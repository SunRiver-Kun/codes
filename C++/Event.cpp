#include<vector>
template<typename... _Types>
class Event
{
public:
	Event& operator+=(void(*fn)(_Types...))
	{
		fns.push_back(fn);
		return *this;
	}
	Event& operator-=(void(*fn)(_Types...))
	{
		for (auto it = fns.begin(); it != fns.end(); ++it)
		{
			if (*it == fn)
			{
				fns.erase(it);
				break;
			}
		}
		return *this;
	}
	void operator()(_Types... args)
	{
		for (auto& fn : fns)
		{
			fn(args...);
		}
	}
private:
	std::vector<void(*)(_Types...)> fns;
};
template<>
class Event<void>
{
public:
	Event& operator+=(void(*fn)())
	{
		fns.push_back(fn);
		return *this;
	}
	Event& operator-=(void(*fn)())
	{
		for (auto it = fns.end(); it != fns.begin(); --it)
		{
			if (*it == fn)
			{
				fns.erase(it);
				break;
			}
		}
		return *this;
	}
	void operator()()
	{
		for (auto& fn : fns)
		{
			fn();
		}
	}
private:
	std::vector<void(*)()> fns;
};