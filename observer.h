#pragma once

class observer
{
private:
	bool alive_flag;
public:
	observer(void);
	~observer(void);
	bool isAlive();
	void sayonara();
};

class drawObserver : virtual public observer
{
public:
	drawObserver(){}
	virtual ~drawObserver(){}
	virtual void draw(){}
};

class soundObserver : public virtual observer
{
public:
	soundObserver(){}
	~soundObserver(){}
	virtual void sound(){}
};

class moveObserver : public virtual observer
{
public:
	moveObserver(){}
	~moveObserver(){}
	virtual void move(){}

};

class inputObserver : public virtual observer
{
public:
	inputObserver(){}
	~inputObserver(){}
	virtual void checkInput(){}
};


class playerShooterObserver;
class playerBulletObserver;
class enemyShooterObserver;
class enemyBulletObserver;
class itemObserver;

class playerShooterObserver : public virtual observer
	,public collisionableObject
{
public:
	playerShooterObserver(){}
	~playerShooterObserver(){}
	virtual void collideWith(enemyShooterObserver* obs){}
	virtual void collideWith(enemyBulletObserver* obs){}
	virtual void collideWith(itemObserver*  obs){}
};

class playerBulletObserver : public virtual observer
	,public collisionableObject
{
public:
	playerBulletObserver(){}
	~playerBulletObserver(){}
	virtual void collideWith(enemyShooterObserver* obs){}
};

class enemyShooterObserver : public virtual observer
	,public collisionableObject
{
public:
	enemyShooterObserver(){}
	~enemyShooterObserver(){}
	virtual void collideWith(playerShooterObserver* obs){}
	virtual void collideWith(playerBulletObserver* obs){}
	virtual void collideWith(itemObserver*  obs){}
};

class enemyBulletObserver : public virtual observer
	,public collisionableObject
{
public:
	enemyBulletObserver(){}
	~enemyBulletObserver(){}
	virtual void collideWith(playerShooterObserver* obs){}
};

class itemObserver : public virtual observer
	,public collisionableObject
{
public:
	itemObserver(){}
	~itemObserver(){}
	virtual void collideWith(playerShooterObserver* obs){}
};

class subjectSet;

class reproductionObserver : public virtual observer
{
protected:
	subjectSet* subject_set;
public:
	reproductionObserver(subjectSet* subset){subject_set = subset;}
	~reproductionObserver(){}
	virtual void reproduction(){};
};