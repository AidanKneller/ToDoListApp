#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    
    ofGLFWWindowSettings settings;
    settings.setSize(850, 708);
    settings.resizable = false;
    
    shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
    shared_ptr<ofApp> app(new ofApp());
    
    ofRunApp(window, app);
    ofRunMainLoop();

}
