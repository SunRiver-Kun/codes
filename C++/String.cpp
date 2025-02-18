#include <string>
#include <cstdlib>
using namespace std;

template <typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string> operator+(const std::string &str, _Ty &&num)
{
	return str + std::to_string(num);
}
template <typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string> operator+(_Ty &&num, const std::string &str)
{
	return str + std::to_string(num);
}

template <typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string &> operator+=(std::string &str, _Ty &&num)
{
	str.append(std::to_string(num));
	return str;
}

int main()
{
	using namespace std;
	string str;
	str = 100 + str + (-200) + true;
	str += 10053.0;
	str += 1.5E3;
}

class String
{
public:
	String(const char *str = nullptr)
	{
		ctor_new(str);
	}

	String(const String &str)
	{
		ctor_new(str.data, str.length);
	}

	String(String &&str)
	{
		ctor_move(std::move(str));
	}

	~String()
	{
		delete[] data;
		length = 0;
	}

	String &operator=(const String &str)
	{
		if (this != &str)
		{
			ctor_new(str.data, str.length);
		}

		return *this;
	}

	String &operator=(String &&str)
	{
		if (this != &str)
		{
			delete[] data;
			ctor_move(std::move(str));
		}
		return *this;
	}

	String operator+(const String &str) const
	{
		int newLength = length + str.length;
		char* newData = new char[newLength + 1];
		strcpy(newData, data);
		strcpy(newData + length, str.data);

		String newStr;
		delete[] newStr.data;
		newStr.data = newData;
		newStr.length = newLength;

		return newStr;
	}

	String &operator+=(const String &str)
	{
		int newLength = length + str.length;
		char* newData = new char[newLength + 1];
		strcpy(newData, data);
		strcpy(newData + length, str.data);

		delete[] data;
		data = newData;
		length = newLength;

		return *this;
	}

	bool operator==(const String &str) const
	{
		return length==str.length && !strcmp(data, str.data);
	}

	char &operator[](int n) const { return data[n]; }

	size_t size() const { return length; }
	const char *c_str() const { return data; }

private:
	char *data;
	size_t length;

	void ctor_new(const char *str, int targetLength=-1)
	{
		if (str)
		{
			length = targetLength>0 ? targetLength :strlen(str);
			data = new char[length + 1];
			strcpy(data, str);
		}
		else
		{
			length = 0;
			data = new char[1]{'\0'};
		}
	}

	void ctor_move(String &&str)
	{
		_ASSERT(str.data);

		length = str.length;
		data = str.data;

		str.data = nullptr;
		str.length = 0;
	}
};