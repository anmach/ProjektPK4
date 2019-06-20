// ProjektSemestr4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"

int main()
{

#pragma region ALLEGRO INITIALIZATION
	if (!al_init()) // inicjalizacja allegro
	{
		al_show_native_message_box(nullptr, "Error", "Allegro initialization", "Could not initialize Allegro 5", " ", NULL);
		return 0; //inicjalizacja nie powiodła się
	}
	if (!al_init_font_addon() || !al_init_image_addon() || !al_init_ttf_addon() || !al_init_primitives_addon())

	{
		al_show_native_message_box(nullptr, "Error", "Allegro initialization", "Could not initialize addons", " ", NULL);
		return 0;
	}
#pragma endregion

	Program program;
	program.loop();

	return 0;
}