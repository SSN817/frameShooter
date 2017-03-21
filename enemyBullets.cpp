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

#include "enemyBullets.h"


basicEnemyBullet::basicEnemyBullet()
{
	vector2D d;
	d.set(5.0,5.0);
	rect.setShape(position - d ,position + d );
}

basicEnemyBullet::~basicEnemyBullet()
{
}

void basicEnemyBullet::setPosition(vector2D pos){
	position = pos;
	rect.setPosition(pos);
}

void basicEnemyBullet::draw(){
	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
}

void basicEnemyBullet::move(){
	position.y-=10.0;
	rect.setPosition(position);
	if(position.y <20.0)
		this->sayonara();
}

void basicEnemyBullet::collideWith(playerShooterObserver* obs){
	this->sayonara();
}


shape* basicEnemyBullet::getShape(){
	return &rect;
}