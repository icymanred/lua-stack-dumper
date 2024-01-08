// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
extern "C" {
#include "Lua5/include/lua.h"
#include "Lua5/include/lauxlib.h"
#include "Lua5/include/lualib.h"
#include "Lua5/include/lauxlib.h"

}


#pragma comment(lib,"Lua5/Lua54.lib")
static void DumpStack(lua_State* L) {
	int top = lua_gettop(L);
	for (int i = 1; i <= top; i++) {
		int t = lua_type(L, i);
		std::cout << "Starting test\n";
		switch (t) {

		case(LUA_TNONE):
			std::cout << "None\n";
			break;
		case(LUA_TNIL):
			std::cout << "Nil\n";
			break;
		case(LUA_TBOOLEAN):
			std::cout << "Boolean: " << lua_toboolean(L, i) ? "True" : "False" << " \n";
			break;
		case(LUA_TLIGHTUSERDATA):
			std::cout << "Light userdata:" << lua_touserdata(L, i) << "\n";
			break;
		case(LUA_TNUMBER):
			std::cout << "Number: " << lua_tonumber(L, i) << "\n";
			break;
		case(LUA_TSTRING):
			std::cout << "String: " << lua_tostring(L, i) << "\n";
			break;
		case(LUA_TTABLE):
			std::cout << "Table: 0x" << lua_topointer(L, i) << "\n";
			break;
		case(LUA_TFUNCTION):
			std::cout << "Function: 0x" << lua_topointer(L, i) << "\n";
			break;
		case(LUA_TUSERDATA):
			std::cout << "Userdata: 0x " << lua_touserdata(L, i) << "\n";
			break;

		}

	}
}

const char* str =  "Hewo baby";
int main(int argc) {
	
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_pushnil(L);
	lua_pushboolean(L, 1);
	lua_pushlightuserdata(L, &str);
	lua_pushnumber(L, 20);
	lua_pushstring(L, "Hewoo");
	lua_newtable(L);
	luaL_loadstring(L, "print(\"hi\")");
	size_t size = 3;
	lua_newuserdatauv(L, size, 3);
	DumpStack(L);

	



	return 0;

	
 
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
