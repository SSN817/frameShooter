#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
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


#include "orbitEditScene.h"
#include "effectTuningScene.h"
#include "menuScene.h"
#include "gameScene.h"

#include "frameEditScene.h"

float round(float r) {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

frameEditor::frameEditor(){
	use_flag = false;
	use_flag = false;
	index = 0;
	color = GetColor(255,255,255);
	index_color = GetColor(200,200,200);
}

void frameEditor::draw(){

	int c;
	for(int i = 0; i <rects.size();i++){
		if(index == i)
			c = index_color;
		else
			c = color;
		drawer->drawLineOnPlane(rects.at(i).p[0].x,rects.at(i).p[0].y,rects.at(i).p[1].x,rects.at(i).p[1].y,c);
		drawer->drawLineOnPlane(rects.at(i).p[1].x,rects.at(i).p[1].y,rects.at(i).p[2].x,rects.at(i).p[2].y,c);
		drawer->drawLineOnPlane(rects.at(i).p[2].x,rects.at(i).p[2].y,rects.at(i).p[3].x,rects.at(i).p[3].y,c);
		drawer->drawLineOnPlane(rects.at(i).p[3].x,rects.at(i).p[3].y,rects.at(i).p[0].x,rects.at(i).p[0].y,c);
	}
	
	drawVRect(p1 + pos, p2 + pos,GetColor(255,255,255),0,1.0);
	if(use_flag){
		drawVRect(p1 + pos, p2 + pos,color,1);
		drawVString(p1 + pos,GetColor(255,255,255),name);
	}else
		drawVString(p1 + pos,GetColor(127,127,127),name);
}

void frameEditor::edit(){
	if(use_flag){
		if(isKeyHitted("up"))
			index++;
		if(isKeyHitted("down"))
			index--;

		if(index > rects.size() - 1)
			index = rects.size() - 1;
		if(index < 0)
			index = 0;

		if(isKeyHitted("d")){
			for(int i = 0; i<rects.size();i++)
				if(i != index)
					buf.push_back(rects.at(i));
			buf.swap(rects);
			buf.clear();
		}

		if(index > rects.size() - 1)
			index = rects.size() - 1;
		if(index < 0)
			index = 0;
	}
}




frameEditScene::frameEditScene(void)
{
	drag_flag = false;
	extention_rate = 1.0;
	x = 0;
	y = 0;
	edit_flag = false;
	
	file_name[0] = 0;

	main.pos.set(30.0,30.0);
	sub.pos.set(70.0,30.0);
	gun.pos.set(110.0,30.0);
	design.pos.set(150.0,30.0);

	main.name = "主";
	sub.name = "副";
	gun.name = "銃";
	design.name = "飾";

	main.color = GetColor(255,0,0);
	sub.color = GetColor(0,255,0);
	gun.color = GetColor(0,0,255);
	design.color = GetColor(0,255,255);

	main.index_color = GetColor(200,0,0);
	sub.index_color = GetColor(0,200,0);
	gun.index_color = GetColor(0,0,200);
	design.index_color = GetColor(0,200,200);

	editors.push_back(&main);
	editors.push_back(&sub);
	editors.push_back(&gun);
	editors.push_back(&design);

	for(int i = 0;i<editors.size();i++){
		editors.at(i)->p1.set(-10.0,-10.0);
		editors.at(i)->p2.set(10.0,10.0);
		editors.at(i)->drawer = this;
	}

	now_editor = &main;
	now_editor->use_flag = true;

}


frameEditScene::~frameEditScene(void)
{
	ex_slider->sayonara();
}

void frameEditScene::drawLineOnPlane(int x1,int y1,int x2,int y2,int color){
	
	vector2D p1,p2;
	p1.set(min(x1,x2),min(y1,y2));
	p1 = p1*extention_rate;
	p2.set(max(x1,x2)+1,max(y1,y2)+1);
	p2 = p2*extention_rate;
	
	drawVRect(p1+position,p2+position,color,1);
}

void frameEditScene::button(){
	
	if(!edit_flag){
		if(isKeyHitted("1")){
			for(int i = 0;i<editors.size();i++)
				editors.at(i)->use_flag = false;
			now_editor = &main;
		}
		if(isKeyHitted("2")){
			for(int i = 0;i<editors.size();i++)
				editors.at(i)->use_flag = false;
			now_editor = &sub;
		}
		if(isKeyHitted("3")){
			for(int i = 0;i<editors.size();i++)
				editors.at(i)->use_flag = false;
			now_editor = &gun;
		}
		if(isKeyHitted("4")){
			for(int i = 0;i<editors.size();i++)
				editors.at(i)->use_flag = false;
			now_editor = &design;
		}
		now_editor->use_flag = true;
	}

}

void frameEditScene::save(){
	DrawFormatString(0,100,GetColor(255,255,255),"ファイル名:%s",file_name);
	if(isKeyHitted("s")){
		KeyInputString(0,80,100,file_name,TRUE);
		string name = file_name;
		
		ofstream ofs;
		ofs.open(name, std::ios::trunc);

		ofs<<"main_collision_frame"<<","<<main.rects.size()<<endl;
		ofs<<"sub_collision_frame"<<","<<sub.rects.size()<<endl;
		ofs<<"gun_frame"<<","<<gun.rects.size()<<endl;
		ofs<<"design_frame"<<","<<design.rects.size()<<endl;

		
		for(int i = 0;i<editors.size();i++)
			for(int j = 0;j<editors.at(i)->rects.size();j++){
				ofs<<editors.at(i)->rects.at(j).p[2].x<<","
				   <<editors.at(i)->rects.at(j).p[2].y<<","
				   <<editors.at(i)->rects.at(j).p[0].x<<","
				   <<editors.at(i)->rects.at(j).p[0].y<<endl;
			}
	}
}

void frameEditScene::edit(){

	now_editor->edit();

	for(int i = 0; i<editors.size(); i++)
		editors.at(i)->draw();

	if(!edit_flag && isMouseHitted("right")){
		edit_flag = true;
		now_editor->f1.set(x,y);
	}

	if(edit_flag && isMouseHitted("left")){
		edit_flag = false;
		now_editor->f2.set(x,y);

		now_editor->v1.set(min(now_editor->f1.x,now_editor->f2.x),min(now_editor->f1.y,now_editor->f2.y));
		now_editor->v2.set(max(now_editor->f1.x,now_editor->f2.x),max(now_editor->f1.y,now_editor->f2.y));
		rectangle rect;
		rect.setShape(now_editor->v1,now_editor->v2);
		now_editor->rects.push_back(rect);
	}
}



void frameEditScene::movePlane(){
	if(isMouseHitted("middle")){
		drag_flag = true;
		link = rtov2D(nowMouse()) - position;
	}
	if(!isMousePressed("middle"))
		drag_flag = false;

	if(drag_flag)
		position = rtov2D(nowMouse()) - link;

	if(isKeyHitted("z"))
		position.set(0.0,0.0);

}

void frameEditScene::drawPointer(){

	mouse_on_plane = rtov2D(nowMouse()) - position;
	if(mouse_on_plane.x > 0.0)
		x = round((abs(mouse_on_plane.x) - fmod(abs(mouse_on_plane.x),extention_rate))/extention_rate);
	else
		x = round(-(abs(mouse_on_plane.x) - fmod(abs(mouse_on_plane.x),extention_rate))/extention_rate -1.0);

	if(mouse_on_plane.y > 0.0)
		y = round((abs(mouse_on_plane.y) - fmod(abs(mouse_on_plane.y),extention_rate))/extention_rate);
	else
		y = round(-(abs(mouse_on_plane.y) - fmod(abs(mouse_on_plane.y),extention_rate))/extention_rate -1.0);
	
	DrawFormatString(vtorx(50.0),vtory(500.0),GetColor(255,255,255),"(%f,%f)",x,y);
}

void frameEditScene::drawLine(){

	float x1,y1;
	int bx,by;

	bx = (abs(position.x)-fmod(abs(position.x),extention_rate))/extention_rate + 1;
	by = (abs(position.y)-fmod(abs(position.y),extention_rate))/extention_rate + 1;

	if(position.x > 0.0){
		x1 = position.x - bx * extention_rate;
	}else{
		x1 = position.x + bx * extention_rate;
	}

	if(position.y > 0.0){
		y1 = position.y - by * extention_rate;
	}else{
		y1 = position.y + by * extention_rate;
	}

	if(extention_rate > 5.0){
		vector2D p1,p2;
		int i = 0;
		while(x1+i*extention_rate<1000.0){
			p1.set(x1+i*extention_rate,-20.0);
			p2.set(x1+i*extention_rate,800.0);
			drawVLine(p1,p2,GetColor(100,100,100),1.0);
			i++;
		}

		i = 0;
		while(y1+i*extention_rate<1000.0){
			p1.set(-20.0,y1+i*extention_rate);
			p2.set(1000.0,y1+i*extention_rate);
			drawVLine(p1,p2,GetColor(100,100,100),1.0);
			i++;
		}
	}
}



void frameEditScene::run(){
	button();
	save();
	edit();
	movePlane();
	drawLine();
	drawPointer();

	drawLineOnPlane(x,y,x,y,GetColor(200,200,200));


	vector2D d;
	d.set(2.0,2.0);
	drawVRect(position + d, position - d,GetColor(255,0,0),1); 

	extention_rate = ex_slider ->valueLeftTop()*40.0f +1.0f;
	DrawFormatString(vtorx(250.0),vtory(70.0),GetColor(255,255,255),"×%f",extention_rate);


	DrawFormatString(0,20,GetColor(255,255,255),"フレーム編集シーン");
	if(isKeyHitted("m"))
		game_base->changeScene(new menuScene, new defaultCurtain);
}

void frameEditScene::initScene(){
	vector2D pos;
	pos.set(50.0,70.0);
	ex_slider = new horizontalSlider;
	ex_slider ->setInfo(pos,400.0);
	subject_set->setObserver(ex_slider);
}