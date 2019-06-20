#pragma once
#include <allegro5/allegro_primitives.h>
class Image;

class ALL_things
{
private:
	ALLEGRO_DISPLAY * window; //wskaünik okna
	ALLEGRO_FONT *font; //wskaünik fonta
	ALLEGRO_FONT *fontText;
	ALLEGRO_MOUSE_STATE mouseState; //utworzenie struktury do otczytu stanu myszki
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT events;
public:
	ALL_things();
	~ALL_things();

	//accesors
	ALLEGRO_FONT* getFont();
	ALLEGRO_FONT* getFontText();
	ALLEGRO_DISPLAY* getWindow();

	//accesors to mouse
	ALLEGRO_MOUSE_STATE getMouseState();
	int getMouseX();
	int getMouseY();
	int getMouseButtons();

	//accesors to events
	ALLEGRO_EVENT_TYPE getEventType();
	ALLEGRO_EVENT_QUEUE* getEventQueue();
	ALLEGRO_EVENT getEvent();
	bool nextEvent();

	void refreshMouseState();
	void waitForEvent();

	void drawBackground(ALLEGRO_BITMAP* bitmap);
	void drawImg(ALLEGRO_BITMAP* bitmap, int x, int y);
	void drawImage(Image* img);
	void drawRectangleOnImage(Image* img);
	void refreshDisplay();
};