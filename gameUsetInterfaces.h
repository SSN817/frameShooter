#pragma once

class arrowSelectableItem
{
private:
	arrowSelectableItem* up;
	arrowSelectableItem* down;
	arrowSelectableItem* right;
	arrowSelectableItem* left;
	bool selectFlag;
public:
	arrowSelectableItem();
	~arrowSelectableItem();
	void setNextItem(arrowSelectableItem* U,arrowSelectableItem* D,arrowSelectableItem* L,arrowSelectableItem* R);
	void selectNextItem();
	void selectThis();
	bool isSelected();
};


class rectangleButton : public drawObserver
	,public soundObserver
	,public arrowSelectableItem
	,public inputObserver
{
private:
	rectangle rect;
	string name;
	bool hit;
public:
	rectangleButton(void){};
	~rectangleButton(void){};
	void setInfo(vector2D v1,vector2D v2);
	void setName(string buttonName);
	void loadInfo(string fileName){};
	void draw();
	void checkInput();
	bool isHitted();
};

class verticalSlider : public drawObserver
	,public moveObserver
	,public inputObserver
{
private:
	vector2D link;
	bool linkFlag;
	vector2D position;
	double length;
	rectangle rect;
public:
	verticalSlider();
	~verticalSlider(){};
	void setInfo(vector2D pos,double len);
	void draw();
	void move();
	void checkInput();
	double valueHighTop();
	double valueLowTop();
};


class horizontalSlider : public drawObserver
	,public moveObserver
	,public inputObserver
{
private:
	vector2D link;
	bool linkFlag;
	vector2D position;
	double length;
	rectangle rect;
public:
	horizontalSlider();
	~horizontalSlider(){};
	void setInfo(vector2D pos,double len);
	void draw();
	void move();
	void checkInput();
	double valueRightTop();
	double valueLeftTop();
};


