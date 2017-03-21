

class defaultShooter : public playerShooterObserver
	,public drawObserver
	,public moveObserver
	,public soundObserver
	,public reproductionObserver
{
private:
	vector2D position;
	rectangle rect;
	bool collide_flag;
public:
	defaultShooter(subjectSet* subset);
	~defaultShooter();
	void reproduction();
	void move();
	void draw();

	void collideWith(enemyShooterObserver* Obs);


	shape* getShape();
};