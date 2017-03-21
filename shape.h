#pragma once


struct circle;
struct rectangle;

struct shape
{
	shape(void);
	~shape(void);
	virtual bool checkCollide(shape* s){return false;}
	virtual bool checkCollide(rectangle* s){return false;}
	virtual bool checkCollide(circle* s){return false;}
};


struct rectangle : public shape
{
	vector2D orip[4];//‰Šúİ’è
	vector2D rot[4];//‰ñ“]Œã
	vector2D p[4];//ˆÚ“®‚ª‰Á‚í‚Á‚½Œ»İ‚ÌˆÊ’u
	float width;
	float heigth;
	vector2D position;
	vector2D centroid;

	float theta;

	rectangle();
	~rectangle();
	void setShape(float rx1,float ry1,float rx2,float ry2);
	void setShape(vector2D p1,vector2D p2);
	void setPosition(float px,float py);
	void setPosition(vector2D pos);
	void setAngle(float t);
	void rotate();
	void update();

	bool checkCollide(shape* s);
	bool checkCollide(rectangle* s);
	bool checkCollide(circle* s);



	bool isPointIn(float px,float py);
	bool isPointIn(vector2D p);
};

struct circle : public shape
{
	float x;
	float y;
	float r;

	circle();
	~circle();
	bool checkCollide(shape* s);
	bool checkCollide(rectangle* s);
	bool checkCollide(circle* s);

};

class collisionableObject
{
public:
	virtual shape* getShape(){return NULL;}
};

bool checkCollide(collisionableObject* a,collisionableObject *b);
