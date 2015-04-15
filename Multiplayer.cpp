#include "Multiplayer.hpp"
#include <iostream>

Multiplayer::Multiplayer()
: select_player1(1)
, select_player2(1)
, selectface(0)
, nochmal(true)
{
	
	anzahlwürfel = 13;
}

void Multiplayer::PlayStatePlayer1(int hardness)
{
	//SPIELER 1 AM ZUG

	genutzthühner = false;
	genutztkühe = false;
	genutztmenschen = false;

	gesamtpunktespieler1 = 0;
	gesamthühner = 0;
	gesamtkühe = 0;
	gesamtmenschen = 0;
	gesamtstrahler = 0;
	gesamtpanzer = 0;
	whsp1 = true;

	punktespieler1 = 0;
	gesamtpunktespieler1 = 0;
	
	while (whsp1)
	{
		anzahlstrahler = 0;
		anzahlkühe = 0;
		anzahlmenschen = 0;
		anzahlhühner = 0;

		std::cout << std::endl << "Spieler 1 am Zug:" << std::endl;
		std::srand(time(NULL));
		std::cout << std::endl << "Spieler 1 hat folgendes gewuerfelt:" << std::endl;

		for (würfel = 0; würfel < anzahlwürfel; würfel++)
		{
			cube[würfel] = std::rand() & (5 + hardness);

			switch (cube[würfel])
			{
			case 0:
				face = "Todesstrahler";
				anzahlstrahler++;
				std::cout << "\n case 0";
				break;
			case 1:
				face = "Todesstrahler";
				anzahlstrahler++;
				std::cout << "\n case 1";
				break;
			case 2:
				face = "Mensch";
				anzahlmenschen++;
				std::cout << "\n case 2";
				break;
			case 3:
				face = "Panzer";
				gesamtpanzer++;
				std::cout << "\n case 3";
				break;
			case 4:
				face = "Kuh";
				anzahlkühe++;
				std::cout << "\n case 4";
				break;
			case 5:
				face = "Huhn";
				anzahlhühner++;
				std::cout << "\n case 5";
				break;
			case 6:
				face = "Panzer";
				gesamtpanzer++;
				std::cout << "\n case 6";
				break;
			case 7:
				face = "Panzer";
				gesamtpanzer++;
				std::cout << "\n case 7";
				break;
			default:
				face = "FEHLER";
				break;
			}

			std::cout << "\tWuerfel " << würfel+1 << ": " << face << std::endl;
		}

		do
		{
			std::cout << "\nWollen sie die Todesstrahler oder eine Art von Lebewesen nehmen?" << std::endl
				<< "(1) Todesstrahler : " << anzahlstrahler << " Stueck" << " / insgesamt: " << gesamtstrahler << std::endl
				<< "(2) Menschen : " << anzahlmenschen << " Stueck" << " / insgesamt: " << gesamtmenschen << std::endl
				<< "(3) Kuehe : " << anzahlkühe << " Stueck" << " / insgesamt: " << gesamtkühe << std::endl
				<< "(4) Huehner : " << anzahlhühner << " Stueck" << " / insgesamt: " << gesamthühner << std::endl
				<< "Sie haben z.Z. " << gesamtpanzer << " Panzer" << std::endl;

			std::cin >> selectface;

			while (selectface > 4)
			{
				std::cout << "\nFalsche Eingabe!\nWollen sie die Todesstrahler oder eine Art von Lebewesen nehmen?" << std::endl
					<< "(1) Todesstrahler : " << anzahlstrahler << " Stueck" << " / insgesamt: " << gesamtstrahler << std::endl
					<< "(2) Menschen : " << anzahlmenschen << " Stueck" << " / insgesamt: " << gesamtmenschen << std::endl
					<< "(3) Kuh : " << anzahlkühe << " Stueck" << " / insgesamt: " << gesamtkühe << std::endl
					<< "(4) Huhn : " << anzahlhühner << " Stueck" << " / insgesamt: " << gesamthühner << std::endl
					<< "Sie haben z.Z. " << gesamtpanzer << " Panzer" << std::endl;

				std::cin >> selectface;
			}

			switch (selectface)
			{
			case 1:
				anzahlwürfel -= anzahlstrahler;
				gesamtstrahler += anzahlstrahler;
				nochmal = false;
				break;
			case 2:
				if (genutztmenschen)
				{
					std::cout << "\nSie haben die Menschen schon einmal gewaehlt!" << std::endl;
					nochmal = true;
				}
				else
				{
					anzahlwürfel -= anzahlmenschen;
					punktespieler2 += anzahlmenschen;
					gesamtmenschen += anzahlmenschen;
					genutztmenschen = true;
					nochmal = false;
				}
				break;
			case 3:
				if (genutztkühe)
				{
					std::cout << "\nSie haben die Kuehe schon einmal gewaehlt!" << std::endl;
					nochmal = true;
				}
				else
				{
					anzahlwürfel -= anzahlkühe;
					punktespieler2 += anzahlkühe;
					gesamtkühe += anzahlkühe;
					genutztkühe = true;
					nochmal = false;
				}
				break;
			case 4:
				if (genutzthühner)
				{
					std::cout << "\nSie haben die Huehner schon einmal gewaehlt!" << std::endl;
					nochmal = true;
				}
				else
				{
					anzahlwürfel -= anzahlhühner;
					punktespieler2 += anzahlhühner;
					gesamthühner += anzahlhühner;
					genutzthühner = true;
					nochmal = false;
				}
				break;
			default:
				break;
			}

		} while (nochmal);

		std::cout << "\nWollen sie den naechsten Zug starten oder ihre Runde beenden?"
			"\n(1) Naechster Zug (2) Beenden\n";
		std::cin >> select_player1;

		while (select_player1 > 2)
		{
			std::cout << "\nNicht definierte Eingabe.\n"
				"Wollen sie den naechsten Zug starten oder ihre Runde beenden?"
				"\n(1) Naechster Zug (2) Beenden\n";
			std::cin >> select_player1;
		}

		if (select_player1 == 2)
		{
			if (anzahlstrahler >= gesamtpanzer)
			{
				std::cout << "Sie hatten genug Todesstrahler um die Panzer abzuwehren."
					"\nIhre Punktzahl beträgt " << punktespieler1 << " Punkte." << std::endl;

				std::cout << "\nIhre Gesamtpunktzahl betraegt " << gesamtpunktespieler1 << " Punkte." << std::endl;
				nochmal = false;
			}
			else
			{
				punktespieler1 = 0;

				std::cout << "Sie hatten nicht genug Todesstrahler um die Panzer abzuwehren."
					"\nIhre Punktzahl betraegt " << punktespieler1 << " Punkte." << std::endl;

				gesamtpunktespieler1 += punktespieler1;

				std::cout << "Ihre Gesamtpunktzahl betraegt " << gesamtpunktespieler1 << " Punkte." << std::endl;
				nochmal = false;
			}
			whsp1 = false;
		}
		else
		{
			whsp1 = true;
		}
	}
}

