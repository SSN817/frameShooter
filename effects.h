
class frame : public drawObserver
	,public moveObserver
	,public soundObserver
{
public:
	float power_to_velocity;
	float power_to_vertex;
	float power_to_rot_velocity;
	float acceleration;
	float weight;
private:
	rectangle rect;
	vector2D velocity;
	float rot_velocity;
	bool explose_flag;
	vector2D centroid;
	vector2D ccuv[4];//counter_clockwise_unit_vector
	vector2D wing[4];//centroid to vertex
	vector2D pv[4];//power to vertex
public:
	frame();
	~frame();
	void setInfo(rectangle _rect,float _weight);
	void setPosition(vector2D position);
	void draw();
	void move();
	void sound();
	vector2D powerToVertex(vector2D position, vector2D vertex,float pow);
	vector2D powerToVelocity(vector2D position,vector2D centroid,float pow);
	void explose(vector2D position,float power);
};


