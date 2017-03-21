#include "math.h"
#include "DxLib.h"
#include "vector2D.h"
#include "shape.h"




shape::shape(void)
{
}

shape::~shape(void)
{
}


rectangle::rectangle()
{
	theta = 0.0;
}

rectangle::~rectangle()
{
	
}

void rectangle::setShape(float rx1,float ry1,float rx2,float ry2){
	orip[0].set(max(rx1,rx2),max(ry1,ry2));
	orip[1].set(min(rx1,rx2),max(ry1,ry2));
	orip[2].set(min(rx1,rx2),min(ry1,ry2));
	orip[3].set(max(rx1,rx2),min(ry1,ry2));
	for(int i =0;i<4;i++)
		rot[i] = orip[i];
	centroid = (orip[0]+orip[2])*0.5;
	width = abs(rx1 - rx2);
	heigth = abs(ry1 - ry2);
	update();
}

void rectangle::setShape(vector2D p1,vector2D p2){
	orip[0].set(max(p1.x,p2.x),max(p1.y,p2.y));
	orip[1].set(min(p1.x,p2.x),max(p1.y,p2.y));
	orip[2].set(min(p1.x,p2.x),min(p1.y,p2.y));
	orip[3].set(max(p1.x,p2.x),min(p1.y,p2.y));
	for(int i =0;i<4;i++)
		rot[i] = orip[i];
	centroid = (orip[0]+orip[2])*0.5;
	width = abs(p1.x - p2.x);
	heigth = abs(p1.y - p2.y);
	update();
}

void rectangle::setPosition(float px,float py){
	position.set(px,py);
	update();
}

void rectangle::setPosition(vector2D pos){
	position = pos;
	update();
}

void rectangle::setAngle(float t){
	theta = t;
}
void rectangle::rotate(){
	for(int i =0;i<4;i++){
		rot[i].x = orip[i].x * cos(theta) - orip[i].y*sin(theta);
		rot[i].y = orip[i].x * sin(theta) + orip[i].y*cos(theta);
	}
}

void rectangle::update(){
	for(int i =0;i<4;i++)
		p[i] = rot[i] + position;
}

bool rectangle::checkCollide(shape* s)
{
	return s->checkCollide(this);
}

bool rectangle::checkCollide(rectangle* s)
{
	return (s->width + width >= max(abs(s->p[0].x - p[2].x),abs((s->p[2].x - p[0].x)))) && 
		 (s->heigth + heigth >= max(abs(s->p[0].y - p[2].y),abs((s->p[2].y - p[0].y))));
}

bool rectangle::checkCollide(circle* s)
{
	return false;
}

bool rectangle::isPointIn(float px,float py){
	return (((p[1].x<=px) && (p[0].x>=px))
		 && ((p[3].y<=py) && (p[0].y>=py))); 
}

bool rectangle::isPointIn(vector2D point){
	return (((p[1].x<=point.x) && (p[0].x>=point.x))
		 && ((p[3].y<=point.y) && (p[0].y>=point.y))); 
}


circle::circle()
{
	x = 0.0;
	y = 0.0;
	r = 0.0;
}

circle::~circle()
{

}

bool circle::checkCollide(shape* s)
{
	return s->checkCollide(this);
}

bool circle::checkCollide(rectangle* s)
{
	return false;
}

bool circle::checkCollide(circle* s)
{
	return false;
}





bool checkCollide(collisionableObject* a,collisionableObject* b){
	if((a->getShape()!= NULL) && (b->getShape()!= NULL))
		return a->getShape()->checkCollide(b->getShape());
	return false;
}

