
#include "testApp.h"
#include "ofMesh.h"
#include "ofxCsv.h"


//--------------------------------------------------------------
void testApp::setup(){
	
    csv.loadFile(ofToDataPath("hotelsbase.csv"), "~");
    
    int hotelEntries = csv.numRows;
    int hotelFields = csv.data[0].size();
    
    hotelMesh.setMode(OF_PRIMITIVE_POINTS);
    
	for (int i = 1; i < hotelEntries; i++) {
        int stars = -1;
        if (csv.data[i][starsCol] != "")
        {
            stars = csv.getInt(i, starsCol);
        }
        int price = csv.getInt(i, priceCol);
        float latitude = csv.getFloat(i, latitudeCol);
        float longitude = csv.getFloat(i, longitudeCol);
        
        latitude = ofMap(latitude, 90, -90, 0, 768);
        longitude = ofMap(longitude, -180, 180, 0, 1024);
        
        hotel currentHotel = {
            stars,
            price,
            latitude,
            longitude,
        };
        
        
        hotels.push_back(currentHotel);
        
        ofVec3f currentHotelPoint(longitude, latitude, stars);
        hotelMesh.addVertex(currentHotelPoint);
        
        hotelCount++;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    int zoom = 1;
    if (zoomRating)
        zoom = 15;
    
    hotelMesh.clear();
    for(int i = 0; i != hotels.size(); i++) {
        hotel h = hotels[i];
        ofVec3f currentHotelPoint(h.longitude, h.latitude, zoom * h.stars);
        
        if (zoomPrice)
            currentHotelPoint.set(h.longitude, h.latitude, (1/(zoom * zoom)) * h.price);
        
        if (zoomRating || zoomPrice)
             hotelMesh.addVertex(currentHotelPoint);
        else
        {
            if (h.stars != -1)
                hotelMesh.addVertex(currentHotelPoint);
            else
                continue;
        }
        
        ofColor c(0,0,255);
        
        if (h.stars != -1)
            c.set(255 - h.stars * 51, h.stars * 51, 0);
        
        hotelMesh.addColor(c);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor centerColor = ofColor(38, 105, 117);
    ofColor edgeColor = ofColor(28, 27, 43);
    ofBackground(0x000000);
    
    camera.begin();
    camera.setScale(1, -1, .8);
    ofPushMatrix();
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    hotelMesh.draw();
    ofPopMatrix();
    camera.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
        zoomPrice = true;
    }
    else {
        zoomRating = true;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	zoomRating = false;
    zoomPrice = false;
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

