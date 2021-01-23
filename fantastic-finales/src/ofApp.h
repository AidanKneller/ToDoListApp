#pragma once

#include "ofMain.h"
#include "inclusions.h"
#include "Dashboard.hpp"
#include "List.hpp"
#include "Task.hpp"
#include "ofxTextInputField.h"

/*  WORK FLOW
 X List deletion
 X Task completion
 - Load from JSON
 X Start from New
 - Cursor limit?
 - Replace hard coded integers for scalability or make sure it cannot be scaled
 - Update proposal and put into Github Fantastic Finales
*/

// allign the taks and check buttons with Pascale

class ofApp : public ofBaseApp{
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    Dashboard dash;
};

// Make tasks in completed view clickable?
