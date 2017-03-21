
class basicEnemyBullet : public enemyBulletObserver
	,public drawObserver
	,public moveObserver
	,public soundObserver
{
private:
	rectangle rect;
	vector2D position;
public:
	basicEnemyBullet();
	~basicEnemyBullet();

	void setPosition(vector2D pos);

	void draw();
	void move();

	void collideWith(playerShooterObserver* obs);

	shape* getShape();
};