#include <vector>
#include <string>
#include <map>
using namespace std;

#include "DxLib.h"
#include "vector2D.h"
#include "gameio.h"
using namespace gio;
#include "shape.h"

#include "observer.h"
#include "subject.h"

#include "curtains.h"

defaultCurtain::defaultCurtain(void)
{
	beginCloseFlag = false;
	isClosedFlag = false;
	isOpenedFlag = false;
	count = 0;
	curtainPosition = 0;

	rectangle rect;
	vector2D a,b;
	pair<rectangle,float> buf;

	for(int i = 0; i < 300 ; i++){
		a.set(3*i,rand()%700 -100);
		rect.setPosition(a);
		b.set(rand()%100+30,rand()%100+30);
		rect.setShape(a-b,a+b);
		buf.first = rect;
		buf.second = 1.0;
		salts.push_back(buf);
	}

}


defaultCurtain::~defaultCurtain(void)
{
}

void defaultCurtain::draw(){
	/*
	if(beginCloseFlag)
		count++;
	
	curtainPosition = count;
	if(curtainPosition > 2){
		curtainPosition = 2;
		isClosedFlag = true;
	}
	if(count >2)
		curtainPosition = 3 - count;
	if(curtainPosition <0){
		curtainPosition = 0;
		isOpenedFlag = true;
	}

	DrawBox(100,100,100+100,100+20,GetColor(255,255,255),0);
	DrawBox(100,100,100+curtainPosition*50,100+20,GetColor(255,255,255),1);
	*/

	if(!isClosedFlag)
		count+=7;
	else
		count-=7;

	if(count > 250){
		count = 250;
		isClosedFlag = true;

	}

	if(count<0){
		count = 0;
		isOpenedFlag = true;
	}
	

		for(int i = 0; i<salts.size();i++)
			if(i<count)
				drawVRect(salts.at(i).first.p[0],salts.at(i).first.p[2],GetColor(100,100,100),0,max(count-i,0.0));
}

void defaultCurtain::beginClose(){
	beginCloseFlag = true;
}

bool defaultCurtain::isOpened(){
	return isOpenedFlag;
}

bool defaultCurtain::isClosed(){
	return isClosedFlag;
}

