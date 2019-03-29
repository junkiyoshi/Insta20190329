#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5 + 80);
	ofRotate(270);

	for (int i = 0; i < 250; i++) {

		float radius = ofRandom(160, 400);
		vector<glm::vec2> vertices;
		int start = ofRandom(1000) + ofGetFrameNum() * ofRandom(1, 3);
		for (int deg = start; deg <= start + ofRandom(15, 100); deg++) {

			vertices.push_back(this->make_point(radius, deg));
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(float radius, int deg) {

	deg = deg % 360;

	int deg_a = (deg / 120) * 120;
	int deg_b = deg_a + 120;

	int remainder = deg % 120;
	int diff = deg - deg_a;

	auto point_a = glm::vec2(radius * cos(deg_a * DEG_TO_RAD), radius * sin(deg_a * DEG_TO_RAD));
	auto point_b = glm::vec2(radius * cos(deg_b * DEG_TO_RAD), radius * sin(deg_b * DEG_TO_RAD));
	auto distance = point_b - point_a;

	return point_a + (distance / 120) * diff;
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}