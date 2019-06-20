#include "pch.h"
#include "PhoenixFeather.h"


PhoenixFeather::PhoenixFeather():PhoenixFeather(0,0)
{
}

PhoenixFeather::PhoenixFeather(int x, int y): Stock(100, phoenixFeatherImageString, x, y)
{
}


PhoenixFeather::~PhoenixFeather()
{
}
