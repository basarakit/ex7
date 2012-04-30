#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	

	
	mode = "menu";
	menuPressed = false;
	menuBtnPressed = false;
	backBtnPressed = false;
	nextBtnPressed = false;
	nextBtnPressing = false;
	backToCaseMenu = false;
	
	pressingTime = 0;
	
	//button position
	button1.set(204, 202); //left upper one
	button2.set(204, 340); //left middle one
	button3.set(204, 487); //left lower one
	button4.set(666, 202); //right upper one
	button5.set(666, 340); //right middle one
	button6.set(666, 487); //right lower one
	button7.set(666, 55);// right uppest one for back and next only
	
	casePos.set(110, 0);
	caseUPos.set(1024, 0);
	
	//image init
	
	//back and next button
	backBtn.load("icon/back/back_button_right_", "png", 0, 14, 5, button7.x, button7.y, "back");
	backBtn.loadGlow("icon/back/touch/back_button_right_touch_effect_", "png", 15, 29, 5);
	
	nextBtn.load("icon/next/next_button_right_", "png", 0, 14, 5, button7.x, button7.y, "next");
	nextBtn.loadGlow("icon/next/touch/next_button_right_touch_effect_", "png", 15, 29, 5);
	
	//passive button
	passiveInL.load("icon/passive/left/passive_design_button_left_", "png", 0, 14, 5, button1.x, button1.y, "passive");
	passiveInL.loadGlow("icon/passive/left/touch/passive_design_button_left_touch_effect_", "png", 15, 29, 5);
	
	passiveInR.load("icon/passive/right/passive_design_button_right_", "png", 0, 14, 5, button4.x, button4.y, "passive");
	passiveInR.loadGlow("icon/passive/right/touch/passive_design_button_right_touch_effect_", "png", 15, 29, 5);

	//active button
	activeInL.load("icon/active/left/active_systems_button_left_", "png", 0, 14, 5, button2.x, button2.y, "active");
	activeInL.loadGlow("icon/active/left/touch/active_systems_button_left_touch_effects_", "png", 15, 29, 5);

	activeInR.load("icon/active/right/active_systems_button_right_", "png", 0, 14, 5, button5.x, button5.y, "active");
	activeInR.loadGlow("icon/active/right/touch/active_systems_button_right_touch_effect_", "png", 15, 29, 5);
	
	//renewable button
	renewInL.load("icon/renewable/left/renewable_energy_button_left_", "png", 0, 14, 5, button3.x, button3.y, "renew");
	renewInL.loadGlow("icon/renewable/left/touch/renewable_energy_button_left_touch_effect_", "png", 15, 29, 5);
	
	renewInR.load("icon/renewable/right/renewable_energy_button_right_", "png", 0, 14, 5, button6.x, button6.y, "renew");
	renewInR.loadGlow("icon/renewable/right/touch/renewable_energy_button_right_touch_effect_", "png", 15, 29, 5);
	
	menuBtn.push_back(&passiveInL);
	menuBtn.push_back(&activeInL);
	menuBtn.push_back(&renewInL);
	menuBtn.push_back(&passiveInR);
	menuBtn.push_back(&activeInR);
	menuBtn.push_back(&renewInR);
	
	//ventilation button
	ventilationInL.load("icon/passive/ventilation/left/ventilation_button_left_", "png", 0, 14, 5, button1.x, button1.y, "ventilation");
	ventilationInL.loadGlow("icon/passive/ventilation/left/touch/ventilation_button_left_touch_effect_", "png", 15, 29, 5);
	
	ventilationInR.load("icon/passive/ventilation/right/ventilation_button_right_", "png", 0, 14, 5, button4.x, button4.y, "ventilation");
	ventilationInR.loadGlow("icon/passive/ventilation/right/touch/ventilation_button_right_touch_effect_", "png", 15, 29, 5);
	
	//solar button
	solarInL.load("icon/passive/solar/left/solar_control_button_left_", "png", 0, 14, 5, button2.x, button2.y, "solar");
	solarInL.loadGlow("icon/passive/solar/left/touch/solar_control_button_left_touch_effect_", "png", 15, 29, 5);
	
	solarInR.load("icon/passive/solar/right/solar_control_button_right_", "png", 0, 14, 5, button5.x, button5.y, "solar");
	solarInR.loadGlow("icon/passive/solar/right/touch/solar_control_button_right_touch_effect_", "png", 15, 29, 5);

	//light button
	lightInL.load("icon/passive/light/left/light_button_left_", "png", 0, 14, 5, button3.x, button3.y, "light");
	lightInL.loadGlow("icon/passive/light/left/touch/light_button_left_touch_effect_", "png", 15, 29, 5);
	
	lightInR.load("icon/passive/light/right/light_button_right_", "png", 0, 14, 5, button6.x, button6.y, "light");
	lightInR.loadGlow("icon/passive/light/right/touch/light_button_right_touch_effect_", "png", 15, 29, 5);
	
	pAMenuBtn.push_back(&ventilationInL);
	pAMenuBtn.push_back(&solarInL);
	pAMenuBtn.push_back(&lightInL);
	pAMenuBtn.push_back(&ventilationInR);
	pAMenuBtn.push_back(&solarInR);
	pAMenuBtn.push_back(&lightInR);
	
	//passive ventilation button
	earthCoolingBtn.load("icon/passive/ventilation/earthcooling/earth_cooling_button_", "png", 0, 14, 5, button1.x, button1.y, "pVEarth");
	earthCoolingBtn.loadGlow("icon/passive/ventilation/earthcooling/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	windCatcherBtn.load("icon/passive/ventilation/wind/ventilation_button_right_", "png", 0, 14, 5, button5.x, button5.y, "pVWind");
	windCatcherBtn.loadGlow("icon/passive/ventilation/wind/touch/ventilation_button_right_touch_effect_", "png", 15, 29, 5);
	
	ventilationLayoutBtn.load("icon/passive/ventilation/layout/ventilation_button_right_", "png", 0, 14, 5, button6.x, button6.y, "pVLayout");
	ventilationLayoutBtn.loadGlow("icon/passive/ventilation/layout/touch/ventilation_button_right_touch_effect_", "png", 15, 29, 5);
	
	pVMenuBtn.push_back(&earthCoolingBtn);
	pVMenuBtn.push_back(&ventilationLayoutBtn);
	pVMenuBtn.push_back(&windCatcherBtn);
	
	//------------------------------------------------
	
	//passive light button
	lightPipeBtn.load("icon/passive/light/lightPipe/earth_cooling_button_", "png", 0, 14, 5, button1.x, button1.y, "pLPipe");
	lightPipeBtn.loadGlow("icon/passive/light/lightPipe/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	lightShelfBtn.load("icon/passive/light/lightShelf/earth_cooling_button_", "png", 0, 14, 5, button5.x, button5.y, "pLShelf");
	lightShelfBtn.loadGlow("icon/passive/light/lightShelf/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	northGlazingBtn.load("icon/passive/light/northGlazing/earth_cooling_button_", "png", 0, 14, 5, button6.x, button6.y, "pLNorth");
	northGlazingBtn.loadGlow("icon/passive/light/northGlazing/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	pLMenuBtn.push_back(&lightPipeBtn);
	pLMenuBtn.push_back(&lightShelfBtn);
	pLMenuBtn.push_back(&northGlazingBtn);
	
	//------------------------------------------------
	
	//passive solar button
	externalShadingBtn.load("icon/passive/solar/externalShading/earth_cooling_button_", "png", 0, 14, 5, button1.x, button1.y, "pSExternal");
	externalShadingBtn.loadGlow("icon/passive/solar/externalShading/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	roofBtn.load("icon/passive/solar/roof/earth_cooling_button_", "png", 0, 14, 5, button5.x, button5.y, "pSRoof");
	roofBtn.loadGlow("icon/passive/solar/roof/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	shadeBtn.load("icon/passive/solar/shade/earth_cooling_button_", "png", 0, 14, 5, button6.x, button6.y, "pSShade");
	shadeBtn.loadGlow("icon/passive/solar/shade/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	windowBtn.load("icon/passive/solar/window/earth_cooling_button_", "png", 0, 14, 5, button2.x, button2.y, "pSWindow");
	windowBtn.loadGlow("icon/passive/solar/window/touch/earth_cooling_button_touch_effect_", "png", 15, 29, 5);
	
	pSMenuBtn.push_back(&externalShadingBtn);
	pSMenuBtn.push_back(&roofBtn);
	pSMenuBtn.push_back(&shadeBtn);
	pSMenuBtn.push_back(&windowBtn);
	
	//------------------------------------------------

	background.loadImage("bgTmp.png");

	//passive ventilation case-------------------------
	
	earth.load("case/passive/ventilation/earth/AnimationA2_P_V_Earth_Cooling.mov", casePos.x, casePos.y, "pVEarth");
	layout.load("case/passive/ventilation/layout/AnimationA2_P_V_ventilated_layout.mov", casePos.x, casePos.y, "pVLayout");
	wind.load("case/passive/ventilation/wind/AnimationA2_P_V_wind_catcher.mov", casePos.x, casePos.y, "pVWind");
	
	pVCase.push_back(&earth);
	pVCase.push_back(&layout);
	pVCase.push_back(&wind);
	
	earthU.load("case/passive/ventilation/earth/AnimationB_P_V_EarthCooling.mov", caseUPos.x, caseUPos.y, "pVEarthU");
	layoutU.load("case/passive/ventilation/layout/AnimationB_P_V_ventilated_layout.mov", caseUPos.x, caseUPos.y, "pVLayoutU");
	windU.load("case/passive/ventilation/wind/AnimationB_P_V_wincatcher.mov", caseUPos.x, caseUPos.y, "pVWindU");
	
	pVCaseU.push_back(&earthU);
	pVCaseU.push_back(&layoutU);
	pVCaseU.push_back(&windU);
	
	//--------------------------------------------------
	
	//passive light case-------------------------
	
	pipe.load("case/passive/light/lightPipe/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pLPipe");
	shelf.load("case/passive/light/lightShelf/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pLShelf");
	north.load("case/passive/light/northGlazing/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pLNorth");
	
	pLCase.push_back(&pipe);
	pLCase.push_back(&shelf);
	pLCase.push_back(&north);
	
	pipeU.load("case/passive/light/lightPipe/AnimationA2_A_S_active_skylight.mov", caseUPos.x, caseUPos.y, "pLPipeU");
	shelfU.load("case/passive/light/lightShelf/AnimationA2_A_S_active_skylight.mov", caseUPos.x, caseUPos.y, "pLShelfU");
	northU.load("case/passive/light/northGlazing/AnimationA2_A_S_active_skylight.mov", caseUPos.x, caseUPos.y, "pLNorthU");
	
	pLCaseU.push_back(&pipeU);
	pLCaseU.push_back(&shelfU);
	pLCaseU.push_back(&northU);
	
	//--------------------------------------------------
	
	//passive solar case-------------------------
	
	external.load("case/passive/solar/externalShading/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pSExternal");
	roof.load("case/passive/solar/roof/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pSRoof");
	shade.load("case/passive/solar/shade/AnimationA2_P_S_heat_reflecting_shade.mov", casePos.x, casePos.y, "pSShade");
	glazing.load("case/passive/solar/glazing/AnimationA2_P_S_High_Performance_glazing.mov", casePos.x, casePos.y, "pSGlazing");
	
	pSCase.push_back(&external);
	pSCase.push_back(&roof);
	pSCase.push_back(&shade);
	pSCase.push_back(&glazing);
	
	externalU.load("case/passive/solar/externalShading/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "pSExternalU");
	roofU.load("case/passive/solar/roof/AnimationB_P_S_Insulated_Roof.mov", casePos.x, casePos.y, "pSRoofU");
	shadeU.load("case/passive/solar/shade/AnimationB_P_S_Heat_reflecting_shade.mov", casePos.x, casePos.y, "pSShadeU");
	glazingU.load("case/passive/solar/glazing/AnimationB_P_S_High_Performance_Glazing.mov", casePos.x, casePos.y, "pSGlazingU");
	
	pSCaseU.push_back(&externalU);
	pSCaseU.push_back(&roofU);
	pSCaseU.push_back(&shadeU);
	pSCaseU.push_back(&glazingU);
	
	//--------------------------------------------------
	
	
	//active ventilation case-------------------------
	
	fan.load("case/active/ventilation/fan/AnimationA2_A_V_high_volume_low_speed_fan.mov", casePos.x, casePos.y, "aVFan");
	hvac.load("case/active/ventilation/hvac/AnimationA2_A_V_HVAC.mov", casePos.x, casePos.y, "aVHVAC");

	aVCase.push_back(&fan);
	aVCase.push_back(&hvac);

	fanU.load("case/active/ventilation/fan/AnimationB_A_V_high_volume_low_speed_fan.mov", casePos.x, casePos.y, "aVFanU");
	hvacU.load("case/active/ventilation/hvac/AnimationB_A_V_HVAC.mov", casePos.x, casePos.y, "aVHVACU");
	
	aVCaseU.push_back(&fanU);
	aVCaseU.push_back(&hvacU);
	
	//--------------------------------------------------
	
	//avtive light case-------------------------
	
	management.load("case/active/light/management/AnimationA2_A_L_Interlligent_Light Management.mov", casePos.x, casePos.y, "aLManagement");
	
	aLCase.push_back(&management);
	
	managementU.load("case/active/light/management/AnimationA2_A_L_Interlligent_Light Management.mov", casePos.x, casePos.y, "aLManagementU");
	
	aLCaseU.push_back(&managementU);
	
	//--------------------------------------------------
	
	//active solar case-------------------------
	
	skylight.load("case/active/solar/skylight/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "aSSkylight");
	
	aSCase.push_back(&skylight);
	
	skylightU.load("case/active/solar/skylight/AnimationA2_A_S_active_skylight.mov", casePos.x, casePos.y, "aSSkylightU");
	
	aSCaseU.push_back(&skylightU);
	
	//--------------------------------------------------
	
	
	//renewable case-------------------------
	
	bio.load("case/renewable/bio/AnimationA2_R_bio_diesel.mov", casePos.x, casePos.y, "renewBio");
	photovoltaic.load("case/renewable/photovoltaic/AnimationA2_R_Photovoltaic.mov", casePos.x, casePos.y, "renewPhoto");
	
	renewCase.push_back(&bio);
	renewCase.push_back(&photovoltaic);
	
	bioU.load("case/renewable/bio/AnimationB_R_bio_disel.mov", casePos.x, casePos.y, "renewBioU");
	photovoltaicU.load("case/renewable/photovoltaic/AnimationB_R_Photovoltaic.mov", casePos.x, casePos.y, "renewPhotoU");
	
	renewCaseU.push_back(&bioU);
	renewCaseU.push_back(&photovoltaicU);
	
	//--------------------------------------------------
	
	
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
	for(int i=0;i<pVCase.size();i++) {
		if(pVCase[i]->isShow() == true) {
			pVCase[i]->idleMovie();
			pVCaseU[i]->idleMovie();
		}
	}
	
	for(int i=0;i<pLCase.size();i++) {
		if(pLCase[i]->isShow() == true) {
			pLCase[i]->idleMovie();
			pLCaseU[i]->idleMovie();
		}
	}
	
	for(int i=0;i<pSCase.size();i++) {
		if(pSCase[i]->isShow() == true) {
			pSCase[i]->idleMovie();
			pSCaseU[i]->idleMovie();
		}
	}
	
	string str = "framerate is ";                       
	str += ofToString(ofGetFrameRate(), 2)+"fps"; 
	ofSetWindowTitle(str);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofDisableAlphaBlending();
	ofSetColor(255);
	//background.draw(0,0, 1024, 768);
	ofBackground(0);
	
	for(int i=0;i<pVCase.size();i++) {
		if(pVCase[i]->isShow() == true) {
			pVCase[i]->draw();
			pVCaseU[i]->draw();
		}
	}
	
	for(int i=0;i<pLCase.size();i++) {
		if(pLCase[i]->isShow() == true) {
			pLCase[i]->draw();
			pLCaseU[i]->draw();
		}
	}
	
	for(int i=0;i<pSCase.size();i++) {
		if(pSCase[i]->isShow() == true) {
			pSCase[i]->draw();
			pSCaseU[i]->draw();
		}
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
					if(menuBtn[i]->isPressed() == true) {//check the pressed button is which one
						if(menuBtn[i]->btnName == "active" || menuBtn[i]->btnName == "passive") {
							showPassiveAndActiveSubMenu(menuBtn[i]->btnName);
							showBackBtn();
						} else if(menuBtn[i]->btnName == "renewable" ) {
							
						}
					}
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
						if(pAMenuBtn[i]->isPressed() == true) {
							if(pAMenuBtn[i]->btnName == "ventilation" && mode == "passive") {
								showPVMenu();
								break;
							} else if(pAMenuBtn[i]->btnName == "solar" && mode == "passive") {
								showPSMenu();
								break;
							} else if(pAMenuBtn[i]->btnName == "light" && mode == "passive") {
								showPLMenu();
								break;
							} else if(pAMenuBtn[i]->btnName == "ventilation" && mode == "active") {
								break;
							} else if(pAMenuBtn[i]->btnName == "solar" && mode == "active") {
								break;
							} else if(pAMenuBtn[i]->btnName == "light" && mode == "active") {
								break;
							}
						} else {
							showMenu();
							break;
						}
					}
				}
			} 
		}
	}
	
	
	//passive ventilation
	if(mode == "pV" || mode == "pVEarth" || mode == "pVLayout" || mode == "pVWind") {
		menuRender(pVMenuBtn, pVCase, pVCaseU, mode);
		//for(int i=0;i<pVMenuBtn.size();i++) {
//			if(pVMenuBtn[i]->isShow() == true) {
//				if(pVMenuBtn[i]->isRev() == false) {//when one of button start to play
//					if(menuBtnPressed == true && pVMenuBtn[i]->isPressed() == false) pVMenuBtn[i]->setRev();//set other button play reverse
//					pVMenuBtn[i]->play(false, false);
//				} else {//one of button start to play reverse 
//					if(menuBtnPressed == false) menuBtnPressed = true;
//					if(backBtnPressed == true) {
//						if(pVMenuBtn[i]->play(false, true) == true) {
//							showPassiveAndActiveSubMenu("passive");
//							backBtn.showSeq();
//							backBtnPressed = false;
//							break;
//						}
//					} else {
//						if(pVMenuBtn[i]->isPressed() == true) {//check which one clicked
//							pVMenuBtn[i]->setRev(false);//keep the pressed button not out
//							hideBackBtn();
//							if(pVMenuBtn[i]->play(false, false) == true) {
//								//case play here
//								if(mode == "pVEarth") pVCase[0]->showCase();
//								else if(mode =="pVLayout") pVCase[1]->showCase();
//								else if(mode =="pVWind") pVCase[2]->showCase();
//							}
//						} else {
//							pVMenuBtn[i]->play(false, true);
//						}
//					}
//				}
//			}
//		}
	}
	
	
	//passive light
	if(mode == "pL" || mode == "pLPipe" || mode == "pLShelf" || mode == "pLNorth") {
		menuRender(pLMenuBtn, pLCase, pLCaseU, mode);
	}
	
	//passive solar
	if(mode == "pS" || mode == "pSExternal" || mode == "pSRoof" || mode == "pSShade" || mode == "pSWindow") {
		menuRender(pSMenuBtn, pSCase, pSCaseU, mode);
	}
	
	//back button show here
	if(backBtn.isShow() == true) {
		if(backBtn.isRev() == false) {
			backBtn.play(false, false);
		} else {
			if(backBtn.isPressed() == true) {
				backBtn.setPressed(false);
				if(mode == "active" || mode == "passive" || mode == "renewable") {
					hidePassiveAndActiveSubMenu();
				} else if(mode == "pV") {
					hidePVMenu("all");
					backBtn.setRev(false);
				} else if(mode == "pL") {
					hidePLMenu("all");
					backBtn.setRev(false);
				} else if(mode == "pS") {
					hidePSMenu("all");
					backBtn.setRev(false);
				}
			}
			//into case menu
			if(backBtn.play(false, true) == true) {
				if(mode == "pVEarth" || mode == "pVLayout" || mode == "pVWind" || 
				   mode == "pSExternal" || mode == "pSRoof" || mode == "pSShade" || mode == "pSWindow" ||
				   mode == "pLPipe" || mode == "pLShelf" || mode == "pLNorth") {
					showNextBtn();
				}
			}
		}
	}
	
	//next button show here
	if(nextBtn.isShow() == true) {
		if(nextBtn.isRev() == false) {
			nextBtn.play(false, false);
			if(nextBtnPressed == true && backToCaseMenu == false) {
				nextBtnPressed = false;
				if (mode == "pVEarth") {
					nextCase(pVMenuBtn, pVCase, pVCaseU, "pVLayout", 0, 1);
				} else if (mode == "pVLayout") {
					nextCase(pVMenuBtn, pVCase, pVCaseU, "pVWind", 1, 2);
				} else if (mode == "pVWind") {
					nextCase(pVMenuBtn, pVCase, pVCaseU, "pVEarth", 2, 0);
				}
			}
		} else {//start to play reverse
			if(backToCaseMenu == true) {
				backToCaseMenu = false;
				if(mode == "pVEarth") {
					showPVMenu(mode);
				}
			}
			if(nextBtn.play(false, true) == true) {
				nextBtnPressed = false;
				showBackBtn();
			}
		}
	}

	ofDisableAlphaBlending();
	
	ofSetColor(0, 0, 0);
	ofRect(914, 0, 2, 768);
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
	if(key == 'q') {//left renewable button
		if(mode == "menu") {
			menuBtn[0]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[0]->setOver();
		} else if(mode == "active") {
			mode = "AVentilation";
			pAMenuBtn[0]->setOver();
		} else if(mode == "pV") {
			pVMenuBtn[0]->setOver();
			mode = "pVEarth";
		} else if(mode == "pS") {
			pSMenuBtn[0]->setOver();
			mode = "pSExternal";
		}
	} else if(key == 'a') {//left active button
		if(mode == "menu") {
			menuBtn[1]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[1]->setOver();
		} else if(mode == "active") {
			mode = "ASolar";
			pAMenuBtn[1]->setOver();
		} 
	} else if(key == 'z') {//left passive button
		if(mode == "menu") {
			menuBtn[2]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[2]->setOver();
		} else if(mode == "active") {
			mode = "ALight";
			pAMenuBtn[2]->setOver();
		} 
	} else if(key =='o') {//right renewable button
		if(mode == "menu") {
			menuBtn[3]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[3]->setOver();
		} else if(mode == "active") {
			mode = "AVentilation";
			pAMenuBtn[3]->setOver();
		} 
	} else if(key == 'k') {//right active button
		if(mode == "menu") {
			menuBtn[4]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[4]->setOver();
		} else if(mode == "active") {
			mode = "ASolar";
			pAMenuBtn[4]->setOver();
		} else if(mode == "pV") {
			pVMenuBtn[2]->setOver();
			mode = "pVWind";
		}
	} else if(key == 'm') {//right passive button
		if(mode == "menu") {
			menuBtn[5]->setOver();
		} else if(mode == "passive") {
			pAMenuBtn[5]->setOver();
		} else if(mode == "active") {
			mode = "ALight";
			pAMenuBtn[5]->setOver();
		}  else if(mode == "pV") {
			pVMenuBtn[1]->setOver();
			mode = "pVLayout";
		}
	} else if(key == 's') {
		
	} else if(key == 'i') {
		if(backBtn.isShow()) {
			backBtn.setOver();
			backBtnPressed = true;
		}
		if(nextBtn.isShow()) {
			nextBtnPressing = false;
			if(backToCaseMenu == false) nextBtn.setOver(true);
			else nextBtn.setOver();
			nextBtnPressed = true;
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
void testApp::keyPressed(int key){
	if(key == 'i') {
		if(nextBtn.isShow()) {
			if(!nextBtnPressing) {
				nextBtnPressing = true;
				pressingTime = ofGetElapsedTimef();
			} else {
				int tmpTime = ofGetElapsedTimef() - pressingTime;
				if(tmpTime >= 2.0) backToCaseMenu = true;
				else backToCaseMenu = false;
			}
		}
	}
	
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

void testApp::nextCase(vector<ofxImageHolder*> btn, vector<ofxVideoHolder*> movie, vector<ofxVideoHolder*> movieU, string m, int s, int d) {
	mode = m;
	movie[s]->reset();
	movieU[s]->reset();
	btn[s]->setPressed(false);
	btn[s]->setRev();
	btn[d]->reset();
	btn[d]->setPressed(true);
	btn[d]->showSeq();
}

void testApp::menuRender(vector<ofxImageHolder*> btn, vector<ofxVideoHolder*> movie, vector<ofxVideoHolder*> movieU, string m) {
	for(int i=0;i<btn.size();i++) {
		if(btn[i]->isShow() == true) {
			if(btn[i]->isRev() == false) {//when one of button start to play
				if(menuBtnPressed == true && btn[i]->isPressed() == false) btn[i]->setRev();//set other button play reverse
				if(btn[i]->play(false, false) == true && btn[i]->isPressed() == true) {
					if(movie[i]->isShow() == false) movie[i]->showCase();
					if(movieU[i]->isShow() == false) movieU[i]->showCase();
				}
			} else {//one of button start to play reverse 
				if(menuBtnPressed == false) menuBtnPressed = true;
				if(backBtnPressed == true) {
					if(btn[i]->play(false, true) == true) {
						showPassiveAndActiveSubMenu("passive");
						backBtn.showSeq();
						backBtnPressed = false;
						break;
					}
				} else {
					if(btn[i]->isPressed() == true) {//check which one clicked
						btn[i]->setRev(false);//keep the pressed button not out
						hideBackBtn();
						btn[i]->play(false, false);
						//if(btn[i]->play(false, false) == true) {
//							//case play here
//							//movie[i]->showCase();
//							//movieU[i]->showCase();
//						}
					} else {
						btn[i]->play(false, true);
					}
				}
			}
		}
	}
}

void testApp::showMenu() {
	mode = "menu";
	resetBtn();
	resetCase();
	for(int i=0;i<menuBtn.size();i++) {
		menuBtn[i]->showSeq();
	}
}

void testApp::showPassiveAndActiveSubMenu(string name) {
	mode = name;
	menuPressed = false;
	menuBtnPressed = false;
	for(int i=0;i<pAMenuBtn.size();i++) {
		pAMenuBtn[i]->reset();
		pAMenuBtn[i]->showSeq();
	}
	
}

void testApp::showPVMenu(string name) {
	menuBtnPressed = false;
	mode = "pV";
	for(int i=0;i<pVMenuBtn.size();i++) pVMenuBtn[i]->setPressed(false);
	if(name == "all") {
		for(int i=0;i<pVMenuBtn.size();i++) {
			pVMenuBtn[i]->reset();
			pVMenuBtn[i]->showSeq();
		}
	} else {//check which button do not need play animation
		for(int i=0;i<pVMenuBtn.size();i++) {
			if(pVMenuBtn[i]->btnName != name) {
				pVMenuBtn[i]->reset();
				pVMenuBtn[i]->showSeq();
			}
		}
	}
	resetCase();
}

void testApp::showPLMenu() {
	menuBtnPressed = false;
	mode = "pL";
	for(int i=0;i<pLMenuBtn.size();i++) {
		pLMenuBtn[i]->reset();
		pLMenuBtn[i]->showSeq();
	}
	
}

void testApp::showPSMenu() {
	menuBtnPressed = false;
	mode = "pS";
	for(int i=0;i<pSMenuBtn.size();i++) {
		pSMenuBtn[i]->reset();
		pSMenuBtn[i]->showSeq();
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
		for(int i=0;i<pVMenuBtn.size();i++) {
			pVMenuBtn[i]->setRev();
		}
	}
}

void testApp::hidePLMenu(string name) {
	if(name == "all") {
		for(int i=0;i<pLMenuBtn.size();i++) {
			pLMenuBtn[i]->setRev();
		}
	}
}

void testApp::hidePSMenu(string name) {
	if(name == "all") {
		for(int i=0;i<pSMenuBtn.size();i++) {
			pSMenuBtn[i]->setRev();
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
	backBtnPressed = false;
	nextBtnPressed = false;
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
	for(int i=0;i<pLMenuBtn.size();i++) {
		pLMenuBtn[i]->reset();
	}
	for(int i=0;i<pSMenuBtn.size();i++) {
		pSMenuBtn[i]->reset();
	}
}

void testApp::resetCase() {
	for(int i=0;i<pVCase.size();i++) {
		pVCase[i]->reset();
		pVCaseU[i]->reset();
	}
	for(int i=0;i<pSCase.size();i++) {
		pSCase[i]->reset();
		pSCaseU[i]->reset();
	}
	for(int i=0;i<pLCase.size();i++) {
		pLCase[i]->reset();
		pLCaseU[i]->reset();
	}
}

void testApp::resetAll() {
	mode = "menu";
	resetBtn();
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

