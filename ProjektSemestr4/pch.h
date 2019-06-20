#ifndef PCH_H
#define PCH_H

#define windowH 720
#define windowW 1280

#define farmH 600
#define farmW 800
#define farmX 0
#define farmY 100

#define dragonImageString "Obrazki/Dragon.jpg"
#define perytonImageString "Obrazki/Peryton.jpg"
#define phoenixImageString "Obrazki/Phoenix.jpg"

#define dragonScaleImageString "Obrazki/DragonScale.jpg"
#define perytonFeatherImageString "Obrazki/PerytonFeather.jpg"
#define phoenixFeatherImageString "Obrazki/PhoenixFeather.jpg"

#define dragonScale2ImageString "Obrazki/DragonScale2.jpg"
#define perytonFeather2ImageString "Obrazki/PerytonFeather2.jpg"
#define phoenixFeather2ImageString "Obrazki/PhoenixFeather2.jpg"

#define dragonScaleForgeImageString "Obrazki/DragonScaleForge.jpg"
#define perytonFeatherSpecialistImageString "Obrazki/PerytonFeatherSpecialist.jpg"
#define phoenixFeatherAlchemistImageString "Obrazki/Alchemist.jpg"

#define crossImageString "Obrazki/Cross.jpg"
#define predatorImageString "Obrazki/Predator.jpg"

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>

#include <string>
#include <iostream>
#include <list>

#include "All_things.h"
#include "Image.h"

#include "Program.h"
#include "Game.h"
#include "Menu.h"

#include "Dragon.h"
#include "Peryton.h"
#include "Phoenix.h"

#include "DragonScale.h"
#include "PhoenixFeather.h"
#include "PerytonFeather.h"

#include "DragonScaleForge.h"
#include "PhoenixFeatherAlchemist.h"
#include "PerytonFeatherSpecialist.h"

#endif //PCH_H
