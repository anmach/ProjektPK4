#include "pch.h"
#include "All_things.h"

#pragma region CONSTRUCTORS
ALL_things::ALL_things()
{
	al_install_mouse();		 //instalowanie sterownika myszki

	window = al_create_display(windowW, windowH);
	al_set_window_title(window, "Projekt z PK - Anna Mach");
	font = al_load_ttf_font("Obrazki/IdealistSans.ttf", 16, 0);
	fontText = al_load_ttf_font("Obrazki/IdealistSans.ttf", 20, 0);

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_register_event_source(eventQueue, al_get_display_event_source(window));
}

ALL_things::~ALL_things()
{
	al_destroy_display(window);	//usuwanie z pamiêci okna
	al_destroy_font(font);			//fontów
	al_destroy_font(fontText);
	al_destroy_event_queue(eventQueue);
}
#pragma endregion

#pragma region ACCESORS
ALLEGRO_FONT * ALL_things::getFont()
{
	return font;
}

ALLEGRO_FONT * ALL_things::getFontText()
{
	return fontText;
}

ALLEGRO_DISPLAY * ALL_things::getWindow()
{
	return window;
}

ALLEGRO_MOUSE_STATE ALL_things::getMouseState()
{
	return mouseState;
}
int ALL_things::getMouseX()
{
	return events.mouse.x;
}
int ALL_things::getMouseY()
{
	return events.mouse.y;
}
int ALL_things::getMouseButtons()
{
	return events.mouse.button;
}
ALLEGRO_EVENT_TYPE ALL_things::getEventType()
{
	return events.type;
}
ALLEGRO_EVENT_QUEUE * ALL_things::getEventQueue()
{
	return eventQueue;
}
ALLEGRO_EVENT ALL_things::getEvent()
{
	return events;
}
bool ALL_things::nextEvent()
{
	return al_get_next_event(eventQueue, &events);
}
void ALL_things::refreshMouseState()
{
	al_get_mouse_state(&mouseState);
}
void ALL_things::waitForEvent()
{
	al_wait_for_event(eventQueue, &events);
}
#pragma endregion

void ALL_things::drawBackground(ALLEGRO_BITMAP* bitmap)
{
	if (bitmap != nullptr)
	{
		al_clear_to_color(al_map_rgb(0, 255, 0)); // wyczyszczenie aktualnego bufora ekranu
		al_draw_bitmap(bitmap, 0, 0, 0);		  // wyœwietlenie bitmapy "bitmap" na "Backbuffer" (bufor ekranu)
			}
	else
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
}

void ALL_things::drawImg(ALLEGRO_BITMAP * bitmap, int x, int y)
{
	if (bitmap != nullptr){
		al_draw_bitmap(bitmap, x, y, 0);		  // wyœwietlenie bitmapy "bitmap" na "Backbuffer" (bufor ekranu)
	}
}

void ALL_things::drawImage(Image * img)
{
	if (img->getImg() != nullptr){
		al_draw_bitmap(img->getImg(), img->getX(), img->getY(), 0);	
	}
}

void ALL_things::drawRectangleOnImage(Image * img)
{
	if (img != nullptr)
		al_draw_filled_rectangle(img->getX(), img->getY(), img->getX() + img->getW(), img->getY() + img->getH(), al_map_rgb(0, 0, 0));
}

void ALL_things::refreshDisplay()
{
	al_flip_display();
}
