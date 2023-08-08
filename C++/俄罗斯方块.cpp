#include <Windows.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

constexpr  short WinLeft = 0;
constexpr  short WinRight = 30;
constexpr  short WinButtom = 0;
constexpr  short WinTop = 25;
constexpr short WinHeight = WinTop - WinButtom - 1;
constexpr short WinWidth = WinRight - WinLeft + 1;
bool g_map[WinHeight][WinWidth];

template<size_t _Size>
class Object
{
public:
	Object(const bool(&shape)[_Size][_Size] = {}, short x = 0, short y = 0) noexcept :x(x), y(y)
	{
		copy((bool*)shape, (bool*)shape + _Size * _Size, (bool*)pos);
	}
	void rotate();
	void draw()const;
	short left()const;
	short right()const;
	short x, y;
private:
	bool pos[_Size][_Size];
};
typedef Object<4> Block;

void gotoxy(short x, short y);
void InitGame();

int main()
{
	//SetWindowText
	SetConsoleTitle(L"¶íÂÞË¹·½¿é");
	InitGame();
	system("pause");
}

void gotoxy(short x, short y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord{ x,y };
	SetConsoleCursorPosition(hOut, coord);
}

void InitGame()
{
	fill((bool*)g_map, (bool*)g_map + WinHeight * WinWidth, false);

	for (short i = 0; i < WinHeight; ++i)
	{
		gotoxy(WinLeft, i);
		cout << "";
		gotoxy(WinRight, i);
		cout << "|";
	}
	gotoxy(WinLeft, WinHeight);
	for (short i = 0; i < WinWidth; ++i)
	{
		cout << "^";
	}
}

template<size_t _Size>
void Object<_Size>::rotate()
{
	vector<pair<size_t, size_t>> target_pos;
	for (size_t i = 0; i < _Size; ++i)
	{
		for (size_t j = 0; j < _Size; ++j)
		{
			if (pos[i][j])
			{
				target_pos.push_back(make_pair(i, j));
				pos[i][j] = false;
			}
		}
	}
	for (auto& v : target_pos)
	{
		auto pair = make_pair(_Size - 1 - v.second, v.first);
		pos[pair.first][pair.second] = true;
	}
}

template<size_t _Size>
void Object<_Size>::draw() const
{}

template<size_t _Size>
short Object<_Size>::left() const
{
	short left = static_cast<short>(_Size - 1);
	for (size_t i = 0; i < _Size; ++i)
	{
		for (size_t j = 0; j < _Size; ++j)
		{
			if (pos[i][j])
			{
				if (j < left) { left = j; }
				break;
			}
		}
	}
	return left;
}

template<size_t _Size>
short Object<_Size>::right() const
{
	short right = 0;
	for (size_t i = 0; i < _Size; ++i)
	{
		for (size_t j = _Size - 1; j >= 0; --j)
		{
			if (pos[i][j])
			{
				if (right < j) { right = j; }
				break;
			}
		}
	}
	return right;
}