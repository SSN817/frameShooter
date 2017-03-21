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

#include "gameUsetInterfaces.h"



arrowSelectableItem::arrowSelectableItem(){
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;
	selectFlag = false;
}

arrowSelectableItem::~arrowSelectableItem(){
}
void arrowSelectableItem::setNextItem(arrowSelectableItem* U,arrowSelectableItem* D,arrowSelectableItem* L,arrowSelectableItem* R){
	up = U;
	down = D;
	left = L;
	right = R;
}
void arrowSelectableItem::selectNextItem(){
	if(isKeyHitted("up") && up!= NULL){
		up->selectThis();
		selectFlag = false;
	}
	if(isKeyHitted("down") && down!= NULL){
		down->selectThis();
		selectFlag = false;
	}
	if(isKeyHitted("right") && right!= NULL){
		right->selectThis();
		selectFlag = false;
	}
	if(isKeyHitted("left") && left!= NULL){
		left->selectThis();
		selectFlag = false;
	}
}

void arrowSelectableItem::selectThis(){
	selectFlag = true;
}

bool arrowSelectableItem::isSelected(){
	return selectFlag;
}



void rectangleButton::setInfo(vector2D v1,vector2D v2){
	rect.setShape(v1,v2);
	rect.setPosition(0.0,0.0);
}

void rectangleButton::setName(string buttonName){
	name = buttonName;
}

void rectangleButton::draw(){
	vector2D d;
	d.set(2.0,2.0);
	if(isSelected())
		drawVRect(rect.p[0] - d,rect.p[2] + d,GetColor(255,255,255),0);
	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
}

void rectangleButton::checkInput(){
	hit = false;
	if(isMouseHitted("left"))
		if(rect.isPointIn(nowMouse()))
			hit = true;
	if(isSelected())
		if(isKeyHitted("return"))
			hit = true;
	selectNextItem();
}

bool rectangleButton::isHitted(){
	return hit;
}





verticalSlider::verticalSlider(){
	linkFlag = false;
	rect.setPosition(0.0,0.0);
	rect.setShape(-10.0,10.0,10.0,-10.0);
}

void verticalSlider::setInfo(vector2D pos,double len){
	position = pos;
	length = len;
	rect.setPosition(pos.x,pos.y);
}

void verticalSlider::draw(){

	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
	vector2D d;
	d.set(0.0,length);
	drawVLine(position,position + d,GetColor(255,255,255),1.0);
}

void verticalSlider::move(){

	if(linkFlag)
		rect.setPosition(position.x,rtovy(nowMouseY())-link.y);
	if(rect.position.y>position.y+length)
		rect.position.y = position.y+length;
	if(rect.position.y<position.y)
		rect.position.y = position.y;
	rect.setPosition(rect.position.x,rect.position.y);

}

void verticalSlider::checkInput(){
	if(rect.isPointIn(nowMouse()))
		if(isMouseHitted("left")){
			linkFlag = true;
			link = rtov2D(nowMouse()) - rect.position;
		}
	if(!isMousePressed("left"))
		linkFlag = false;
}

double verticalSlider::valueHighTop(){
	return (rect.position.y - (position.y - length))/length;
}

double verticalSlider::valueLowTop(){
	return (position.y - rect.position.y)/length;
}




horizontalSlider::horizontalSlider(){
	linkFlag = false;
	rect.setPosition(0.0,0.0);
	rect.setShape(-10.0,10.0,10.0,-10.0);
}

void horizontalSlider::setInfo(vector2D pos,double len){
	position = pos;
	length = len;
	rect.setPosition(pos.x,pos.y);
}

void horizontalSlider::draw(){
	vector2D d;
	d.set(length,0.0);
	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
	drawVLine(position,position + d,GetColor(255,255,255),1);
}

void horizontalSlider::move(){
	if(linkFlag)
		rect.setPosition(rtovx(nowMouseX())-link.x,position.y);
	
	if(rect.position.x>position.x+length)
		rect.position.x = position.x+length;
	if(rect.position.x<position.x)
		rect.position.x = position.x;
	
	rect.setPosition(rect.position.x,rect.position.y);

}

void horizontalSlider::checkInput(){
	if(rect.isPointIn(rtovx(nowMouseX()),rtovy(nowMouseY())))
		if(isMouseHitted("left")){
			linkFlag = true;
			link = rtov2D(nowMouse()) - rect.position;
		}
	if(!isMousePressed("left"))
		linkFlag = false;
}

double horizontalSlider::valueRightTop(){
	return (length - (rect.position.x - position.x))/length;

}

double horizontalSlider::valueLeftTop(){
	return (rect.position.x - position.x)/length;
}
