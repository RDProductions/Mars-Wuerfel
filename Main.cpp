#include <iostream>
#include "StartScreen.hpp"
#include "MainMenu.hpp"

int main()
{
	StartScreen startscreen;
	MainMenu mainMenu;

	bool open = true;
	int selection = 0;

	//Zeige StartBildschirm
	std::cout << startscreen.ShowTitle() << startscreen.ShowMiniHelp() << std::endl;

	//Hauptschleife mit Prüfung ob Fenster schließen oder nicht
	while (open)
	{
		if (!mainMenu.mPlayingMode)
		{
			mainMenu.showAvaibleSelections();

			mainMenu.setSelection();
		}
			mainMenu.setString();
			selection = mainMenu.showSelection();
		open = mainMenu.mOpen;
	}

	std::cin.get();
	return 0;
}
