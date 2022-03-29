//�ٶ� helper.dll
// require("helper")  --preload->lua->cpath("./?.dll;./?.so")->loader   ���� - ǰ���, . ��_
#include <lua.hpp>

//��һ��Ҫstatic
int Print(lua_State* L)
{
	lua_pushstring(L, "hello world!");
	return 1;
}

//�����ĺ���
static luaL_Reg exfns[] = {
	{"Print",Print},
	{NULL , NULL}  //Ҫ�������Ϊ������
};

//�������  luaopen_xxx   xxxΪ�ļ���
extern "C"  __declspec(dllexport) int luaopen_helper(lua_State * L)
{
	luaL_dostring(L, R"(print("hello world"))");
	luaL_register(L, "Helper", exfns);  //��lua��  Helper����.Print ������Print
	return 0;
}