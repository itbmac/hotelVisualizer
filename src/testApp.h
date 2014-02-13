#pragma once

#include "ofMain.h"
#include "ofMesh.h"
#include "ofxCsv.h"

using namespace wng;


struct hotel {
    int stars; // 2
    int price; // 3
    float latitude; // 12
    float longitude; // 13
};


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
    ofxCsv csv;
    ofMesh hotelMesh;
    
    ofEasyCam camera;
    bool zoomRating = false, zoomPrice = false;
    
    int starsCol = 2;
    int priceCol = 3;
    int latitudeCol = 12;
    int longitudeCol = 13;
    
    int hotelCount = 0;
    vector<hotel> hotels;
};