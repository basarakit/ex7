/*
 *  ofxImageHolder.h
 *
 *  Created by basara on 16/04/2012.
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxImageSequence.h"

class ofxImageHolder : public ofBaseApp {
	public:
		ofxImageHolder();
	
		//load the image sequence
		void load(string prefix, string filetype, int startIndex, int endIndex, int numDigits);
		
	
	protected:
		ofxImageSequence seq;
		
	bool over;
	bool show;
	
};


