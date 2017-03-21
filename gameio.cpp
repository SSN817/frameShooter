#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#include"DxLib.h"

#include "vector2D.h"

#include "gameio.h"


DxIOData gameio_data;


DxInputData::DxInputData()
{
	GetHitKeyStateAll(keyStates);
	mouseX = 0;
	mouseY = 0;
	bool mouseLeft = false;
	bool mouseRight = false;
	bool mouseMiddle = false;
}

DxIOData::DxIOData()
{
	Apress = false;
	Aclick = false;
	ApressLog = false;

	keyMap["back"] = KEY_INPUT_BACK;// バックスペースキー
	keyMap["tab"] = KEY_INPUT_TAB;// タブキー
	keyMap["return"] = KEY_INPUT_RETURN;// エンターキー

	keyMap["lshitt"] = KEY_INPUT_LSHIFT;// 左シフトキー
	keyMap["rshift"] = KEY_INPUT_RSHIFT;// 右シフトキー
	keyMap["lcontrol"] = KEY_INPUT_LCONTROL;// 左コントロールキー
	keyMap["rcontrol"] = KEY_INPUT_RCONTROL;// 右コントロールキー
	keyMap["escape"] = KEY_INPUT_ESCAPE;// エスケープキー
	keyMap["space"] = KEY_INPUT_SPACE;// スペースキー
	keyMap["pgup"] = KEY_INPUT_PGUP;// ＰａｇｅＵＰキー
	keyMap["pgdn"] = KEY_INPUT_PGDN;// ＰａｇｅＤｏｗｎキー
	keyMap["end"] = KEY_INPUT_END;// エンドキー
	keyMap["home"] = KEY_INPUT_HOME;// ホームキー
	keyMap["left"] = KEY_INPUT_LEFT;// 左キー
	keyMap["up"] = KEY_INPUT_UP;// 上キー
	keyMap["right"] = KEY_INPUT_RIGHT;// 右キー
	keyMap["down"] = KEY_INPUT_DOWN;// 下キー
	keyMap["insert"] = KEY_INPUT_INSERT;// インサートキー
	keyMap["delete"] = KEY_INPUT_DELETE;// デリートキー

	keyMap["minus"] = KEY_INPUT_MINUS;// －キー
	keyMap["yen"] = KEY_INPUT_YEN;// ￥キー
	keyMap["prevtrack"] = KEY_INPUT_PREVTRACK;// ＾キー
	keyMap["period"] = KEY_INPUT_PERIOD;// ．キー
	keyMap["slash"] = KEY_INPUT_SLASH;// ／キー
	keyMap["lalt"] = KEY_INPUT_LALT;// 左ＡＬＴキー
	keyMap["ralt"] = KEY_INPUT_RALT;// 右ＡＬＴキー
	keyMap["scroll"] = KEY_INPUT_SCROLL;// ScrollLockキー
	keyMap["semicolon"] = KEY_INPUT_SEMICOLON;// ；キー
	keyMap["colon"] = KEY_INPUT_COLON;// ：キー
	keyMap["lbracket"] = KEY_INPUT_LBRACKET;// ［キー
	keyMap["rbracket"] = KEY_INPUT_RBRACKET;// ］キー
	keyMap["at"] = KEY_INPUT_AT;// ＠キー
	keyMap["backslash"] = KEY_INPUT_BACKSLASH;// ＼キー
	keyMap["comma"] = KEY_INPUT_COMMA;// ，キー
	keyMap["capslock"] = KEY_INPUT_CAPSLOCK;// CaspLockキー
	keyMap["pausebreak"] = KEY_INPUT_PAUSE;// PauseBreakキー

	keyMap["numpad0"] = KEY_INPUT_NUMPAD0;// テンキー０
	keyMap["numpad1"] = KEY_INPUT_NUMPAD1;// テンキー１
	keyMap["numpad2"] = KEY_INPUT_NUMPAD2;// テンキー２
	keyMap["numpad3"] = KEY_INPUT_NUMPAD3;// テンキー３
	keyMap["numpad4"] = KEY_INPUT_NUMPAD4;// テンキー４
	keyMap["numpad5"] = KEY_INPUT_NUMPAD5;// テンキー５
	keyMap["numpad6"] = KEY_INPUT_NUMPAD6;// テンキー６
	keyMap["numpad7"] = KEY_INPUT_NUMPAD7;// テンキー７
	keyMap["numpad8"] = KEY_INPUT_NUMPAD8;// テンキー８
	keyMap["numpad9"] = KEY_INPUT_NUMPAD9;// テンキー９
	keyMap["numpadmultiply"] = KEY_INPUT_MULTIPLY;// テンキー＊キー
	keyMap["add"] = KEY_INPUT_ADD;// テンキー＋キー
	keyMap["subtract"] = KEY_INPUT_SUBTRACT;// テンキー－キー
	keyMap["decimal"] = KEY_INPUT_DECIMAL;// テンキー．キー
	keyMap["divide"] = KEY_INPUT_DIVIDE;// テンキー／キー
	keyMap["numpadenter"] = KEY_INPUT_NUMPADENTER;// テンキーのエンターキー

	keyMap["f1"] = KEY_INPUT_F1;// Ｆ１キー
	keyMap["f2"] = KEY_INPUT_F2;// Ｆ２キー
	keyMap["f3"] = KEY_INPUT_F3;// Ｆ３キー
	keyMap["f4"] = KEY_INPUT_F4;// Ｆ４キー
	keyMap["f5"] = KEY_INPUT_F5;// Ｆ５キー
	keyMap["f6"] = KEY_INPUT_F6;// Ｆ６キー
	keyMap["f7"] = KEY_INPUT_F7;// Ｆ７キー
	keyMap["f8"] = KEY_INPUT_F8;// Ｆ８キー
	keyMap["f9"] = KEY_INPUT_F9;// Ｆ９キー
	keyMap["f10"] = KEY_INPUT_F10;// Ｆ１０キー
	keyMap["f11"] = KEY_INPUT_F11;// Ｆ１１キー
	keyMap["f12"] = KEY_INPUT_F12;// Ｆ１２キー

	keyMap["a"] = KEY_INPUT_A;// Ａキー
	keyMap["b"] = KEY_INPUT_B;// Ｂキー
	keyMap["c"] = KEY_INPUT_C;// Ｃキー
	keyMap["d"] = KEY_INPUT_D;// Ｄキー
	keyMap["e"] = KEY_INPUT_E;// Ｅキー
	keyMap["f"] = KEY_INPUT_F;// Ｆキー
	keyMap["g"] = KEY_INPUT_G;// Ｇキー
	keyMap["h"] = KEY_INPUT_H;// Ｈキー
	keyMap["i"] = KEY_INPUT_I;// Ｉキー
	keyMap["j"] = KEY_INPUT_J;// Ｊキー
	keyMap["k"] = KEY_INPUT_K;// Ｋキー
	keyMap["l"] = KEY_INPUT_L;// Ｌキー
	keyMap["m"] = KEY_INPUT_M;// Ｍキー
	keyMap["n"] = KEY_INPUT_N;// Ｎキー
	keyMap["o"] = KEY_INPUT_O;// Ｏキー
	keyMap["p"] = KEY_INPUT_P;// Ｐキー
	keyMap["q"] = KEY_INPUT_Q;// Ｑキー
	keyMap["r"] = KEY_INPUT_R;// Ｒキー
	keyMap["s"] = KEY_INPUT_S;// Ｓキー
	keyMap["t"] = KEY_INPUT_T;// Ｔキー
	keyMap["u"] = KEY_INPUT_U;// Ｕキー
	keyMap["v"] = KEY_INPUT_V;// Ｖキー
	keyMap["w"] = KEY_INPUT_W;// Ｗキー
	keyMap["x"] = KEY_INPUT_X;// Ｘキー
	keyMap["y"] = KEY_INPUT_Y;// Ｙキー
	keyMap["z"] = KEY_INPUT_Z;// Ｚキー
	keyMap["0"] = KEY_INPUT_0;// ０キー
	keyMap["1"] = KEY_INPUT_1;// １キー
	keyMap["2"] = KEY_INPUT_2;// ２キー
	keyMap["3"] = KEY_INPUT_3;// ３キー
	keyMap["4"] = KEY_INPUT_4;// ４キー
	keyMap["5"] = KEY_INPUT_5;// ５キー
	keyMap["6"] = KEY_INPUT_6;// ６キー
	keyMap["7"] = KEY_INPUT_7;// ７キー
	keyMap["8"] = KEY_INPUT_8;// ８キー
	keyMap["9"] = KEY_INPUT_9;// ９キー
}

