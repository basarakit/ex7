#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxTweener.h"
#include "ofxImageSequence.h"
#include "ofxImageHolder.h"
#include "ofxVideoHolder.h"

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
		void showPLMenu();
		void showPSMenu();
		void showBackBtn();
		void showNextBtn();
		void hidePassiveAndActiveSubMenu();
		void hideMenu();// hide the root menu
		void hidePVMenu(string name);//can hide menu by name
		void hidePLMenu(string name);
		void hidePSMenu(string name);
		void hideBackBtn();
		void hideNextBtn();
		void resetBtn();
		void resetAll();
	
		//case menu render function
		void menuRender(vector<ofxImageHolder*> btn, vector<ofxVideoHolder*> movie, vector<ofxVideoHolder*> movieU, string m);
		
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
	
	ofxImageHolder ventilationInL;
	ofxImageHolder ventilationInR;
	
	ofxImageHolder solarInL;
	ofxImageHolder solarInR;
	
	ofxImageHolder lightInL;
	ofxImageHolder lightInR;
	
	//intro video
	ofxVideoHolder introVideo;
	
	//passive ventilation 
	ofxImageHolder earthCoolingBtn, windCatcherBtn, ventilationLayoutBtn;
	
	//passive light
	ofxImageHolder lightPipeBtn, lightShelfBtn, northGlazingBtn;
	
	//passive solar
	ofxImageHolder externalShadingBtn, roofBtn, shadeBtn, windowBtn;
	
	//actve ventilation
	ofxImageHolder fanBtn, hvacBtn;
	
	//active light
	ofxImageHolder sensorBtn, taskLightingBtn;
	
	//active solar
	ofxImageHolder skylightBtn;
	
	//renewable
	ofxImageHolder bioBtn, photovoltaicBtn, thermalBtn;
	
	//case movie
	//passive ventilation
	ofxVideoHolder earth, wind, layout;
	ofxVideoHolder earthU, windU, layoutU;
	
	//passive light
	ofxVideoHolder pipe, shelf, north;
	ofxVideoHolder pipeU, shelfU, northU;
	
	//passive solar
	ofxVideoHolder external, roof, shade, window;
	ofxVideoHolder externalU, roofU, shadeU, windowU;
	
	//active ventilation
	ofxVideoHolder fan, hvac;
	ofxVideoHolder fanU, hvacU;
	
	//active light
	ofxVideoHolder sensor, taskLighting;
	ofxVideoHolder sensorU, taskLightingU;
	
	//active solar
	ofxVideoHolder skylight;
	ofxVideoHolder skylightU;
	
	//renewable
	ofxVideoHolder bio, photovoltaic, thermal;
	ofxVideoHolder bioU, photovoltaicU, thermalU;
	
	vector<ofxImageHolder*> menuBtn;
	vector<ofxImageHolder*> pAMenuBtn;//passive and active menu button
	
	vector<ofxImageHolder*> pVMenuBtn;//passive ventilation menu button
	vector<ofxImageHolder*> pLMenuBtn;//passive light menu button
	vector<ofxImageHolder*> pSMenuBtn;//passive solar menu button
	
	vector<ofxImageHolder*> aVMenuBtn;//active ventilation menu button
	vector<ofxImageHolder*> aLMenuBtn;//active light menu button
	vector<ofxImageHolder*> aSMenuBtn;//active solar menu button
	
	vector<ofxImageHolder*> renewMenuBtn;
	
	vector<ofxVideoHolder*> pVCase, pVCaseU;
	vector<ofxVideoHolder*> pLCase, pLCaseU;
	vector<ofxVideoHolder*> pSCase, pSCaseU;
	
	vector<ofxVideoHolder*> aVCase, aVCaseU;
	vector<ofxVideoHolder*> aLCase, aLCaseU;
	vector<ofxVideoHolder*> aSCase, aSCaseU;
	
	vector<ofxVideoHolder*> renewCase, renewCaseU;
	
	ofArduino	ard;
	bool		bSetupArduino;			// flag variable for setting up arduino once
	
	bool menuPressed;
	bool menuBtnPressed;
	bool backBtnPressed;
	bool nextBtnPressed;

	ofVec2f button1, button2, button3, button4, button5, button6, button7;
	ofVec2f casePos, caseUPos;
};

#endif
