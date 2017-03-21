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



#include"playerBullets.h"

#include"playerShooters.h"


defaultShooter::defaultShooter(subjectSet* subset) : reproductionObserver(subset){
	vector2D d;
	d.set(20.0,20.0);
	rect.setShape(position - d,position + d);
	collide_flag = false;
}

defaultShooter::~defaultShooter()
{
}

void defaultShooter::reproduction(){
	if(isKeyHitted("a")){
		defaultBullet* bullet = new defaultBullet;
		bullet->setPosition(position);
		subject_set->setObserver(bullet);
	}
}

void defaultShooter::move(){
	if(isKeyPressed("left"))
		position.x -= 3.0;
	if(isKeyPressed("right"))
		position.x += 3.0;
	if(isKeyPressed("up"))
		position.y += 3.0;
	if(isKeyPressed("down"))
		position.y -= 3.0;

	rect.setPosition(position);
}

void defaultShooter::draw(){
	if(collide_flag)
		drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
	else
		drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),1);
}

void defaultShooter::collideWith(enemyShooterObserver* obs){
	collide_flag = true;
}



shape* defaultShooter::getShape(){
	return &rect;
}