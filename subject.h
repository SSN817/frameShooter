#pragma once

namespace gio
{
	void show();
	void show2();
}


template<class Obs>
class subject
{
protected:
	vector<Obs*> buf;
	vector<Obs*> observers;
public:
	subject(void){};
	virtual ~subject(void){};
	
	void setObserver(Obs* obs){
		observers.push_back(obs);
	}
	void setObserver(observer* obs){}

	virtual void deleteObservers(){
		buf.clear();
		for(unsigned int i =0;i<observers.size();i++)
			if(observers.at(i)->isAlive())
				buf.push_back(observers.at(i));
		observers.swap(buf);
	}

	virtual void run(){}

	unsigned int size(){
		return observers.size();
	}

	Obs* at(int i){
		return observers.at(i);
	}
};

class drawSubject : public subject<drawObserver>
{
public:
	drawSubject(){}
	~drawSubject(){}
	void run(){
		for(unsigned int i = 0 ; i < observers.size() ; i++)
			observers.at(i)->draw();
	}
};

class moveSubject : public subject<moveObserver>
{
public:
	moveSubject(){}
	~moveSubject(){}
	void run(){
		for(unsigned int i = 0 ; i < observers.size() ; i++)
			observers.at(i)->move();
	}
};

class soundSubject : public subject<soundObserver>
{
public:
	soundSubject(){}
	~soundSubject(){}
	void run(){
		for(unsigned int i = 0 ; i < observers.size() ; i++)
			observers.at(i)->sound();
	}
};

class inputSubject : public subject<inputObserver>
{
public:
	inputSubject(){}
	~inputSubject(){}
	void run(){
		for(unsigned int i = 0 ; i < observers.size() ; i++)
			observers.at(i)->checkInput();
	}
};

class collisionSubjects
{
private:
	subject<playerShooterObserver> player_shooters;
	subject<playerBulletObserver> player_bullets;
	subject<enemyShooterObserver> enemy_shooters;
	subject<enemyBulletObserver> enemy_bullets;
	subject<itemObserver> items;

public:
	collisionSubjects(){}
	~collisionSubjects(){}
	void deleteObservers(){};
	template<class Obs>
	void setObserver(Obs* obs){
		player_shooters.setObserver(obs);
		player_bullets.setObserver(obs);
		enemy_shooters.setObserver(obs);
		enemy_bullets.setObserver(obs);
		items.setObserver(obs);
	}
	
	void run(){
		for(unsigned int i = 0 ; i < player_shooters.size() ; i++)
			for(unsigned int j = 0 ; j < enemy_shooters.size() ; j++)
				if(checkCollide(player_shooters.at(i),enemy_shooters.at(j))){
					player_shooters.at(i)->collideWith(enemy_shooters.at(j));
					enemy_shooters.at(j)->collideWith(player_shooters.at(i));
				}
		
		for(unsigned int i = 0 ; i < player_shooters.size() ; i++)
			for(unsigned int j = 0 ; j < enemy_bullets.size() ; j++)
				if(checkCollide(player_shooters.at(i),enemy_bullets.at(j))){
					player_shooters.at(i)->collideWith(enemy_bullets.at(j));
					enemy_bullets.at(j)->collideWith(player_shooters.at(i));
				}
		
		for(unsigned int i = 0 ; i < player_shooters.size() ; i++)
			for(unsigned int j = 0 ; j < items.size() ; j++)
				if(checkCollide(player_shooters.at(i),items.at(j))){
					player_shooters.at(i)->collideWith(items.at(j));
					items.at(j)->collideWith(player_shooters.at(i));
				}
		
		for(unsigned int i = 0 ; i < player_bullets.size() ; i++)
			for(unsigned int j = 0 ; j < enemy_shooters.size() ; j++)
				if(checkCollide(player_bullets.at(i),enemy_shooters.at(j))){
					player_bullets.at(i)->collideWith(enemy_shooters.at(j));
					enemy_shooters.at(j)->collideWith(player_bullets.at(i));
				}
	}
};

class reproductionSubject : public subject<reproductionObserver>
{
public:
	reproductionSubject(){}
	~reproductionSubject(){}
	void run(){
		for(unsigned int i = 0 ; i < observers.size() ; i++)
			observers.at(i)->reproduction();
	}
};

class subjectSet
{
private:
	vector<observer*> observers;
	vector<observer*> buf;
	drawSubject draws;
	soundSubject sounds;
	moveSubject moves;
	inputSubject inputs;
	reproductionSubject reproductions;
	collisionSubjects collisions;
public:
	template<class Obs>
	void setObserver(Obs* obs){
		draws.setObserver(obs);
		sounds.setObserver(obs);
		moves.setObserver(obs);
		inputs.setObserver(obs);
		collisions.setObserver(obs);
		reproductions.setObserver(obs);
	}
	void update(){
		draws.run();
		sounds.run();
		moves.run();
		inputs.run();
		collisions.run();
		reproductions.run();
		
		draws.deleteObservers();
		sounds.deleteObservers();
		moves.deleteObservers();
		inputs.deleteObservers();
		collisions.deleteObservers();
		reproductions.deleteObservers();

		for(unsigned int i = 0 ; i <observers.size() ; i ++){
			if(observers.at(i)->isAlive())
				buf.push_back(observers.at(i));
			else
				delete  observers.at(i);
			observers.swap(buf);
		}
	}
};