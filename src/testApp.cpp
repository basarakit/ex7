#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	mode = "menu";
	menuPressed = false;
	menuBtnPressed = false;
	
	//image init
	
	//back and next button
	backBtn.load("icon/back/back_button_right_", "png", 0, 14, 5, 666, 55, "back");
	backBtn.loadGlow("icon/back/touch/back_button_right_touch_effect_", "png", 15, 29, 5);
	
	nextBtn.load("icon/next/next_button_right_", "png", 0, 14, 5, 666, 55, "next");
	nextBtn.loadGlow("icon/next/touch/next_button_right_touch_effect_", "png", 15, 29, 5);
	
	//passive button
	passiveInL.load("icon/passive/left/passive_design_button_left_", "png", 0, 14, 5, 204, 487, "passiveL");
	passiveInL.loadGlow("icon/passive/left/touch/passive_design_button_left_touch_effect_", "png", 15, 29, 5);
	
	passiveInR.load("icon/passive/right/passive_design_button_right_", "png", 0, 14, 5, 666, 487, "passiveR");
	passiveInR.loadGlow("icon/passive/right/touch/passive_design_button_right_touch_effect_", "png", 15, 29, 5);

	//active button
	activeInL.load("icon/active/left/active_systems_button_left_", "png", 0, 14, 5, 204, 340, "activeL");
	activeInL.loadGlow("icon/active/left/touch/active_systems_button_left_touch_effects_", "png", 15, 29, 5);
	
	activeInR.load("icon/active/right/active_systems_button_right_", "png", 0, 14, 5, 666, 340, "activeR");
	activeInR.loadGlow("icon/active/right/touch/active_systems_button_right_touch_effect_", "png", 15, 29, 5);
	
	//renewable button
	renewInL.load("icon/renewable/left/renewable_energy_button_left_", "png", 0, 14, 5, 204, 202, "renewL");
	renewInL.loadGlow("icon/renewable/left/touch/renewable_energy_button_left_touch_effect_", "png", 15, 29, 5);
	
	renewInR.load("icon/renewable/right/renewable_energy_button_right_", "png", 0, 14, 5, 666, 202, "renewR");
	renewInR.loadGlow("icon/renewable/right/touch/renewable_energy_button_right_touch_effect_", "png", 15, 29, 5);
	
	menuBtn.push_back(&renewInL);
	menuBtn.push_back(&activeInL);
	menuBtn.push_back(&passiveInL);
	menuBtn.push_back(&renewInR);
	menuBtn.push_back(&activeInR);
	menuBtn.push_back(&passiveInR);
	
	
	//ventilation button
	ventilationInL.load("icon/passive/ventilation/left/ventilation_button_left_", "png", 0, 14, 5, 204, 202, "ventilationL");
	ventilationInL.loadGlow("icon/passive/ventilation/left/touch/ventilation_button_left_touch_effect_", "png", 15, 29, 5);
	
	ventilationInR.load("icon/passive/ventilation/right/ventilation_button_right_", "png", 0, 14, 5, 666, 202, "ventilationR");
	ventilationInR.loadGlow("icon/passive/ventilation/right/touch/ventilation_button_right_touch_effect_", "png", 15, 29, 5);
	
	//solar button
	solarInL.load("icon/passive/solar/left/solar_control_button_left_", "png", 0, 14, 5, 204, 340, "solarL");
	solarInL.loadGlow("icon/passive/solar/left/touch/solar_control_button_left_touch_effect_", "png", 15, 29, 5);
	
	solarInR.load("icon/passive/solar/right/solar_control_button_right_", "png", 0, 14, 5, 666, 340, "solarR");
	solarInR.loadGlow("icon/passive/solar/right/touch/solar_control_button_right_touch_effect_", "png", 15, 29, 5);

	//light button
	lightInL.load("icon/passive/light/left/light_button_left_", "png", 0, 14, 5, 204, 487, "lightL");
	lightInL.loadGlow("icon/passive/light/left/touch/light_button_left_touch_effect_", "png", 15, 29, 5);
	
	lightInR.load("icon/passive/light/right/light_button_right_", "png", 0, 14, 5, 666, 487, "lightR");
	lightInR.loadGlow("icon/passive/light/right/touch/light_button_right_touch_effect_", "png", 15, 29, 5);
	
	pAMenuBtn.push_back(&ventilationInL);
	pAMenuBtn.push_back(&solarInL);
	pAMenuBtn.push_back(&lightInL);
	pAMenuBtn.push_back(&ventilationInR);
	pAMenuBtn.push_back(&solarInR);
	pAMenuBtn.push_back(&lightInR);
	
	//passive ventilation button
	earthCoolingBtn.load("icon/passive/earthcooling/earth_cooling_button_", "png", 0, 14, 5, 204, 202, "earthCooling");
	earthCoolingBtn.loadGlow("icon/passive/earthcooling/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	pVMenuBtn.push_back(&earthCoolingBtn);
	
	tmpCase.load("case/AnimationA2_A_S_active skylight_", "png", 0, 249, 5, 110, 0, "tmp");
	tmpCase.loadGlow("case/loop/AnimationA2_A_S_active skylight_", "png", 250, 274, 5);
	tmpCase.setPlaySubLoop();
	tmpCase.hideSeq();

	background.loadImage("bgTmp.png");

	
	//ard.connect("/dev/tty.usbmodem411", 57600);
	
	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	//ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
	
	//bSetupArduino = false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void testApp::update(){
	//updateArduino();
	Tweener.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofDisableAlphaBlending();
	ofSetColor(255);
	//background.draw(0,0, 1024, 768);
	ofBackground(0);
	if(tmpCase.isShow() == true) {
		tmpCase.play(false, false);
	}
	ofEnableAlphaBlending();
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	ofSetColor(255, 255);
	
	for(int i=0;i<menuBtn.size();i++) {
		if(menuBtn[i]->isShow() == true) {
			if(menuBtn[i]->isRev() == false) {//when one of button start to  play
				if(menuPressed == true) menuBtn[i]->setRev();//set other button play reverse
				menuBtn[i]->play(false, false);
			} else {//one of button start to play reverse 
				if(menuPressed == false) menuPressed = true;//check the first menu button pressed
				if(menuBtn[i]->play(false, true) == true) {//when it is play reverse finish
					showPassiveAndActiveSubMenu(mode);
					showBackBtn();
				}
			}
		} else menuPressed = false;// return default state
	}

	if(mode == "passive" || mode == "active") {
		for(int i=0;i<pAMenuBtn.size();i++) {
			if(pAMenuBtn[i]->isShow() == true) {
				if(pAMenuBtn[i]->isRev() == false) {//when one of button start to play
					if(menuBtnPressed == true) pAMenuBtn[i]->setRev();//set other button play reverse
					pAMenuBtn[i]->play(false, false);
				} else {//one of button start to play reverse 
					if(menuBtnPressed == false) menuBtnPressed = true;//check the first menu button pressed
					if(pAMenuBtn[i]->play(false, true) == true) {//when it is play reverse finish
						if(backBtn.isPressed() == true) {
							backBtn.setPressed(false);
							showMenu();
							break;
						} else {
							showPVMenu();
							break;
						}
					}
				}
			} 
		}
	}
	
	if(mode == "PV") {//passive ventilation
		for(int i=0;i<pVMenuBtn.size();i++) {
			if(pVMenuBtn[i]->isShow() == true) {
				if(pVMenuBtn[i]->isRev() == false) {//when one of button start to play
					if(menuBtnPressed == true && pVMenuBtn[i]->isPressed() == false) pVMenuBtn[i]->setRev();//set other button play reverse
					pVMenuBtn[i]->play(false, false);
				} else {//one of button start to play reverse 
					if(menuBtnPressed == false) {//check the first menu button pressed
						menuBtnPressed = true;
					}
					if(pVMenuBtn[i]->isPressed() == true) {//check which one clicked
						pVMenuBtn[i]->setRev(false);
						pVMenuBtn[i]->play(false, false);
						backBtn.setRev(true);//backBtn leave at same time
					} else {
						if(pVMenuBtn[i]->play(false, true) == true) {//when it is play reverse finish
							showNextBtn();
						}
					}
				}
			}
		}
	}
	
	//back button show here
	if(backBtn.isShow() == true) {
		if(backBtn.isRev() == false) {
			backBtn.play(false, false);
		} else {
			if(backBtn.play(false, true) == true) {
				if(mode == "active" || mode == "passive" || mode == "renewable") {
					hidePassiveAndActiveSubMenu();
				}
			}
		}
	}
	
	//next button show here
	if(nextBtn.isShow() == true) {
		if(nextBtn.isRev() == false) {
			nextBtn.play(false, false);
		} else {
			nextBtn.play(false, true);
		}
	}

	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if(key =='o') {//right renewable button
		if(mode == "menu") {
			mode = "renewable";
			menuBtn[3]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[3]->setOver();
		} else if(mode == "active") {
			mode = "AVentilation";
			pAMenuBtn[3]->setOver();
		} 
	} else if(key == 'k') {//right active button
		if(mode == "menu") {
			mode = "active";
			menuBtn[4]->setOver();
		} else if(mode == "passive") {
			mode = "PSolar";
			pAMenuBtn[4]->setOver();
		} else if(mode == "active") {
			mode = "ASolar";
			pAMenuBtn[4]->setOver();
		} 
	} else if(key == 'm') {//right passive button
		if(mode == "menu") {
			mode = "passive";
			menuBtn[5]->setOver();
		} else if(mode == "passive") {
			mode = "PLight";
			pAMenuBtn[5]->setOver();
		} else if(mode == "active") {
			mode = "ALight";
			pAMenuBtn[5]->setOver();
		} 
	} else if(key == 'q') {//left renewable button
		if(mode == "menu") {
			mode = "renewable";
			menuBtn[0]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[0]->setOver();
		} else if(mode == "active") {
			mode = "AVentilation";
			pAMenuBtn[0]->setOver();
		} else if(mode == "PV") {
			pVMenuBtn[0]->setOver();
			pVMenuBtn[0]->setPressed(true);
		}
	} else if(key == 'a') {//left active button
		if(mode == "menu") {
			mode = "active";
			menuBtn[1]->setOver();
		} else if(mode == "passive") {
			mode = "PSolar";
			pAMenuBtn[1]->setOver();
		} else if(mode == "active") {
			mode = "ASolar";
			pAMenuBtn[1]->setOver();
		} 
	} else if(key == 'z') {//left passive button
		if(mode == "menu") {
			mode = "passive";
			menuBtn[2]->setOver();
		} else if(mode == "passive") {
			mode = "PLight";
			pAMenuBtn[2]->setOver();
		} else if(mode == "active") {
			mode = "ALight";
			pAMenuBtn[2]->setOver();
		} 
	} else if(key == 's') {
		
	} else if(key == 'i') {
		if(mode == "active" || mode == "passive" || mode == "renewable") {
			backBtn.setOver();
		}
	} else if(key == 'u') {

	} else if(key == 'y') {

	} else if(key == 't') {

	} else if(key =='v') {
		showMenu();
	} else if(key == 'b') {
		resetAll();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::showMenu() {
	mode = "menu";
	resetBtn();
	for(int i=0;i<menuBtn.size();i++) {
		menuBtn[i]->showSeq();
	}
}

void testApp::showPassiveAndActiveSubMenu(string name) {
	mode = name;
	for(int i=0;i<pAMenuBtn.size();i++) {
		pAMenuBtn[i]->reset();
		pAMenuBtn[i]->showSeq();
	}
	
}

void testApp::showPVMenu() {
	menuBtnPressed = false;
	mode = "PV";
	for(int i=0;i<pVMenuBtn.size();i++) {
		pVMenuBtn[i]->reset();
		pVMenuBtn[i]->showSeq();
	}
	
}

void testApp::showBackBtn() {
	backBtn.reset();
	backBtn.showSeq();
}

void testApp::showNextBtn() {
	nextBtn.reset();
	nextBtn.showSeq();
}

void testApp::hidePVMenu(string name) {
	if(name == "all") {
		mode = "PV";
		for(int i=0;i<pVMenuBtn.size();i++) {
			pVMenuBtn[i]->setRev();
		}
	}
}

void testApp::hidePassiveAndActiveSubMenu() {
	for(int i=0;i<pAMenuBtn.size();i++) {
		pAMenuBtn[i]->setRev();	
	}
	
}

void testApp::hideMenu() {
	for(int i=0;i<menuBtn.size();i++) {
		menuBtn[i]->setRev();
	}
}

void testApp::hideBackBtn() {
	backBtn.setRev();
}

void testApp::hideNextBtn() {
	nextBtn.setRev();
}

void testApp::resetBtn() {
	menuPressed = false;
	menuBtnPressed = false;
	backBtn.reset();
	nextBtn.reset();
	for(int i=0;i<menuBtn.size();i++) {
		menuBtn[i]->reset();
	}
	for(int i=0;i<pAMenuBtn.size();i++) {
		pAMenuBtn[i]->reset();	
	}
	for(int i=0;i<pVMenuBtn.size();i++) {
		pVMenuBtn[i]->reset();
	}
}

void testApp::resetAll() {
	mode = "menu";
	menuPressed = false;
	menuBtnPressed = false;
	backBtn.reset();
	nextBtn.reset();
	for(int i=0;i<menuBtn.size();i++) {
		menuBtn[i]->reset();
	}
	for(int i=0;i<pAMenuBtn.size();i++) {
		pAMenuBtn[i]->reset();	
	}
	for(int i=0;i<pVMenuBtn.size();i++) {
		pVMenuBtn[i]->reset();
	}
}

//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
	
	// this is where you setup all the pins and pin modes, etc
	for (int i = 0; i < 13; i++){
		//ard.sendDigitalPinMode(i, ARD_OUTPUT);
		ard.sendDigitalPinMode(i, ARD_INPUT);
	}
	
	ard.sendDigitalPinMode(13, ARD_OUTPUT);
	//ard.sendDigitalPinMode(2, ARD_INPUT);
	ard.sendAnalogPinReporting(0, ARD_ANALOG);	// AB: report data
	//ard.sendDigitalPinMode(11, ARD_PWM);		// on diecimelia: 11 pwm?*/
	
	bSetupArduino = true;
}

//--------------------------------------------------------------
void testApp::updateArduino(){
	
	// update the arduino, get any data or messages.
	ard.update();
	
	// do not send anything until the arduino has been set up
	if (bSetupArduino) {
		ard.sendDigital(13, ARD_HIGH);
		//ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
		//cout << ofToString(ard.getDigital(2));
		if(ard.getDigital(2) == 0) {
			//passiveInL.reset();
		}
	}
	
	
}

