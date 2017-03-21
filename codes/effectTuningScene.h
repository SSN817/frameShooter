#pragma once
class effectTuningScene : public scene
{
private:
	frame* test_frame;
	horizontalSlider* p_to_vel_slider;
	horizontalSlider* p_to_ver_slider;
	horizontalSlider* p_to_rot_slider;
	horizontalSlider* ac_slider;
	horizontalSlider* p_slider;
	horizontalSlider* w_slider;
	rectangle rect;
	float power;
public:
	effectTuningScene(void);
	~effectTuningScene(void);
	void run();
	void initScene();
};