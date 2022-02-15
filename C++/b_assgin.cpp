#include<boost/assign.hpp> //��׼������ֵ��
int main()
{
	using namespace boost::assign;
	//����,c++11��{}�������� repeat,repeat_fun,range
	//list_of, ref_list_of, cref_list_of, map_list_of
	std::vector<int> v = list_of(-1)(-2)(-3).repeat(4, -4).repeat_fun(5, []() {return 5; });
	std::deque<std::string> d = (list_of("-one")("-two"), "-three", "-four"); //��()��list_of��,������
	std::map<int, std::string> m = map_list_of(-1, "-one")(-2, "-two"); //�ȼ��� list_of(std::make_pair(-1,"-one"))(std::make_pair(-2,"-two"))
	//��ֵ +=,  push_back, push_front, insert
	//ptr_push_back, ptr_push_front
	v += 1, 2, 3, 4, 5, 6 * 6; //���β���
	push_back(v)(7), 8, 9; //�����ǵ��� v.push_back

	d += "one", "two", "three", "four", "five";
	push_front(d)("zero");
	push_back(d)("six")("seven");

	m += std::make_pair(1, "one"), std::make_pair(2, "two");
	insert(m)(3, "three")(4, "four"); //map,setֻ��insert
}