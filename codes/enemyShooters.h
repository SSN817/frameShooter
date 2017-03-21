

class basicEnemy : public enemyShooterObserver
	,public drawObserver
	,public moveObserver
	,public reproductionObserver
{
private:
	vector2D position;
	vector2D verocity;
	rectangle rect;
	vector<frame*> frames;
public:
	basicEnemy(subjectSet* subset);
	~basicEnemy();
	void move();
	void draw();
	void reproduction();
	void collideWith(playerBulletObserver* obs);
	shape* getShape();
};