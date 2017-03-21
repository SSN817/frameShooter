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
#include "gameScene.h"
#include "frameEditScene.h"
#include "orbitEditScene.h"

#include "effectTuningScene.h"


effectTuningScene::effectTuningScene(void)
{
}


effectTuningScene::~effectTuningScene(void)
{
	test_frame->sayonara();
	p_to_ver_slider->sayonara();
	p_to_vel_slider->sayonara();
	p_to_rot_slider->sayonara();
	ac_slider->sayonara();
	w_slider->sayonara();
	p_slider->sayonara();
}


void effectTuningScene::run(){
	DrawFormatString(0,20,GetColor(255,255,255),"エフェクト調整シーン");




	test_frame->power_to_vertex       = p_to_ver_slider->valueLeftTop()*10.0;
	test_frame->power_to_velocity     = p_to_vel_slider->valueLeftTop()*1000.0;
	test_frame->power_to_rot_velocity = p_to_rot_slider->valueLeftTop()*10.0;
	test_frame->acceleration          =       ac_slider->valueLeftTop()*10.0;
	test_frame->weight                =       w_slider->valueLeftTop()*1000.0;
	power                             =       p_slider->valueLeftTop()*10.0;

	DrawFormatString(vtorx(300.0),vtory(220.0),GetColor(255,255,255),"%f(ver)",p_to_ver_slider->valueLeftTop()*10.0);
	DrawFormatString(vtorx(300.0),vtory(190.0),GetColor(255,255,255),"%f(vel)",p_to_vel_slider->valueLeftTop()*1000.0);
	DrawFormatString(vtorx(300.0),vtory(160.0),GetColor(255,255,255),"%f(rot)",p_to_rot_slider->valueLeftTop()*10.0);
	DrawFormatString(vtorx(300.0),vtory(130.0),GetColor(255,255,255),"%f(acc)",      ac_slider->valueLeftTop()*10.0);
	DrawFormatString(vtorx(300.0),vtory(100.0),GetColor(255,255,255),"%f(pow)",       p_slider->valueLeftTop()*10.0);
	DrawFormatString(vtorx(300.0),vtory(70.0) ,GetColor(255,255,255),"%f(wei)",       w_slider->valueLeftTop()*1000.0);


	if(isKeyHitted("p"))
		test_frame->explose(rtov2D(nowMouse()),power);

	if(isKeyHitted("return"))
		test_frame->setInfo(rect,40.0);


	if(isKeyHitted("m"))
		game_base->changeScene(new menuScene, new defaultCurtain);
}

void effectTuningScene::initScene(){
	vector2D position;
	rect.setPosition(400.0,400.0);
	rect.setShape(-50.0+20,-20.0+20,50.0+20,20.0+20);
	test_frame = new frame;
	test_frame->setInfo(rect,40.0);
	subject_set->setObserver(test_frame);

	p_to_ver_slider = new horizontalSlider;
	position.set(100.0,210.0);
	p_to_ver_slider->setInfo(position,200.0);
	subject_set->setObserver(p_to_ver_slider);

	p_to_vel_slider = new horizontalSlider;
	position.set(100.0,180.0);
	p_to_vel_slider->setInfo(position,200.0);
	subject_set->setObserver(p_to_vel_slider);

	p_to_rot_slider = new horizontalSlider;
	position.set(100.0,150.0);
	p_to_rot_slider->setInfo(position,200.0);
	subject_set->setObserver(p_to_rot_slider);

	ac_slider = new horizontalSlider;
	position.set(100.0,120.0);
	ac_slider->setInfo(position,200.0);
	subject_set->setObserver(ac_slider);

	p_slider = new horizontalSlider;
	position.set(100.0,90.0);
	p_slider->setInfo(position,200.0);
	subject_set->setObserver(p_slider);

	w_slider = new horizontalSlider;
	position.set(100.0,60.0);
	w_slider->setInfo(position,200.0);
	subject_set->setObserver(w_slider);
}