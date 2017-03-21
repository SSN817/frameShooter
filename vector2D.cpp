#include "vector2D.h"

vector2D::vector2D():x(0),y(0)
{
}

vector2D::vector2D(float _x,float _y):x(_x),y(_y)
{
}
//代入演算子の定義
vector2D& vector2D::operator=(const vector2D& v){
	this->x=v.x;	this->y=v.y;
	return *this;
}
// +=の定義
vector2D& vector2D::operator+=(const vector2D& v){
	this->x += v.x;	this->y += v.y;	return *this;		
}
// -=の定義
vector2D& vector2D::operator-=(const vector2D& v){
	this->x -= v.x;	this->y -= v.y;	return *this;		
}
// *=の定義
vector2D& vector2D::operator*=(float k){
	this->x *= k;	this->y *= k;	return *this;	
}
// /=の定義
vector2D& vector2D::operator/=(float k){
	this->x /= k;	this->y /= k;	return *this;	
}

//+の定義:	+v
vector2D vector2D::operator+(){			
	return *this;
}
//-の定義:	-v
vector2D vector2D::operator-(){			
	return vector2D(-x,-y);
}

void vector2D::set(float _x,float _y){
	x = _x;
	y = _y;
}



//二項演算子
vector2D operator+(const vector2D& u,const vector2D& v){	//vector+vector
	vector2D w;
	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return w;
}

vector2D operator-(const vector2D& u,const vector2D& v){	//vector-vector
	vector2D w;
	w.x = u.x - v.x;
	w.y = u.y - v.y;
	return w;
}

float operator*(const vector2D& u,const vector2D& v){	//内積 vector*vector
	return u.x * v.x + u.y * v.y;
}

vector2D operator*(const vector2D& v, float k){	//vector*scalar
	vector2D w;
	w.x = v.x * k;
	w.y = v.y * k;
	return w;
}
vector2D operator*(float k ,const vector2D& v){	//scalar*vector
	vector2D w;
	w.x = v.x * k;
	w.y = v.y * k;
	return w;
}
vector2D operator/(const vector2D& v, float k){	//vector/scalar
	vector2D w;
	w.x = v.x / k;
	w.y = v.y / k;
	return w;
}

