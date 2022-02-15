#include<boost/assign.hpp> //标准容器赋值简化
int main()
{
	using namespace boost::assign;
	//构造,c++11的{}构造更舒服 repeat,repeat_fun,range
	//list_of, ref_list_of, cref_list_of, map_list_of
	std::vector<int> v = list_of(-1)(-2)(-3).repeat(4, -4).repeat_fun(5, []() {return 5; });
	std::deque<std::string> d = (list_of("-one")("-two"), "-three", "-four"); //用()把list_of和,包起来
	std::map<int, std::string> m = map_list_of(-1, "-one")(-2, "-two"); //等价于 list_of(std::make_pair(-1,"-one"))(std::make_pair(-2,"-two"))
	//赋值 +=,  push_back, push_front, insert
	//ptr_push_back, ptr_push_front
	v += 1, 2, 3, 4, 5, 6 * 6; //依次插入
	push_back(v)(7), 8, 9; //本质是调用 v.push_back

	d += "one", "two", "three", "four", "five";
	push_front(d)("zero");
	push_back(d)("six")("seven");

	m += std::make_pair(1, "one"), std::make_pair(2, "two");
	insert(m)(3, "three")(4, "four"); //map,set只能insert
}