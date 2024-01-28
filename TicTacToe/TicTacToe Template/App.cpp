#include "App.h"
#include <iostream>
#include <cmath>

using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    mFocusRect = -1;

	mTwoPlayer = false;
	mFirstPlayer = true;
	mGameState = ACTIVE;

	// Contruction of the Board
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			mBoard[i][j] = BLANK;
			float xb = ((-3 * mBoxSize) / 2) + mBoxSize * j;
			float yb = ((1 * mBoxSize) / 2) - mBoxSize * i;
			mBoardVisual[i][j] = Rect(xb, yb, mBoxSize, mBoxSize);
		}
	}
}

void App::drawBox(Rect& rect, BoxState& boxState){
	if (boxState == FIRSTPLAYER){
		glColor3f(1, 0, 0); // Red X
		glBegin(GL_LINES);
		glVertex2f(rect.getX(), rect.getY());
		glVertex2f(rect.getX() + rect.getW(), rect.getY() + rect.getH());
		glVertex2f(rect.getX(), rect.getY() + rect.getH());
		glVertex2f(rect.getX() + rect.getW(), rect.getY());
		glEnd();
	}
	else if (boxState == SECONDPLAYER){
		glColor3f(0, 0, 1); //Blue O
		glBegin(GL_LINES);
		float x = rect.getX() + rect.getW()/2;
		float y = rect.getY() + rect.getH()/2;
		float r = rect.getW() / 3;
		
		const float M_PI = 3.14159f;
		for (int i = 0; i < 1000; i++) {
			glVertex2f(x + r*cos(2 * M_PI /1000 * i), y + r*sin(2 * M_PI / 1000 * i));
		}

		glEnd();
	}
    glColor3f(1,1,1); //White Squares

    glBegin(GL_POLYGON);
    glVertex2f(rect.getX(), rect.getY());
    glVertex2f(rect.getX()+rect.getW(), rect.getY());
    glVertex2f(rect.getX()+rect.getW(), rect.getY()+rect.getH());
    glVertex2f(rect.getX(), rect.getY()+rect.getH());
    glEnd();

    // Trim Lines of Square
    glColor3f(0,0,1); //Blue Lines
    // Horizontal Lines
    glBegin(GL_LINES);
    glVertex2f(rect.getX(), rect.getY());
    glVertex2f(rect.getX()+rect.getW(), rect.getY());
    glVertex2f(rect.getX()+rect.getW(), rect.getY()+rect.getH());
    glVertex2f(rect.getX(), rect.getY()+rect.getH());
    // Vertical Lines
    glVertex2f(rect.getX()+rect.getW(), rect.getY());
    glVertex2f(rect.getX()+rect.getW(), rect.getY()+rect.getH());
    glVertex2f(rect.getX(), rect.getY());
    glVertex2f(rect.getX(), rect.getY()+rect.getH());
    glEnd();

}

void App::draw(){

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	if (mGameState == FIRSTWINNER){
		cout << "First winner\n";
	}
	else if (mGameState == SECONDWINNER) {
		cout << "Second winner\n";
	}
	for (int i = 0; i < 3; i++) {  
		for (int j = 0; j < 3; j++) {
			drawBox(mBoardVisual[i][j], mBoard[i][j]);
		}
	}
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
	if (mGameState != ACTIVE) return;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mBoard[i][j] == BLANK && mBoardVisual[i][j].contains(x, y)) {
				if (mFirstPlayer) mBoard[i][j] = FIRSTPLAYER;
				else mBoard[i][j] = SECONDPLAYER;
				if (mTwoPlayer) mFirstPlayer = !mFirstPlayer;
				else {
					for (int ii = 0; ii < 3; ii++) {
						for (int jj = 0; jj < 3; jj++) {
							if (mBoard[ii][jj] == BLANK) {
								mBoard[ii][jj] = SECONDPLAYER;
								updateGameState();
								// Redraw the scene
								redraw();
								return;
							}
						}
					}
				}
			}
		}
	}
	updateGameState();
    // Redraw the scene
    redraw();
}
void App::updateGameState() {
	BoxState winner = BLANK;
	for (BoxState p = FIRSTPLAYER; p <= SECONDPLAYER; p=(BoxState)(((int)p)+1)) {
		for (int i = 0; i < 3; i++) {
			if (mBoard[i][0] == p && mBoard[i][1] == p && mBoard[i][2] == p) winner = p;
		}
		for (int i = 0; i < 3; i++) {
			if (mBoard[0][i] == p && mBoard[1][i] == p && mBoard[2][i] == p) winner = p;
		}
		if (mBoard[0][0] == p && mBoard[1][1] == p && mBoard[2][2] == p) winner = p;
		if (mBoard[0][2] == p && mBoard[1][1] == p && mBoard[2][0] == p) winner = p;
	}
	if (winner == FIRSTPLAYER) mGameState = FIRSTWINNER;
	if (winner == SECONDPLAYER) mGameState = SECONDWINNER;
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

    //cout << x << " " << y << endl;
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key){
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}

Rect::Rect(float x, float y, float w, float h){
    mx = x;
    my = y;
    mw = w;
    mh = h;
}

Rect::Rect(){
	mx = 0;
	my = 0;
	mw = 0;
	mh = 0;
}

float Rect::getX(){
    return mx;
}
void Rect::setX(float x){
    mx = x;
}

float Rect::getY(){
    return my;
}
void Rect::setY(float y){
    my = y;
}

float Rect::getW(){
    return mw;
}
void Rect::setW(float w){
    mw = w;
}

float Rect::getH(){
    return mh;
}
void Rect::setH(float h){
    mh = h;
}

bool Rect::contains(float x, float y){
    return x >= mx && x <= mx+mw && y >= my && y <= my+mh;

}