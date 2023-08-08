#include <vector>
#include <algorithm>
#include <list>
//template<typename _Ty>
struct Rect//
{
	using _Ty = double;
	std::pair<_Ty, _Ty> lb, tr;	//x,y
};

template<typename T>
inline bool IsInline(T a1, T a2, T b)
{
	return a1 <= b && b <= a2;
}

template<typename T>
bool IsCross(T a1, T a2, T b1, T b2)
{	//a1<a2		b1<b2
	return IsInline(a1, a2, b1) || IsInline(a1, a2, b2) || IsInline(b1, b2, a1) || IsInline(b1, b2, a2);
}

std::vector< std::pair<Rect, Rect> >  GetCollisions(std::vector<Rect> rects)
{
	using namespace std;
	sort(rects.begin(), rects.end(), [](const Rect& a, const Rect& b) {return a.lb.first < b.lb.first; });	//¸ù¾Ýx½µÐòÅÅÁÐ
	vector< std::pair<Rect, Rect> > collisions;
	for (int i = 0; i < rects.size() - 1; ++i)
	{
		int j = i + 1;
		while (j < rects.size() && rects[i].tr.first >= rects[j].lb.first) { ++j; }
		if (j == rects.size()) { continue; }
		for (int k = i + 1; k < j; ++k)
		{
			if (IsCross(rects[i].lb.second, rects[i].tr.second, rects[k].lb.second, rects[k].tr.second))
			{
				collisions.push_back(make_pair(rects[i], rects[k]));
			}
		}
	}

	return collisions;
}

int main()
{
	using namespace std;
	vector<Rect> rects;
	rects.push_back(Rect{ {1,1},{3,4} });
	rects.push_back(Rect{ {3,3},{3,4} });
	rects.push_back(Rect{ {2,2},{3,4} });
	rects.push_back(Rect{ {1,4},{3,4} });
	GetCollisions(rects);
	system("pause");
}