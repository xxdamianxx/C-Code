#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include <vector>

class Rect {
    
    float mx, my, mw, mh;

public:
	Rect();
    Rect(float x, float y, float w, float h);
    bool contains(float x, float y);

    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    float getW();
    void setW(float w);
    float getH();
    void setH(float h);
};

class App: public GlutApp {

	enum BoxState { BLANK, FIRSTPLAYER, SECONDPLAYER };

    // Maintain app state here
    float mx;
    float my;
    std::vector<Rect*> mRects;
    int mFocusRect;
	void drawBox(Rect& rect, BoxState& boxState);
	void updateGameState();
	bool mTwoPlayer;
	bool mFirstPlayer;
	BoxState mBoard[3][3];
	Rect mBoardVisual[3][3];
	enum GameState{ACTIVE, FIRSTWINNER, SECONDWINNER, TIE};
	GameState mGameState;
	const float mBoxSize = 1.5f / 3.0f;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);


};

#endif
