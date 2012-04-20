#include "ofxVideoHolder.h"

ofxVideoHolder::ofxVideoHolder() {
	show = false;
	needLoop = false;
	loopStart = false;
}

ofxVideoHolder::~ofxVideoHolder() {
}

void ofxVideoHolder::load(string _casePath, int _x, int _y, string _name) 
{
	casePath = _casePath;
	x = _x;
	y = _y;
	caseName = _name;
	caseVideo.loadMovie(casePath);
}

void ofxVideoHolder::loadLoop(string _loopPath)
{
	//needLoop = true;
	loopPath = _loopPath;
	caseLoop.loadMovie(loopPath);
}

void ofxVideoHolder::play() 
{
	caseVideo.play();
	caseVideo.setLoopState(OF_LOOP_NONE);
	caseVideo.setFrame(0);
	//caseLoop.play();
}

void ofxVideoHolder::idleMovie() 
{
	caseVideo.idleMovie();
	caseLoop.idleMovie();
}

void ofxVideoHolder::draw()
{
	if(needLoop == true && caseVideo.getCurrentFrame() == caseVideo.getTotalNumFrames()) {
		caseLoop.setFrame(0);
		loopStart = true;
		caseVideo.stop();
		caseVideo.setFrame(0);
	}

	if(loopStart == true) caseLoop.draw(x, y);
	else caseVideo.draw(x, y);
}

void ofxVideoHolder::showCase()
{
	show = true;
	play();
}

bool ofxVideoHolder::isShow() {
	return show;
}

void ofxVideoHolder::reset()
{
	show = false;
	
}