// ��Ҫʵ����ص�tuple_size��tuple_element��get<N>������
#include <iostream>
#include <tuple>
using namespace std;

class Entry {
public:
	void Init() {
		name_ = "name";
		age_ = 10;
	}

	std::string GetName() const { return name_; }
	int GetAge() const { return age_; }
private:
	std::string name_;
	int age_;
};

template <size_t I>
auto get(const Entry& e) {
	if constexpr (I == 0) return e.GetName();
	else if constexpr (I == 1) return e.GetAge();
}

namespace std {
	template<> struct tuple_size<Entry> : integral_constant<size_t, 2> {};
	template<> struct tuple_element<0, Entry> { using type = std::string; };
	template<> struct tuple_element<1, Entry> { using type = int; };
}

//û�й���������Ҳ����
struct Entry2
{
	void Show()
	{
		cout << name << " " << age << endl;
	}
	string name;
	int age = 100;
};

int main() {
	Entry e;
	e.Init();
	auto [name, age] = e;
	cout << name << " " << age << endl; // name 10

	Entry2 e2{ "Tom" };
	auto& [name2, age2] = e2;
	cout << name2 << " " << age2 << endl;

	system("pause");
	return 0;
}