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

#include "playerBullets.h"


defaultBullet::defaultBullet(){
	vector2D d;
	d.set(3.0,3.0);
	rect.setShape(-d,d);
}

void defaultBullet::setPosition(vector2D pos){
	rect.setPosition(pos);
}

void defaultBullet::draw(){

	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
}

void defaultBullet::move(){
	rect.position.y += 6.0;
	if(rect.position.y > 500)
		this->sayonara();
	rect.update();
}

shape* defaultBullet::getShape(){
	return &rect;
}

