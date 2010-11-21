#include "testApp.h"

#include "lcdtv/index_channel.h"
#include "lcdtv/folder_channel.h"

//--------------------------------------------------------------
void testApp::setup(){

    m_Channels.reserve (10);
    m_Channels.push_back (new lcdtv::index_channel ("Index Channel", "id/index.png", "LCD TV", &m_Channels));
    m_Channels.push_back (new lcdtv::folder_channel ("Video Art Channel", "id/video_art.png", "channels/video_art"));
    m_Channels.push_back (new lcdtv::folder_channel ("UBU Channel", "id/ubu.png", "channels/ubu"));
    m_Channels.push_back (new lcdtv::folder_channel ("Talks Channel", "id/talks.png", "channels/talks"));
    m_Channels.push_back (new lcdtv::folder_channel ("AZ Projects Channel", "id/az_projects.png", "channels/az_projects"));
    m_Channels.push_back (new lcdtv::folder_channel ("Performance Channel", "id/performance.png","channels/performance"));
    m_Channels.push_back (new lcdtv::folder_channel ("4D Channel", "id/4d.png", "channels/4d"));
    m_Channels.push_back (new lcdtv::folder_channel ("Interactive Art Channel", "id/interactive_art.png", "channels/interactive_art"));
    m_Channels.push_back (new lcdtv::folder_channel ("Music Channel", "id/music.png", "channels/music"));
    m_Channels.push_back (new lcdtv::folder_channel ("Tutorials Channel", "id/tutorial.png", "channels/tutorial"));

    m_CurrentChannel = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    m_Channels[m_CurrentChannel]->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    m_Channels[m_CurrentChannel]->draw (0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    int channel = key - '0';

    if (channel < 0 || channel >= m_Channels.size()) {
        channel = 0;
    }

    m_Channels[m_CurrentChannel]->stop();
    m_CurrentChannel = channel;
    m_Channels[m_CurrentChannel]->play();
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

