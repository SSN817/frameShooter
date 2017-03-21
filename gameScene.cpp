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

#include "frameEditScene.h"
#include "orbitEditScene.h"
#include "effectTuningScene.h"
#include "menuScene.h"

#include "gameScene.h"


gameScene::~gameScene(void)
{
}


void gameScene::run(){
	DrawFormatString(0,40,GetColor(255,255,255),"ƒQ[ƒ€ƒV[ƒ“");
	if(isKeyHitted("m"))
		game_base->changeScene(new menuScene,new defaultCurtain);
}

void gameScene::initScene()
{
	basicEnemy* enemy = new basicEnemy(subject_set);
	subject_set->setObserver(enemy);

	defaultShooter* shooter = new defaultShooter(subject_set);
	subject_set->setObserver(shooter);
}