#pragma once

//from
//h_ttp://d.hatena.ne.jp/white_wheels/20100304/p2

class vector2D{
public:
	vector2D();
	vector2D(float _x,float _y);
	vector2D& vector2D::operator=(const vector2D& v);
	vector2D& operator+=(const vector2D& v);
	vector2D& operator-=(const vector2D& v);
	vector2D& operator*=(float k);
	vector2D& operator/=(float k);
	vector2D operator+();
	vector2D operator-();

	void set(float _x,float _y);

	float x;
	float y;
};


//ìÒçÄââéZéq
vector2D operator+(const vector2D& u,const vector2D& v);

vector2D operator-(const vector2D& u,const vector2D& v);

float operator*(const vector2D& u,const vector2D& v);

vector2D operator*(const vector2D& v, float k);
vector2D operator*(float k ,const vector2D& v);
vector2D operator/(const vector2D& v, float k);

