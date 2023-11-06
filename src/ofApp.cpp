#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // boolean variables to change characters depending on keyPressed
    feeding = false;
    overfeed = false;
    tickling = false;
    peting = false;
    
    // the value of width and height here are float numbers
    x = (ofGetWidth()/2);
    y = (ofGetHeight()/2);
    
    // variables that hold integer number
    feed_max = 600; // 10 seconds at 60 frames per second
    feed = 1;
    width = 100;
    height = 100;
    angle_mov = 45; // angle of the ears
    body_width = 240; // start value based on drawing
    interval = 0;
   
    // load sounds
    tickle_sound.load("tickle.mp3");
    feed_sound.load("feed.mp3");
    pet_sound.load("pet.mp3");
 
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (feeding && feed < feed_max){
        
        // increase the rotation angle for spin
        angle_mov += 5;
        
        // increase width for growing effect
        body_width += 0.05;
        
        // increment feed by 1 every frame (1/60 seconds per frame at 60 frames per second)
        feed += 1;
    }
    
    // Check if feed has reached max value
    if (feed >= feed_max) {
        
        overfeed = true; // shows overfeed drawing
        feeding = false;
        
    } else {
        overfeed = false;
    }
    
    if (tickling){
        
        // adapted the blink chalenge solution to be trigged by tickling
        // interval is used to make eyes blinking at random position
        interval = ofRandom(50, 100);
     
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(77, 180, 225); // yellow
    ofSetCircleResolution(60);
    
                           /*  **** HOW TO INTERACT ****  */
    ofFill();
    ofSetColor(255, 0, 0); // Red
    ofDrawBitmapString("**** FURBY ****", 620, 130);
    ofDrawBitmapString(" press p to pet", 50, 150);
    ofDrawBitmapString(" press t to tickle", 50, 170);
    ofDrawBitmapString(" press f to feed", 50, 190);
    ofDrawBitmapString("  BE CAREFULL.... if overfeed, furby gets angry!!", 50, 250);
    
                          /*  **** VARIABLES' DRAWING ****  */
    if(feeding){
        
        // Feet
        ofFill();
        ofSetColor(77, 225, 122);// Green
        ofDrawEllipse(x + 125, y + 45, width - 40, height - 50); // Left
        ofDrawEllipse(x + 225, y + 45, width - 40, height - 50); // Right
        
        // Ear - out left
        ofPushMatrix(); // save current state
        ofTranslate(x + 70, y - 200); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // Green
        ofDrawEllipse(0, 0, width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - out right
        ofPushMatrix(); // save current state
        ofTranslate(x + 270, y - 200); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // Green
        ofDrawEllipse(0, 0,width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - in left
        ofPushMatrix(); // save current state
        ofTranslate(x + 70, y - 200); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // Blue
        ofDrawEllipse(0, 0, width - 30, height - 10);
        ofPopMatrix(); // restore state
        
        // Ear - in right
        ofPushMatrix(); // save current state
        ofTranslate(x + 270, y - 200); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // Blue
        ofDrawEllipse(0, 0,width -30, height - 10);
        ofPopMatrix(); // restore state
        
        // Body
        ofFill();
        ofSetColor(225, 77, 180); // Pink
        ofDrawEllipse(x + 175, y - 75, body_width, height + 140);
        
        //Eyes - outside
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(x + 150, y - 110, width - 15, height - 30); // left out
        ofDrawEllipse(x + 210, y - 110, width - 15, height - 30); // right out
        
        //Eyes - inside
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(x + 150, y - 110, width - 60,height - 60); // left in
        ofDrawEllipse( x + 210, y - 110, width - 60,height - 60); // right in
        
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(x + 150, y - 110,width - 80, height - 80); // left in
        ofDrawEllipse(x + 210, y - 110,width - 80, height - 80); // right in
        
        // Mouth
        ofFill();
        ofSetColor(225, 196, 77); // yellow
        ofDrawEllipse(x + 180, y - 50, width - 40, height - 40);
        
        // Mouth open
        ofFill();
        ofSetColor(255, 0, 0);
        ofDrawEllipse(x + 180, y - 50, width - 40, height - 70);
        
        
    } else if (overfeed){
        
        // Message
        ofFill();
        ofSetColor(255, 0, 0); // red
        ofDrawBitmapString("RRRRRRRR!", x + 150, y + 150);
        
        // Feet
        ofFill();
        ofSetColor(77, 225, 122);// green
        ofDrawEllipse(x + 125, y + 45, width - 40, height - 50); // left
        ofDrawEllipse(x + 225, y + 45, width - 40, height - 50); // right
        
        // Ear - out left
        ofPushMatrix(); // save current state
        ofTranslate(x + 105, y - 175); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0, width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - out right
        ofPushMatrix(); // save current state
        ofTranslate(x + 255, y - 170); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0,width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - in left
        ofPushMatrix(); // save current state
        ofTranslate(x + 105, y - 175); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0, width - 30, height - 10);
        ofPopMatrix(); // restore state
        
        // Ear - in right
        ofPushMatrix(); // save current state
        ofTranslate(x + 255, y - 170); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0,width -30, height - 10);
        ofPopMatrix(); // restore state
        
        // Body
        ofFill();
        ofSetColor(225, 77, 180); // pink
        ofDrawEllipse(x + 175, y - 75, width + 140, height + 140);
        
        //Eyes
        ofPath path;
        ofSetColor(255);
        path.arc(x + 130, y - 110, width/3, height/3, 0, 180); // left
        path.close();
        path.arc(x + 220, y - 110, width/3, height/3, 0, 180); // right
        path.close();
        path.draw();
        
        // Inside Eyes
        // Left
        ofPushMatrix(); // save current state
        ofTranslate(x + 135, y - 95); // translate to the position of start
        ofRotateDeg(120); // gives a crossed angle
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(0, 0, width - 85, height - 65);
        ofPopMatrix(); // restore state
        
        // Right
        ofPushMatrix(); // save current state
        ofTranslate(x + 215, y - 95); // translate to the position of start
        ofRotateDeg( - 120); // gives a crossed angle
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(0, 0, width - 85, height - 65); // left
        ofPopMatrix(); // restore state
        
        // Mouth
        ofFill();
        ofSetColor(225, 196, 77); // yellow
        ofDrawEllipse(x + 180, y - 60, width - 40, height - 55);
        
        // Mouth Line
        ofFill();
        ofSetColor(0);
        ofDrawLine(x + 150, y - 50, x + 210, y - 50);
        
        
    } else if (tickling){
        
        // Feet
        ofFill();
        ofSetColor(77, 225, 122);// green
        ofDrawEllipse(x + 125, y + 45, width - 40, height - 50); // left
        ofDrawEllipse(x + 225, y + 45, width - 40, height - 50); // right
        
        // Ear - out left
        ofPushMatrix(); // save current state
        ofTranslate(x + 95, y - 175); // translate to the position of start
        ofRotateDeg(-angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0, width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - out right
        ofPushMatrix(); // save current state
        ofTranslate(x + 265, y - 170); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0,width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - in left
        ofPushMatrix(); // save current state
        ofTranslate(x + 95, y - 175); // translate to the position of start
        ofRotateDeg(-angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0, width - 30, height - 10);
        ofPopMatrix(); // restore state
        
        // Ear - in right
        ofPushMatrix(); // save current state
        ofTranslate(x + 265, y - 170); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0,width -30, height - 10);
        ofPopMatrix(); // restore state
        
        // Body
        ofFill();
        ofSetColor(225, 77, 180); // pink
        ofDrawEllipse(x + 175, y - 75, width + 140, height + 140);
        
        //Eyes - outside
        ofFill();
        ofSetColor(255);
        //
        ofDrawEllipse(x + 150, y - 110, width - 15, ofMap(interval,0,120,0, height - 50)); // left out
        ofDrawEllipse(x + 210, y - 110, width - 15, ofMap(interval,0,120,0, height - 50)); // right out
        
        //Eyes - inside
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(x + 150, y - 110, width - 60, ofMap(interval,0,120,0, height - 60)); // left in
        ofDrawEllipse( x + 210, y - 110, width - 60, ofMap(interval,0,120,0, height - 60)); // right in
        
        ofFill();
        ofSetColor(255);
        // maps the interval of the height (blinking eyes)
        ofDrawEllipse(x + 150, y - 110,width - 80,  ofMap(interval,0,120,0, height - 80)); // left in
        ofDrawEllipse(x + 210, y - 110,width - 80, ofMap(interval,0,120,0, height - 80)); // right in
        
        // Mouth
        ofFill();
        ofSetColor(225, 196, 77); // yellow
        ofDrawEllipse(x + 180, y - 70, width - 40, height - 55);
        
        // Mouth Line
        ofFill();
        ofSetColor(0);
        ofDrawLine(x + 150, y - 70, x + 210, y - 70);
        
    }else if (peting) {
        
        // Feet
        ofFill();
        ofSetColor(77, 225, 122);// green
        ofDrawEllipse(x + 125, y + 45, width - 40, height - 50); // left
        ofDrawEllipse(x + 225, y + 45, width - 40, height - 50); // right
        
        // Ear - out left
        ofPushMatrix(); // save current state
        ofTranslate(x + 95, y - 175); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0, width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - out right
        ofPushMatrix(); // save current state
        ofTranslate(x + 265, y - 170); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0,width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - in left
        ofPushMatrix(); // save current state
        ofTranslate(x + 95, y - 175); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0, width - 30, height - 10);
        ofPopMatrix(); // restore state
        
        // Ear - in right
        ofPushMatrix(); // save current state
        ofTranslate(x + 265, y - 170); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0,width -30, height - 10);
        ofPopMatrix(); // restore state
        
        // Body
        ofFill();
        ofSetColor(225, 77, 180); // pink
        ofDrawEllipse(x + 175, y - 75, width + 140, height + 140);
        
        //Eyes
        // draw an arc using paths (closed eyes)
        ofPath path;
        path.setFilled(false); //  set no fill for paths
        path.setStrokeWidth(2);
        path.setStrokeColor(100); // grey
        path.arc(x + 130, y - 110, width/3, height/3, 0, 180); // left
        path.close(); // before start new path
        path.arc(x + 220, y - 110, width/3, height/3, 0, 180); // right
        path.close();
        path.draw(); // both paths
        
        // Mouth
        ofFill();
        ofSetColor(225, 196, 77); // yellow
        ofDrawEllipse(x + 180, y - 50, width - 40, height - 55);
        
        // Mouth Line
        ofFill();
        ofSetColor(0);
        ofDrawLine(x + 150, y - 50, x + 210, y - 50);
        
    } else {
        // **** normal state of furby. Display at the begging ****
        // Feet
        ofFill();
        ofSetColor(77, 225, 122);// green
        ofDrawEllipse(x + 125, y + 45, width - 40, height - 50); // left
        ofDrawEllipse(x + 225, y + 45, width - 40, height - 50); // right
        
        // Ear - out left
        ofPushMatrix(); // save current state
        ofTranslate(x + 75, y - 190); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0, width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - out right
        ofPushMatrix(); // save current state
        ofTranslate(x + 265, y - 190); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 225, 122); // green
        ofDrawEllipse(0, 0,width, height + 20);
        ofPopMatrix(); // restore state
        
        // Ear - in left
        ofPushMatrix(); // save current state
        ofTranslate(x + 80, y - 190); // translate to the position of start
        ofRotateDeg(- angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0, width - 30, height - 10);
        ofPopMatrix(); // restore state
        
        // Ear - in right
        ofPushMatrix(); // save current state
        ofTranslate(x + 270, y - 190); // translate to the position of start
        ofRotateDeg(angle_mov);
        ofFill();
        ofSetColor(77, 106, 225); // blue
        ofDrawEllipse(0, 0,width -30, height - 10);
        ofPopMatrix(); // restore state
        
        // Body
        ofFill();
        ofSetColor(225, 77, 180); // pink
        ofDrawEllipse(x + 175, y - 75, width + 140, height + 140);
        
        //Eyes - outside
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(x + 150, y - 110, width - 15, height - 30); // left out
        ofDrawEllipse(x + 210, y - 110, width - 15, height - 30); // right out
        
        //Eyes - inside
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(x + 150, y - 110, width - 60,height - 60); // left in
        ofDrawEllipse( x + 210, y - 110, width - 60,height - 60); // right in
        
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(x + 150, y - 110,width - 80, height - 80); // left in
        ofDrawEllipse(x + 210, y - 110,width - 80, height - 80); // right in
        
        // Mouth
        ofFill();
        ofSetColor(225, 196, 77); // yellow
        ofDrawEllipse(x + 180, y - 50, width - 40, height - 55);
        
        // Mouth Line
        ofFill();
        ofSetColor(0);
        ofDrawLine(x + 150, y - 50, x + 210, y - 50);
        
    }
    
    // displays the position of the mouse
    string pixelCoords = "("+to_string(mouseX)+", "+to_string(mouseY)+")";  // creates a string with pixel position
    ofSetColor(255,0,255);     // set text color
    ofDrawBitmapString(pixelCoords, mouseX, mouseY); // write text with pixel position following the mouse
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'f' && !tickling && !peting){
        
        feeding = true;
        feed_sound.play();
        
    } else if (key == 't' && !feeding && !peting){
        
        tickling = true;
        tickle_sound.play();
        
    } else if (key == 'p' && !tickling && !feeding){
        
        peting = true;
        pet_sound.play();
    }
    std::cout << "You pressed " << key << std::endl; // this will print the int value of the key
    std::cout << "You pressed " << char(key) << std::endl; // this will print the char value of the key
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'f'){
        
        feeding = false;
        feed_sound.stop();
        
    } else if (key == 't'){
        
        tickling = false;
        tickle_sound.stop();
        
    } else if (key == 'p'){
        
        peting = false;
        pet_sound.stop();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
