#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <string>
#include "StartScreen.hpp"
#include "Multiplayer.hpp"

class MainMenu
{
public:
	MainMenu();
	void setSelection();
	void showAvaibleSelections();
	void setString();
	int showSelection();

	bool mOpen;
	bool mPlayingMode;
	StartScreen screen;
	int mSelection;
};

#endif;
