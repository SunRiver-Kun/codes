#include <lua.hpp>
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

static int Print(lua_State* L)
{
	const int num = lua_gettop(L);
	//	cout << "传进来的L栈个数为:" << num << endl;
	if (num == 0) { return 0; }
	for (int i = 1; i <= num; ++i)
	{
		if (lua_isnumber(L, i))
			cout << lua_tonumber(L, i) << " ";
		else if (lua_isstring(L, i))
			cout << lua_tostring(L, i) << " ";
		else if (lua_isboolean(L, i))
			cout << std::boolalpha << bool(lua_toboolean(L, i)) << " ";
		else if (lua_isnil(L, i))
			cout << "nil ";
		else
		{
			cout << "this function is only for number/string/boolean/nil" << endl;
			lua_error(L);
		}
	}
	cout << endl;
	lua_pop(L, num);
	//cout << "处理后L栈个数为：" << lua_gettop(L) << endl;
	return 0;
}

static int nowtime(lua_State* L)
{
	time_t t = std::time(nullptr);
	const char* str = std::ctime(&t);
	lua_pushinteger(L, t);
	lua_pushstring(L, str);
	return 2;
}

int main()
{
	lua_State* L = lua_open();
	luaL_openlibs(L);  //加载Lua标准库
	//---------------注册我们的函数供Lua使用
	lua_register(L, "Print", Print);
	lua_register(L, "nowtime", nowtime);
	//----------------
	//运行Lua
	luaL_dofile(L, "./Task.lua");
	luaL_dostring(L, R"(
		print(str)
		ans = add(1,2)
	)");
	lua_getglobal(L, "ans");  //把Lua里的全局变量ans入栈
	cout << "ans = " << lua_tonumber(L, -1) << " 现在栈里有" << lua_gettop(L) << "个参数" << endl;
	lua_close(L);
	system("pause");
}