#include<string>
template<typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string> operator+(const std::string& str, _Ty&& num)
{
	return str + std::to_string(num);
}
template<typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string> operator+(_Ty&& num, const std::string& str)
{
	return str + std::to_string(num);
}

template<typename _Ty>
typename std::enable_if_t<std::is_integral_v<_Ty> || std::is_floating_point_v<_Ty>, std::string&> operator+=(std::string& str, _Ty&& num)
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