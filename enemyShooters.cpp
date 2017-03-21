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

#include "effects.h"
#include "enemyBullets.h"
#include "enemyShooters.h"


basicEnemy::basicEnemy(subjectSet* subset) : reproductionObserver(subset)
{
	position.set(200.0,400.0);
	rect.setPosition(position);
	rect.setShape(-20.0,-20.0,20.0,20.0);
	verocity.set(2.0,0.0);

	vector<vector<string>> buf;
	rectangle rect;
	vector2D v1,v2;
	loadFile("test_frame.txt",',',&buf);
	

	for(int i=0;i<stoi(buf[3][1]);i++){
		v1.set(stod(buf[4+stoi(buf[0][1])+stoi(buf[1][1])+stoi(buf[2][1])+i][0]),
			   stod(buf[4+stoi(buf[0][1])+stoi(buf[1][1])+stoi(buf[2][1])+i][1]));
		v2.set(stod(buf[4+stoi(buf[0][1])+stoi(buf[1][1])+stoi(buf[2][1])+i][2]),
			   stod(buf[4+stoi(buf[0][1])+stoi(buf[1][1])+stoi(buf[2][1])+i][3]));
		rect.setShape(v1,v2);
		frames.push_back(new frame);
		frames.at(frames.size() - 1)->setInfo(rect,40.0);
	}

	for(int i = 0;i<frames.size();i++)
		subject_set->setObserver(frames.at(i));
}

basicEnemy::~basicEnemy()
{
}

void basicEnemy::move(){
	position = verocity + position;
	rect.setPosition(position);
	
	
	if(position.x > 960.0)
		verocity.set(-2.0,0.0);

	if(position.x < 40.0)
		verocity.set(2.0,0.0);
	

	for(int i = 0;i<frames.size();i++)
		frames.at(i)->setPosition(position);
}

void basicEnemy::draw(){
	drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0);
}

void basicEnemy::reproduction(){
	if(rand()%10 == 0){
		basicEnemyBullet* bullet = new basicEnemyBullet;
		bullet->setPosition(position);
		subject_set->setObserver(bullet);
	}

}

void basicEnemy::collideWith(playerBulletObserver* obs){
	for(int i = 0;i<frames.size();i++)
		frames.at(i)->explose(position,100.0);
}


shape* basicEnemy::getShape(){
	return &rect;
}

