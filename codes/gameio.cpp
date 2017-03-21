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

	keyMap["back"] = KEY_INPUT_BACK;// �o�b�N�X�y�[�X�L�[
	keyMap["tab"] = KEY_INPUT_TAB;// �^�u�L�[
	keyMap["return"] = KEY_INPUT_RETURN;// �G���^�[�L�[

	keyMap["lshitt"] = KEY_INPUT_LSHIFT;// ���V�t�g�L�[
	keyMap["rshift"] = KEY_INPUT_RSHIFT;// �E�V�t�g�L�[
	keyMap["lcontrol"] = KEY_INPUT_LCONTROL;// ���R���g���[���L�[
	keyMap["rcontrol"] = KEY_INPUT_RCONTROL;// �E�R���g���[���L�[
	keyMap["escape"] = KEY_INPUT_ESCAPE;// �G�X�P�[�v�L�[
	keyMap["space"] = KEY_INPUT_SPACE;// �X�y�[�X�L�[
	keyMap["pgup"] = KEY_INPUT_PGUP;// �o�������t�o�L�[
	keyMap["pgdn"] = KEY_INPUT_PGDN;// �o�������c�������L�[
	keyMap["end"] = KEY_INPUT_END;// �G���h�L�[
	keyMap["home"] = KEY_INPUT_HOME;// �z�[���L�[
	keyMap["left"] = KEY_INPUT_LEFT;// ���L�[
	keyMap["up"] = KEY_INPUT_UP;// ��L�[
	keyMap["right"] = KEY_INPUT_RIGHT;// �E�L�[
	keyMap["down"] = KEY_INPUT_DOWN;// ���L�[
	keyMap["insert"] = KEY_INPUT_INSERT;// �C���T�[�g�L�[
	keyMap["delete"] = KEY_INPUT_DELETE;// �f���[�g�L�[

	keyMap["minus"] = KEY_INPUT_MINUS;// �|�L�[
	keyMap["yen"] = KEY_INPUT_YEN;// ���L�[
	keyMap["prevtrack"] = KEY_INPUT_PREVTRACK;// �O�L�[
	keyMap["period"] = KEY_INPUT_PERIOD;// �D�L�[
	keyMap["slash"] = KEY_INPUT_SLASH;// �^�L�[
	keyMap["lalt"] = KEY_INPUT_LALT;// ���`�k�s�L�[
	keyMap["ralt"] = KEY_INPUT_RALT;// �E�`�k�s�L�[
	keyMap["scroll"] = KEY_INPUT_SCROLL;// ScrollLock�L�[
	keyMap["semicolon"] = KEY_INPUT_SEMICOLON;// �G�L�[
	keyMap["colon"] = KEY_INPUT_COLON;// �F�L�[
	keyMap["lbracket"] = KEY_INPUT_LBRACKET;// �m�L�[
	keyMap["rbracket"] = KEY_INPUT_RBRACKET;// �n�L�[
	keyMap["at"] = KEY_INPUT_AT;// ���L�[
	keyMap["backslash"] = KEY_INPUT_BACKSLASH;// �_�L�[
	keyMap["comma"] = KEY_INPUT_COMMA;// �C�L�[
	keyMap["capslock"] = KEY_INPUT_CAPSLOCK;// CaspLock�L�[
	keyMap["pausebreak"] = KEY_INPUT_PAUSE;// PauseBreak�L�[

	keyMap["numpad0"] = KEY_INPUT_NUMPAD0;// �e���L�[�O
	keyMap["numpad1"] = KEY_INPUT_NUMPAD1;// �e���L�[�P
	keyMap["numpad2"] = KEY_INPUT_NUMPAD2;// �e���L�[�Q
	keyMap["numpad3"] = KEY_INPUT_NUMPAD3;// �e���L�[�R
	keyMap["numpad4"] = KEY_INPUT_NUMPAD4;// �e���L�[�S
	keyMap["numpad5"] = KEY_INPUT_NUMPAD5;// �e���L�[�T
	keyMap["numpad6"] = KEY_INPUT_NUMPAD6;// �e���L�[�U
	keyMap["numpad7"] = KEY_INPUT_NUMPAD7;// �e���L�[�V
	keyMap["numpad8"] = KEY_INPUT_NUMPAD8;// �e���L�[�W
	keyMap["numpad9"] = KEY_INPUT_NUMPAD9;// �e���L�[�X
	keyMap["numpadmultiply"] = KEY_INPUT_MULTIPLY;// �e���L�[���L�[
	keyMap["add"] = KEY_INPUT_ADD;// �e���L�[�{�L�[
	keyMap["subtract"] = KEY_INPUT_SUBTRACT;// �e���L�[�|�L�[
	keyMap["decimal"] = KEY_INPUT_DECIMAL;// �e���L�[�D�L�[
	keyMap["divide"] = KEY_INPUT_DIVIDE;// �e���L�[�^�L�[
	keyMap["numpadenter"] = KEY_INPUT_NUMPADENTER;// �e���L�[�̃G���^�[�L�[

	keyMap["f1"] = KEY_INPUT_F1;// �e�P�L�[
	keyMap["f2"] = KEY_INPUT_F2;// �e�Q�L�[
	keyMap["f3"] = KEY_INPUT_F3;// �e�R�L�[
	keyMap["f4"] = KEY_INPUT_F4;// �e�S�L�[
	keyMap["f5"] = KEY_INPUT_F5;// �e�T�L�[
	keyMap["f6"] = KEY_INPUT_F6;// �e�U�L�[
	keyMap["f7"] = KEY_INPUT_F7;// �e�V�L�[
	keyMap["f8"] = KEY_INPUT_F8;// �e�W�L�[
	keyMap["f9"] = KEY_INPUT_F9;// �e�X�L�[
	keyMap["f10"] = KEY_INPUT_F10;// �e�P�O�L�[
	keyMap["f11"] = KEY_INPUT_F11;// �e�P�P�L�[
	keyMap["f12"] = KEY_INPUT_F12;// �e�P�Q�L�[

	keyMap["a"] = KEY_INPUT_A;// �`�L�[
	keyMap["b"] = KEY_INPUT_B;// �a�L�[
	keyMap["c"] = KEY_INPUT_C;// �b�L�[
	keyMap["d"] = KEY_INPUT_D;// �c�L�[
	keyMap["e"] = KEY_INPUT_E;// �d�L�[
	keyMap["f"] = KEY_INPUT_F;// �e�L�[
	keyMap["g"] = KEY_INPUT_G;// �f�L�[
	keyMap["h"] = KEY_INPUT_H;// �g�L�[
	keyMap["i"] = KEY_INPUT_I;// �h�L�[
	keyMap["j"] = KEY_INPUT_J;// �i�L�[
	keyMap["k"] = KEY_INPUT_K;// �j�L�[
	keyMap["l"] = KEY_INPUT_L;// �k�L�[
	keyMap["m"] = KEY_INPUT_M;// �l�L�[
	keyMap["n"] = KEY_INPUT_N;// �m�L�[
	keyMap["o"] = KEY_INPUT_O;// �n�L�[
	keyMap["p"] = KEY_INPUT_P;// �o�L�[
	keyMap["q"] = KEY_INPUT_Q;// �p�L�[
	keyMap["r"] = KEY_INPUT_R;// �q�L�[
	keyMap["s"] = KEY_INPUT_S;// �r�L�[
	keyMap["t"] = KEY_INPUT_T;// �s�L�[
	keyMap["u"] = KEY_INPUT_U;// �t�L�[
	keyMap["v"] = KEY_INPUT_V;// �u�L�[
	keyMap["w"] = KEY_INPUT_W;// �v�L�[
	keyMap["x"] = KEY_INPUT_X;// �w�L�[
	keyMap["y"] = KEY_INPUT_Y;// �x�L�[
	keyMap["z"] = KEY_INPUT_Z;// �y�L�[
	keyMap["0"] = KEY_INPUT_0;// �O�L�[
	keyMap["1"] = KEY_INPUT_1;// �P�L�[
	keyMap["2"] = KEY_INPUT_2;// �Q�L�[
	keyMap["3"] = KEY_INPUT_3;// �R�L�[
	keyMap["4"] = KEY_INPUT_4;// �S�L�[
	keyMap["5"] = KEY_INPUT_5;// �T�L�[
	keyMap["6"] = KEY_INPUT_6;// �U�L�[
	keyMap["7"] = KEY_INPUT_7;// �V�L�[
	keyMap["8"] = KEY_INPUT_8;// �W�L�[
	keyMap["9"] = KEY_INPUT_9;// �X�L�[
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
	SetGraphMode(x,y,32);//�E�C���h�E�̃T�C�Y�w��
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

	readingFile.open(fileName, std::ios::in);//�ǂݍ��ݐ�p���[�h�ŊJ��
	
	if(readingFile.fail()){
		line.push_back("error");
		buf->push_back(line);
		return;
	}


	while (!readingFile.eof())
	{
		line.clear();
		getline(readingFile,lineBuffer);//reading_line_buffer��1��ǂݍ���
		istringstream separater(lineBuffer);
		while(getline(separater,wordBuffer, delimiter))//getline���I���܂ŋ�؂�ςݕ�����ǂݍ���
			line.push_back(wordBuffer);
		buf->push_back(line);
	}
}
