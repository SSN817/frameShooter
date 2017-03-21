#pragma once

class game;

class scene
{
protected:
	game* game_base;
	subjectSet* subject_set;
public:
	scene();
	virtual~scene();
	void setInfo(game* g_base, subjectSet* sub_set);
	virtual void run(){}
	virtual void initScene(){}
};


class game
{
private:
	curtain* now_curtain;
	scene* next_scene;
	scene* now_scene;
	bool changing_flag;
	subjectSet subject_set;
public:
	game(void);
	~game(void);
	void changeScene(scene* nextScene,curtain* cur);
	void run();
	void update();
};

