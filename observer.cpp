#include <Windows.h>
#include "vector2D.h"
#include "shape.h"
#include "observer.h"


observer::observer(void)
{
	alive_flag = true;
}


observer::~observer(void)
{
}

bool observer::isAlive(){
	return  alive_flag;
}

void observer::sayonara(){
	alive_flag = false;
}


