#pragma once

#include "ofMain.h"

class ofxVideoHolder : public ofBaseApp {
public:
	ofxVideoHolder();
	~ofxVideoHolder();
	
	//load the image sequence
	void load(string path, int _x, int _y, string _name);
	void loadLoop(string path);
	
	void play();
	void idleMovie();
	void draw();
	
	void showCase();
	void reset();
	
	bool isShow();
	
	string caseName;
	ofVideoPlayer caseVideo;
	
protected:
	
	ofVideoPlayer caseLoop;
	
	string casePath;
	string loopPath;
	
	int x;
	int y;
	
	bool show;
	bool needLoop;
	bool loopStart;
};
