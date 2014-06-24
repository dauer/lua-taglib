#include "lua.hpp"

#include <fileref.h>
#include <tag.h>

TagLib::FileRef f;

static int file(lua_State* L)
{
    const char *in = luaL_checkstring(L, 1);
    bool success = false;
    f = TagLib::FileRef(in);
    if(!f.isNull()) {
        success = true;
    }
    lua_pushboolean(L, success);
    return 1;
}

static int tag(lua_State *L)
{
    lua_newtable(L);
    if(!f.isNull() && f.tag()) {
        // ARTIST
        lua_pushstring(L, "artist");
        lua_pushstring(L, f.tag()->artist().toCString());
        lua_rawset(L, -3);
        // ALBUM
        lua_pushstring(L, "album");
        lua_pushstring(L, f.tag()->album().toCString());
        lua_rawset(L, -3);
        // TITLE
        lua_pushstring(L, "title");
        lua_pushstring(L, f.tag()->title().toCString());
        lua_rawset(L, -3);
        // GENRE
        lua_pushstring(L, "genre");
        lua_pushstring(L, f.tag()->genre().toCString());
        lua_rawset(L, -3);
        // TRACKNUMBER
        lua_pushstring(L, "track");
        lua_pushinteger(L, f.tag()->track());
        lua_rawset(L, -3);
        // DATE
        lua_pushstring(L, "year");
        lua_pushinteger(L, f.tag()->year());
        lua_rawset(L, -3);
        // COMMENT
        lua_pushstring(L, "comment");
        lua_pushstring(L, f.tag()->comment().toCString(true));
        lua_rawset(L, -3);
    }
    return 1;
}

static int length(lua_State *L)
{
    lua_pushinteger(L, f.audioProperties()->length());
    return 1;
}

static int bitrate(lua_State *L)
{
    lua_pushinteger(L, f.audioProperties()->bitrate());
    return 1;
}
static int sampleRate(lua_State *L)
{
    lua_pushinteger(L, f.audioProperties()->sampleRate());
    return 1;
}

static int channels(lua_State *L)
{
    lua_pushinteger(L, f.audioProperties()->channels());
    return 1;
}

static const luaL_Reg API[] = {
    {"file", file },
    { "tag", tag },
    { "length", length },
    { "bitrate", bitrate },
    { "sampleRate", sampleRate },
    { "channels", channels },
    { NULL, NULL },
};

LUALIB_API "C" int luaopen_taglib(lua_State* L)
{
    lua_newtable(L);
#if LUA_VERSION_NUM < 502
    luaL_register(L, NULL , API);
#else 
    luaL_setfuncs(L, API, 0);
#endif
    return 1;
}
