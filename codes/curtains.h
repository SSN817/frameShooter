

class curtain : public drawObserver
	,public soundObserver
{
private:
public:
	curtain(){};
	~curtain(){};
	virtual void beginClose(){}
	virtual bool isClosed(){return false;}
	virtual bool isOpened(){return false;}
};

class defaultCurtain : public curtain
{
private:
	bool beginCloseFlag;
	bool isClosedFlag;
	bool isOpenedFlag;
	int count;
	int curtainPosition;

	vector<pair<rectangle,float>> salts;

public:
	defaultCurtain(void);
	~defaultCurtain(void);
	void draw();
	void beginClose();
	bool isOpened();
	bool isClosed();
};

