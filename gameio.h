#pragma once


struct DxInputData
{
	DxInputData();
	char keyStates[256];
	bool mouseLeft;
	bool mouseRight;
	bool mouseMiddle;
	int mouseX;
	int mouseY;
	vector2D mousePoint;
};

struct DxIOData
{
	bool Apress;
	bool Aclick;
	bool ApressLog;

	DxInputData now;
	DxInputData log;
	DxInputData hit;

	map<string,int> keyMap;
	map<string,int> imageMap;

	DxIOData();
	~DxIOData();
	void updata();
};

struct windowData
{
	float width;
	float heigth;
	float extention_rate;
	windowData();
};


namespace gio
{
	 void ioUpdate();
	 bool isKeyHitted(string key_name);
	 bool isKeyPressed(string key_Name);
	 bool isMouseHitted(string button_name);
	 bool isMousePressed(string button_name);
	 int nowMouseX();
	 int nowMouseY();
	 vector2D nowMouse();

	 void setWindowSize(int x,int y);
	 void setExtentionRate(float rate);
	 vector2D rtov2D(vector2D real);
	 float rtovx(float x);
	 float rtovy(float y);
	 vector2D vtor2D(vector2D virt);
	 float vtorx(float x);
	 float vtory(float y);
	 void drawVRect(vector2D vp1,vector2D vp2, int color , int fill_flag = 1,float thickness = 1.0);
	 void drawVLine(vector2D vp1,vector2D vp2, int color , float thickness);
	 void drawVString(vector2D v_position, int color, string comment);

	 void loadFile(string fileName,const char delimiter,vector<vector<string>>* buf);
}