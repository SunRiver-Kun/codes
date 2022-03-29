//假定 helper.dll
// require("helper")  --preload->lua->cpath("./?.dll;./?.so")->loader   舍弃 - 前面的, . 变_
#include <lua.hpp>

//不一定要static
int Print(lua_State* L)
{
	lua_pushstring(L, "hello world!");
	return 1;
}

//导出的函数
static luaL_Reg exfns[] = {
	{"Print",Print},
	{NULL , NULL}  //要有这个作为结束符
};

//导出入口  luaopen_xxx   xxx为文件名
extern "C"  __declspec(dllexport) int luaopen_helper(lua_State * L)
{
	luaL_dostring(L, R"(print("hello world"))");
	luaL_register(L, "Helper", exfns);  //在lua里  Helper（表）.Print 来调用Print
	return 0;
}