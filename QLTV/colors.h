#pragma once
#include <graphics.h>
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))

enum mauChinh{
	MAU_MENU			= COLOR(36, 41, 46),
	MAU_NEN				= COLOR(18, 20, 23),	
	HIGHTLIGHT			= COLOR(3, 102, 214), 
	HIGHTLIGHTS         = COLOR(47, 54, 61),  	
	HL_MENU_PHU			= COLOR(3, 102, 214)	
};

enum mauKhung{
	NEN_KHUNG			= COLOR(30, 30, 30),
	MAU_TEXT_KHUNG		= COLOR(161, 166, 171),
	NEN_TEXT			= COLOR(29, 33, 37),
	TEXTBOX				= COLOR(29, 33, 37)
};

