#include "StartScreen.hpp"

StartScreen::StartScreen()
{
	title = "\t\tMARS WUERFEL\n\n";
	minihelp = "Kurzanleitung: In Mars Wuerfel spielt man ein Marsmaennchen, welches"
		"\nLebewesen von der Erde stehlen will. Die Erde wehrt sich aber mit Panzern."
		"\nDas Spielziel ist, eine Gesamtpunktzahl von 25 Punkten zu erreichen."
		"\nMan hat 13 Wuerfel, dabei hat jeder Wuerfel je:"
		"\neinen Menschen(1 Punkt), eine Kuh(1 Punkt), ein Huhn(1 Punkt)"
		"\neinen Panzer und zwei Todesstrahler"
		"\nBei diesem PC-Spiel kann man die Schwierigkeit einstellen."
		"\nBei hoeherer Schwierigkeit erhoeht sich die Chanche auf einen Panzer."
		"\n\nMan gibt seine Auswahl mit den Zahlen 1 - 9 an und bestaetigt mit \"Enter\"";

	help = "Anleitung: In Mars Wuerfel spielt man ein Marsmaennchen, welches"
		"\nLebewesen von der Erde stehlen will."
		"\nDie Erdbewohner wehren sich aber mit Panzern."
		"\nDas Spielziel ist, nach mehreren Runden eine"
		"\nGesamtpunktzahl von 25 zu erreichen."
		"\nMan hat 13 Wuerfel, dabei hat jeder Wuerfel je:"
		"\neinen Menschen(1 Punkt)"
		"\neine Kuh(1 Punkt)"
		"\nein Huhn(1 Punkt)"
		"\neinen Panzer"
		"\nund zwei Todesstrahler"
		"\nNachdem man gewuerfelt hat, werden alle Panzer zur Seite gelegt"
		"\nund man entscheidet sich etwa"
		"\nfuer ein Entfuehrungsopfer(Mensch,Kuh,Huhn) oder die Todesstrahler."
		"\nMan darf pro Runde, die Opfer nicht zweimal auswaehlen."
		"\nSollte man min. ein Entfuehrungsopfer jeder Sorte gestohlen haben"
		"\n,bekommt man 3 Bonuspunkte."
		"\nAm Ende jedes Zuges kann man sich entscheiden, ob man die Runde"
		"\nbeenden will oder mit den restlichen Wuerfeln nocheinmal wuerfeln moechte."
		"\nSollte man seinen Zug beenden wollen bzw. muessen ,so muss man min. gleich"
		"\nviele Todesstrahler wie Panzer haben."
		"\nAnsonsten bekommt man 0 Punkte."
		"\nBei diesem PC-Spiel kann man die Schwierigkeit einstellen."
		"\nBei hoeherer Schwierigkeit erhoeht sich"
		"\ndie Chanche auf einen Panzer."
		"\n\nMan gibt seine Auswahl mit den Zahlen 1 - 9 an und bestaetigt mit \"Enter\"";
}

std::string StartScreen::ShowTitle()
{
	return title;
}

std::string StartScreen::ShowHelp()
{
	return help;
}

std::string StartScreen::ShowMiniHelp()
{
	return minihelp;
}
