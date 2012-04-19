/*
 * Created by James George, http://www.jamesgeorge.org
 * in collaboration with Flightphase http://www.flightphase.com
 * and this class is created by basara, http://xex.hk for the implementation
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------
 *
 *  ofxImageSequence is a class for easily loading a series of image files
 *  and accessing them like you would frames of a movie.
 *  
 *  This class loads only textures to the graphics card and does not store pixel data in memory. This helps with
 *  fast, random access drawing of seuqences
 *  
 *  Why would you use this instead of a movie file? A few reasons,
 *  If you want truly random frame access with no lag on large images, ofxImageSequence is a good way to go
 *  If you need a movie with alpha channel the only readily available codec is Animation (PNG) which is slow at large resolutions, so this class can help with that
 *  If you want to easily access frames based on percents this class makes that easy
 * 
 * //TODO: Extend ofBaseDraws
 * //TODO: experiment with storing pixels intead of textures and doing upload every frame
 * //TODO: integrate ofDirectory to API
 */

#pragma once

#include "ofMain.h"
#include "ofxImageSequence.h"

class ofxImageHolder : public ofBaseApp {
public:
	ofxImageHolder();
	~ofxImageHolder();
	
	//load the image sequence
	void load(string prefix, string filetype, int startIndex, int endIndex, int numDigits, int _x, int _y, string _name);
	void loadGlow(string prefix, string filetype, int startIndex, int endIndex, int numDigits);
	
	//play the sequence
	//void play(bool loop, bool reverse);
	bool play(bool loop, bool reverse);//return true when the sequence play finish
	void playGlow(bool loop);//play the sub sequence
	
	void unload();
	void reload();
	
	void reset();
	void showSeq();//show the sequence
	void hideSeq();//hide the sequence
	void setRev(bool r=true);//set reverse
	void setOver();//button touched
	void setPlaySubLoop();//play the sub loop
	void setPressed(bool p);
	bool isPlaySubLoop();//return play sub loop state
	bool isOver();//return over state
	bool isRev();//return rev state
	bool isShow();//return show state
	bool isPressed();
	
	string btnName;
	
	
protected:
	ofxImageSequence seq;
	ofxImageSequence glow;
	
	bool rev;
	bool over;
	bool show;
	bool playSubLoop;
	bool pressed;
	
	string prefix;
	string filetype;
	int startIndex;
	int endIndex;
	int numDigits;
	
	string gPrefix;
	string gFiletype;
	int gStartIndex;
	int gEndIndex;
	int gNumDigits;
	
	int x;
	int y;
};


