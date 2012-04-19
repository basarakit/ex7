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

#include "ofxImageHolder.h"

ofxImageHolder::ofxImageHolder() {
	show = false;
	over = false;
	rev = false;
	pressed = false;
	playSubLoop = false;
}

ofxImageHolder::~ofxImageHolder() {

}

void ofxImageHolder::load(string _prefix, string _filetype,  int _startDigit, int _endDigit, int _numDigits, int _x, int _y, string _name) {
	prefix = _prefix;
	filetype = _filetype;
	startIndex = _startDigit;
	endIndex = _endDigit;
	numDigits = _numDigits;
	seq.loadSequence(prefix, filetype, startIndex, endIndex, numDigits);
	seq.setFrameRate(25);
	x = _x;
	y = _y;
	btnName = _name;
}

void ofxImageHolder::loadGlow(string _prefix, string _filetype,  int _startDigit, int _endDigit, int _numDigits) {
	gPrefix = _prefix;
	gFiletype = _filetype;
	gStartIndex = _startDigit;
	gEndIndex = _endDigit;
	gNumDigits = _numDigits;
	glow.loadSequence(gPrefix, gFiletype, gStartIndex, gEndIndex, gNumDigits);
	glow.setFrameRate(25);
}

void ofxImageHolder::reload() {
	seq.loadSequence(prefix, filetype, startIndex, endIndex, numDigits);
	glow.loadSequence(gPrefix, gFiletype, gStartIndex, gEndIndex, gNumDigits);
}

bool ofxImageHolder::play(bool loop, bool reverse) {
	if(show == true) {
		
		if(over == true) {
			playGlow(false);
		}
		
		if(loop == true) {//play the sequence in loop
			seq.getFrameForTime(ofGetElapsedTimef(), reverse)->draw(x,y);
		} else {
			if(reverse == true) {//play sequence once in reverse form
				if(seq.isStart() == false) {
					seq.getFrameForTime(ofGetElapsedTimef(), true)->draw(x,y);
				} else {
					rev = false;
					hideSeq();
					return true;
				}
			} else {// play sequence once in normal form
				if(seq.isEnd() == false) {
					seq.getFrameForTime(ofGetElapsedTimef(), false)->draw(x, y);
				} else {
					if(playSubLoop == true) {
						playGlow(true);
						
					} else {
						seq.getFrameAtPercent(1)->draw(x, y);
						return true;
					}
				}
			}			
		}
		return false;
	} return false;
}

void ofxImageHolder::playGlow(bool loop) {
	if(show == true) {
		if(loop == true) {
			glow.getFrameForTime(ofGetElapsedTimef(), false, true)->draw(x, y);
		} else {
			if(glow.isEnd() == false) {
				glow.getFrameForTime(ofGetElapsedTimef(), false)->draw(x, y);
			} else {
				over = false;
				seq.reset();
				rev = true;
			}
		}
	}
}

void ofxImageHolder::setPlaySubLoop() {
	playSubLoop = true;
}

void ofxImageHolder::showSeq() {
	show = true;
	seq.reset();
}

void ofxImageHolder::hideSeq() {
	show = false;
	seq.reset();
}

void ofxImageHolder::setOver() {
	pressed = true;
	over = true;
}

void ofxImageHolder::setRev(bool r) {
	seq.reset();
	rev = r;
}

void ofxImageHolder::setPressed(bool p) { pressed = p; }

void ofxImageHolder::reset() {
	seq.reset();
	seq.resetFrame();
	glow.reset();
	glow.resetFrame();
	show = false;
	over = false;
	rev = false;
}

void ofxImageHolder::unload() {
	seq.unloadSequence();
	glow.unloadSequence();
}

bool ofxImageHolder::isOver() {
	return over;
}

bool ofxImageHolder::isRev() {
	return rev;
}

bool ofxImageHolder::isShow() {
	return show;
}

bool ofxImageHolder::isPlaySubLoop() {
	return playSubLoop;
}

bool ofxImageHolder::isPressed() { return pressed; }

