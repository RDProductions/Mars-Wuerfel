#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	mOpen = true;
	mPlayingMode = false;
}

void MainMenu::showAvaibleSelections()
{
	std::cout << "\nHauptmenue:"
		"\n1 : Einzelspieler,"
		"\n2 : Mehrspieler Einfach"
		"\n3 : Mehrspieler Normal"
		"\n4 : Mehrspieler Schwer"
		"\n5 : Anleitung anzeigen"
		"\n6 : Sprache wechseln"
		"\n7 : Quellcode"
		"\n8 : Credits"
		"\n9 : Beenden";
}

void MainMenu::setSelection()
{
	std::cout << "\nBitte geben sie ihre Auswahl an!" << std::endl;
	std::cin >> mSelection;
}

int MainMenu::showSelection()
{
	return mSelection;
}

void MainMenu::setString()
{
	switch (mSelection)
	{
	case 1:	//SP
	{
				std::cout << std::endl << "Einzelspieler noch nicht verfuegbar!" << std::endl;
				//mOpen = true;
	}
		break;
	case 2:	//MP easy
	{
				if (!mPlayingMode)
				{
					std::cout << std::endl << "Einfacher Mehrspieler gewaehlt!" << std::endl;
				}

				Multiplayer mp;
				mp.PlayState(0);
				//mOpen = true;
	}
		break;
	case 3:	//MP normal
	{
				if (!mPlayingMode)
				{
					std::cout << std::endl << "Normaler Mehrspieler gewaehlt!" << std::endl;
				}
				Multiplayer mp;
				mp.PlayState(1);
				//mOpen = true;
	}
		break;
	case 4:	//MP hard
	{
				if (!mPlayingMode)
				{
					std::cout << std::endl << "Schwerer Mehrspieler gewaehlt!" << std::endl;
				}
				Multiplayer mp;
				mp.PlayState(2);
				//mOpen = true;
	}
		break;
	case 5:	//Help
	{
				std::string helpOutput = screen.ShowHelp();
				std::cout << std::endl << helpOutput << std::endl;
				//mOpen = true;
	}
		break;
	case 6:	//Translate into English
	{
				std::cout << std::endl << "Uebersetzungen sind leider noch nicht verfuegbar!" << std::endl;
				//mOpen = true;
	}
		break;
	case 7:	//Sourcecode
	{
				std::cout << std::endl << "Sourcecode verfuegbar auf:"
					"\nhttps://github.com/RDProductions/Mars-Wuerfel/tree/master" << std::endl;
				//mOpen = true;
	}
		break;
	case 8:	//Credits
	{
				std::cout << std::endl << "MARS WUERFEL\nEin Videospiel nach dem Prinzip von Mars Wuerfel."
					"\nProgrammierstudio: RD Productions, \nProgrammierer: Robin Deckert, \nProgrammiersprache: C++, \nIDE: MS Visual Studio Express 2013.\n"
					"\nWaehrend der Mini Game++ Community Challenge entstanden." << std::endl;
				//mOpen = true;
	}
		break;
	case 9:	//Close application
	{
				//mString auf closed setzen wegen main()-Hauptschleife, s. Main.cpp
				std::cout << std::endl << "Programm wird geschlossen!" << std::endl;
				mOpen = false;
	}
		break;

	default:
		break;
	}
}