void Multiplayer::PlayStatePlayer2(int hardness)
{

	//SPIELER 2 AM ZUG

	anzahlwürfel = 13;
	genutzthühner = false;
	genutztkühe = false;
	genutztmenschen = false;

	gesamtpunktespieler2 = 0;
	gesamthühner = 0;
	gesamtkühe = 0;
	gesamtmenschen = 0;
	gesamtstrahler = 0;
	gesamtpanzer = 0;
	whsp2 = true;

	while (whsp2)
	{
		anzahlstrahler = 0;
		anzahlkühe = 0;
		anzahlmenschen = 0;
		anzahlhühner = 0;
		
		std::cout << std::endl << "Spieler 2 am Zug:" << std::endl;
		std::srand((unsigned)time(NULL));
		std::cout << std::endl << "Spieler 2 hat folgendes gewuerfelt:" << std::endl;

		for (würfel = 0; würfel < anzahlwürfel; würfel++)
		{
			cube[würfel] = std::rand() & (5 + hardness);

			switch (cube[würfel])
			{
			case 0:
				face = "Todesstrahler";
				anzahlstrahler++;
				break;
			case 1:
				face = "Todesstrahler";
				anzahlstrahler++;
				break;
			case 2:
				face = "Mensch";
				anzahlmenschen++;
				break;
			case 3:
				face = "Panzer";
				gesamtpanzer++;
				break;
			case 4:
				face = "Kuh";
				anzahlkühe++;
				break;
			case 5:
				face = "Huhn";
				anzahlhühner++;
				break;
			case 6:
				face = "Panzer";
				gesamtpanzer++;
				break;
			case 7:
				face = "Panzer";
				gesamtpanzer++;
				break;
			default:
				face = "FEHLER";
				break;
			}

			std::cout << "\tWuerfel " << würfel+1 << ": " << face << std::endl;
		}

		std::cout << "\nWollen sie die Todesstrahler oder eine Art von Lebewesen nehmen?" << std::endl
			<< "(1) Todesstrahler : " << anzahlstrahler << " Stueck" << " / insgesamt: " << gesamtstrahler << std::endl
			<< "(2) Menschen : " << anzahlmenschen << " Stueck" << " / insgesamt: " << gesamtmenschen << std::endl
			<< "(3) Kuh : " << anzahlkühe << " Stueck" << " / insgesamt: " << gesamtkühe << std::endl
			<< "(4) Huhn : " << anzahlhühner << " Stueck" << " / insgesamt: " << gesamthühner<< std::endl
			<< "Sie haben z.Z. " << gesamtpanzer << " Panzer" << std::endl;

		std::cin >> selectface;

		while (selectface > 4)
		{
			std::cout << "\nWollen sie die Todesstrahler oder eine Art von Lebewesen nehmen?" << std::endl
				<< "(1) Todesstrahler : " << anzahlstrahler << " Stueck" << " / insgesamt: " << gesamtstrahler << std::endl
				<< "(2) Menschen : " << anzahlmenschen << " Stueck" << " / insgesamt: " << gesamtmenschen << std::endl
				<< "(3) Kuh : " << anzahlkühe << " Stueck" << " / insgesamt: " << gesamtkühe << std::endl
				<< "(4) Huhn : " << anzahlhühner << " Stueck" << " / insgesamt: " << gesamthühner << std::endl
				<< "Sie haben z.Z. " << gesamtpanzer << " Panzer" << std::endl;

			std::cin >> selectface;
		}

		switch (selectface)
		{
		case 1:
			anzahlwürfel -= anzahlstrahler;
			gesamtstrahler += anzahlstrahler;
			break;
		case 2:
			if (genutztmenschen)
			{
				std::cout << "\nSie haben die Menschen schon einmal gewaehlt!" << std::endl;
				nochmal = true;
			}
			else if (anzahlmenschen < 1)
			{
				std::cout << "\nSie haben keine Menschen zur Auswahl!" << std::endl;
				nochmal = true;
			}
			else
			{
				anzahlwürfel -= anzahlmenschen;
				punktespieler2 += anzahlmenschen;
				gesamtmenschen += anzahlmenschen;
				genutztmenschen = true;
			}
			break;
		case 3:
			if (genutztkühe)
			{
				std::cout << "\nSie haben die Kuehe schon einmal gewaehlt!" << std::endl;
				nochmal = true;
			}
			else if (anzahlkühe < 1)
			{
				std::cout << "\nSie haben keine Kuehe zur Auswahl!" << std::endl;
				nochmal = true;
			}
			else
			{
				anzahlwürfel -= anzahlkühe;
				punktespieler2 += anzahlkühe;
				gesamtkühe += anzahlkühe;
				genutztkühe = true;
			}
			break;
		case 4:
			if (genutzthühner)
			{
				std::cout << "\nSie haben die Huehner schon einmal gewaehlt!" << std::endl;
				nochmal = true;
			}
			else if (anzahlhühner < 1)
			{
				std::cout << "\nSie haben keine Huehner zur Auswahl!" << std::endl;
				nochmal = true;
			}
			else
			{
				anzahlwürfel -= anzahlhühner;
				punktespieler2 += anzahlhühner;
				gesamthühner += anzahlhühner;
				genutzthühner = true;
			}
			break;
		default:
			break;
		}

		std::cout << "\nWollen sie den naechsten Zug starten oder ihre Runde beenden?"
			"\n(1) Naechster Zug (2) Beenden\n";
		std::cin >> select_player2;

		while (select_player2 > 2)
		{
			std::cout << "\nNicht definierte Eingabe.\n"
				"Wollen sie den naechsten Zug starten oder ihre Runde beenden?"
				"\n(1) Naechster Zug (2) Beenden\n";
			std::cin >> select_player2;
		}

		if (select_player1 == 2)
		{
			if (anzahlstrahler >= gesamtpanzer)
			{
				std::cout << "Sie hatten genug Todesstrahler um die Panzer abzuwehren."
					"\nIhre Punktzahl beträgt " << punktespieler2 << " Punkte." << std::endl;

					gesamtpunktespieler2 += punktespieler2;

				std::cout << "Ihre Gesamtpunktzahl beträgt " << gesamtpunktespieler2 << " Punkte." << std::endl;
			}
			else
			{
				punktespieler2 = 0;

				std::cout << "Sie hatten nicht genug Todesstrahler um die Panzer abzuwehren."
					"\nIhre Punktzahl betraegt " << punktespieler2 << " Punkte." << std::endl;

				gesamtpunktespieler2 += punktespieler2;

				std::cout << "Ihre Gesamtpunktzahl betraegt " << gesamtpunktespieler2 << " Punkte." << std::endl;

			}
			whsp2 = false;
		}
		else
		{
			whsp2 = true;
		}
	}
}

void Multiplayer::PlayState(int hardness)
{
	PlayStatePlayer1(hardness);
	PlayStatePlayer2(hardness);
}
