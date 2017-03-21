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

#include "gameScene.h"
#include "frameEditScene.h"
#include "orbitEditScene.h"
#include "effectTuningScene.h"

#include "menuScene.h"




menuScene::~menuScene(void)
{
}

void menuScene::run(){
	DrawFormatString(0,20,GetColor(255,255,255),"メニューシーン");
	if(isKeyHitted("g"))
		game_base->changeScene(new gameScene,new defaultCurtain);
	if(isKeyHitted("f"))
		game_base->changeScene(new frameEditScene,new defaultCurtain);
	if(isKeyHitted("o"))
		game_base->changeScene(new orbitEditScene,new defaultCurtain);
	if(isKeyHitted("e"))
		game_base->changeScene(new effectTuningScene,new defaultCurtain);
}

void menuScene::initScene(){

}