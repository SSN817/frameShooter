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


frame::frame(){
	power_to_velocity = 180.0;
	power_to_vertex = 3.0;
	power_to_rot_velocity = 2.7;

	rot_velocity = 0.0;
	weight = 0.0;
	explose_flag = false;
	acceleration = 1.3;
}

frame::~frame()
{
}

void frame::setInfo(rectangle _rect,float _weight){
	power_to_velocity = 180.0;
	power_to_vertex = 3.0;
	power_to_rot_velocity = 2.7;

	rot_velocity = 0.0;
	rect = _rect;
	weight = _weight;
	explose_flag = false;
}

void frame::draw(){
	if(explose_flag){
		drawVLine(rect.p[0],rect.p[1],GetColor(200,200,200),1.0);
		drawVLine(rect.p[1],rect.p[2],GetColor(200,200,200),1.0);
		drawVLine(rect.p[2],rect.p[3],GetColor(200,200,200),1.0);
		drawVLine(rect.p[3],rect.p[0],GetColor(200,200,200),1.0);
	}else{
		drawVRect(rect.p[0],rect.p[2],GetColor(255,255,255),0,1.0);
	}
}

void frame::setPosition(vector2D position){
	rect.setPosition(position);
	rect.update();
}

void frame::move(){
	if(explose_flag){
		velocity.y -= acceleration;
		rect.position += velocity;
		rect.theta += rot_velocity;
		rect.rotate();
	}
	rect.update();
}

void frame::sound(){

}

vector2D frame::powerToVelocity(vector2D position, vector2D centroid,float pow){
	vector2D power = (centroid - position);
	return power/(sqrt(power.x*power.x+power.y*power.y)+2.0) * power_to_velocity/sqrt(weight)*pow;
}

vector2D frame::powerToVertex(vector2D position,vector2D vertex,float pow){
	vector2D power = (vertex - position);
	return power/(sqrt(power.x*power.x+power.y*power.y)+2.0) * power_to_rot_velocity/sqrt(weight)*pow;
}

void frame::explose(vector2D position,float power){
	if(!explose_flag){
		for(int i = 0; i< 4 ;i++){
			wing[i] = rect.orip[i] - rect.centroid;
			ccuv[i].set(-wing[i].y,wing[i].x);
			ccuv[i] = ccuv[i]/sqrt(ccuv[i].x*ccuv[i].x+ccuv[i].y*ccuv[i].y);
			pv[i] = powerToVertex(position,rect.position + wing[i],power);
			wing[i].set(wing[i].y,-wing[i].x);//w = w'
			rot_velocity += (wing[i]*pv[i])/(wing[i]*ccuv[i]) * power_to_rot_velocity;
		}

		velocity = powerToVelocity(position,rect.position,power);

		explose_flag = true;
	}
}
