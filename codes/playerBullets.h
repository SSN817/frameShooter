

class defaultBullet : public playerBulletObserver
	,public drawObserver
	,public moveObserver
	,public soundObserver
{
private:
	rectangle rect;
public:
	defaultBullet();
	~defaultBullet(){}
	void setPosition(vector2D pos);
	void draw();
	void move();
	void sound(){}
	shape* getShape();
};

