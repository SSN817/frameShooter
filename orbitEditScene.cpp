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


#include "effectTuningScene.h"
#include "menuScene.h"
#include "gameScene.h"
#include "frameEditScene.h"

#include "orbitEditScene.h"

orbitEditScene::orbitEditScene(void)
{
}


orbitEditScene::~orbitEditScene(void)
{
}


void orbitEditScene::run(){
	DrawFormatString(0,20,GetColor(255,255,255),"‹O“¹•ÒWƒV[ƒ“");
	if(isKeyHitted("m"))
		game_base->changeScene(new menuScene, new defaultCurtain);
}

void orbitEditScene::initScene(){

}