#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxTweener.h"
#include "ofxImageSequence.h"
#include "ofxImageHolder.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		void showMenu();// the root menu
		void showPassiveAndActiveSubMenu(string name);// the passive and active sub menu
		void showPVMenu();
		void showBackBtn();
		void showNextBtn();
		void hidePassiveAndActiveSubMenu();
		void hideMenu();// hide the root menu
		void hidePVMenu(string name);//can hide menu by name
		void hideBackBtn();
		void hideNextBtn();
		void resetBtn();
		void resetAll();
		
		void setupArduino(const int & version);
		void updateArduino();
	
	
	ofImage background;
	
	string mode;
	
	ofxImageHolder backBtn;
	ofxImageHolder nextBtn;

	ofxImageHolder renewInL;
	ofxImageHolder renewInR;
	
	ofxImageHolder activeInL;
	ofxImageHolder activeInR;
	
	ofxImageHolder passiveInL;
	ofxImageHolder passiveInR;
	
	ofxImageHolder tmpCase;
	
	ofxImageHolder ventilationInL;
	ofxImageHolder ventilationInR;
	
	ofxImageHolder solarInL;
	ofxImageHolder solarInR;
	
	ofxImageHolder lightInL;
	ofxImageHolder lightInR;
	
	ofxImageHolder earthCoolingBtn;
	
	
	ofxImageSequence returnInR;
	
	ofArduino	ard;
	bool		bSetupArduino;			// flag variable for setting up arduino once
	
	protected:
		bool menuPressed;
		bool menuBtnPressed;
		vector<ofxImageHolder*> menuBtn;
		vector<ofxImageHolder*> pAMenuBtn;//passive and active menu button
		vector<ofxImageHolder*> pVMenuBtn;//passive ventilation menu button
};

#endif
