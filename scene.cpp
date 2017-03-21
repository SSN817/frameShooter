#include <vector>
#include <string>
#include <map>
using namespace std;

#include "DxLib.h"
#include "vector2D.h"
#include "gameio.h"
using namespace gio;
#include "shape.h"

#include "observer.h"
#include "subject.h"

#include "concreteObservers.h"
#include "scene.h"
#include "menuScene.h"

scene::scene()
{
}

scene::~scene(void)
{
}

void scene::setInfo(game* g_base, subjectSet* sub_set){
	game_base = g_base;
	subject_set = sub_set;
}


game::game(void)
{
	now_curtain = NULL;
	next_scene  = NULL;
	now_scene = new menuScene();
	now_scene ->setInfo(this,&subject_set);
	changing_flag = false;
}

game::~game(void)
{
	if(now_scene != NULL)
		delete now_scene;
}

void game::changeScene(scene* next,curtain* cur){
	if(!changing_flag){
		changing_flag = true;
		next_scene = next;
		now_curtain = cur;
		subject_set.setObserver(cur);
		now_curtain ->beginClose();
	}else{
		delete next;
		delete cur;
	}
}

void game::run(){
	subject_set.update();
	update();
	now_scene->run();
}

void game::update(){

	if(changing_flag && now_curtain != NULL){
		if(now_curtain->isClosed() && now_scene != next_scene){
			delete now_scene;
			now_scene = next_scene;
			now_scene -> setInfo(this,&subject_set);
			now_scene -> initScene();
		}

		if(now_curtain->isOpened()){
			now_curtain->sayonara();
			now_curtain = NULL;
			changing_flag = false;
		}
	}
}