DxIOData::~DxIOData()
{
}


windowData window_data;

windowData::windowData(){
	width = 1000.0;
	heigth = 640.0;
	extention_rate = 1.0;
}



void gio::ioUpdate(){
	gameio_data.log = gameio_data.now;
	GetHitKeyStateAll(gameio_data.now.keyStates);

	for(int i = 0;i<256;i++){
		gameio_data.hit.keyStates[i] = 0;
		if((gameio_data.log.keyStates[i] == 0) && (gameio_data.now.keyStates[i] == 1))
			gameio_data.hit.keyStates[i]=1;
	}
	int x,y;
	GetMousePoint(&x,&y);
	gameio_data.now.mousePoint.set(x,y);
	gameio_data.now.mouseX=gameio_data.now.mousePoint.x;
	gameio_data.now.mouseY=gameio_data.now.mousePoint.y;

	gameio_data.now.mouseLeft =false;
	if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		gameio_data.now.mouseLeft = true;

	gameio_data.now.mouseRight =false;
	if((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
		gameio_data.now.mouseRight = true;

	gameio_data.now.mouseMiddle =false;
	if((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)
		gameio_data.now.mouseMiddle = true;


	if(!gameio_data.log.mouseLeft && gameio_data.now.mouseLeft)
		gameio_data.hit.mouseLeft = true;
	else
		gameio_data.hit.mouseLeft = false;


	if(!gameio_data.log.mouseRight && gameio_data.now.mouseRight)
		gameio_data.hit.mouseRight = true;
	else
		gameio_data.hit.mouseRight = false;


	if(!gameio_data.log.mouseMiddle && gameio_data.now.mouseMiddle)
		gameio_data.hit.mouseMiddle = true;
	else
		gameio_data.hit.mouseMiddle = false;
}

bool gio::isKeyHitted(string keyName)
{
	return gameio_data.hit.keyStates[gameio_data.keyMap[keyName.c_str()]];
}

bool gio::isKeyPressed(string keyName)
{
	return gameio_data.now.keyStates[gameio_data.keyMap[keyName.c_str()]];
}

bool gio::isMouseHitted(string buttonName){
	if(buttonName == "left")
		return gameio_data.hit.mouseLeft;
	if(buttonName == "right")
		return gameio_data.hit.mouseRight;
	if(buttonName == "middle")
		return gameio_data.hit.mouseMiddle;
	return false;
}

bool gio::isMousePressed(string buttonName){
	if(buttonName == "left")
		return gameio_data.now.mouseLeft;
	if(buttonName == "right")
		return gameio_data.now.mouseRight;
	if(buttonName == "middle")
		return gameio_data.now.mouseMiddle;
	return false;
}

int gio::nowMouseX(){
	return gameio_data.now.mouseX;
}

int gio::nowMouseY(){
	return gameio_data.now.mouseY;
}

vector2D gio::nowMouse(){
	return gameio_data.now.mousePoint;
}





void gio::setWindowSize(int x, int y){
	SetGraphMode(x,y,32);//ウインドウのサイズ指定
	window_data.width = x;
	window_data.heigth = y;
}

void setExtentionRate(float rate){
	window_data.extention_rate = rate;
}

vector2D gio::rtov2D(vector2D real){
	real.y = -real.y + window_data.heigth -1;
	return real;
}

float gio::rtovx(float x){
	return x;
}

float gio::rtovy(float y){
	return  -y + window_data.heigth -1;
}

vector2D gio::vtor2D(vector2D virt){
	virt.y = -virt.y + window_data.heigth -1;
	return virt;
}

float gio::vtorx(float x){
	return x;
}

float gio::vtory(float y){
	return  -y + window_data.heigth -1;
}

void gio::drawVRect(vector2D vp1, vector2D vp2, int color, int fill_flag,float thickness){
	vp1 = vtor2D(vp1);
	vp2 = vtor2D(vp2);
	DrawBoxAA(min(vp1.x,vp2.x), min(vp1.y,vp2.y),max(vp1.x,vp2.x), max(vp1.y,vp2.y), color, fill_flag, thickness);
}

void gio::drawVLine(vector2D vp1, vector2D vp2, int color, float thickness){
	vp1 = vtor2D(vp1);
	vp2 = vtor2D(vp2);
	DrawLineAA(vp1.x, vp1.y, vp2.x, vp2.y, color, thickness);
}

void gio::drawVString(vector2D v_position, int color, string comment){
	DrawFormatString(vtorx(v_position.x),vtory(v_position.y),color,comment.c_str());
}

void gio::loadFile(string fileName,const char delimiter,vector<vector<string>>* buf){
	ifstream readingFile;
	string wordBuffer;
	vector<string> line;
	string lineBuffer;

	readingFile.open(fileName, std::ios::in);//読み込み専用モードで開く
	
	if(readingFile.fail()){
		line.push_back("error");
		buf->push_back(line);
		return;
	}


	while (!readingFile.eof())
	{
		line.clear();
		getline(readingFile,lineBuffer);//reading_line_bufferに1列読み込む
		istringstream separater(lineBuffer);
		while(getline(separater,wordBuffer, delimiter))//getlineが終わるまで区切り済み文字列読み込み
			line.push_back(wordBuffer);
		buf->push_back(line);
	}
}
