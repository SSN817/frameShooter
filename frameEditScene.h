#pragma once


class frameEditScene;

struct frameEditor
{
	bool use_flag;
	bool edit_flag;
	vector<rectangle> rects;
	vector<rectangle> buf;
	int index;
	vector2D pos,p1,p2,v1,v2,f1,f2;
	string name;
	frameEditor();
	int color,index_color;
	frameEditScene* drawer;

	void draw();
	void edit();
};


class frameEditScene : public scene
{
private:
	vector2D position;
	vector2D link;
	vector2D mouse_on_plane;
	bool drag_flag;
	float extention_rate;
	horizontalSlider* ex_slider;
	float x,y;
	char file_name[100];

	bool edit_flag;
	frameEditor main;
	frameEditor sub;
	frameEditor gun;
	frameEditor design;

	vector<frameEditor*> editors;
	frameEditor* now_editor;
public:
	frameEditScene(void);
	~frameEditScene(void);
	void drawLineOnPlane(int x1,int y1,int x2,int y2,int color);
	void button();
	void save();
	void edit();
	void movePlane();
	void drawPointer();
	void drawLine();
	void run();
	void initScene();
};

