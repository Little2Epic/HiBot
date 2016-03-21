#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


std::string CopyClipboardToString()
{
	std::string Message;

	if (OpenClipboard(NULL))
	{
		HANDLE ClipBoard = GetClipboardData(CF_TEXT);

		if (!ClipBoard)
		{
			CloseClipboard();
			return Message;
		}

		Message = (char*)ClipBoard;
		CloseClipboard();
	}

	return Message;
}

void CopyStringtoClipboard(const std::string & s)
{
	OpenClipboard(NULL);
	EmptyClipboard();

	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());

	if (!hg)
	{
		CloseClipboard();
		return;
	}

	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

void ClickOnce()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
}

void Paste()
{
	const UINT VK_V = 0x56;
	keybd_event(VK_LCONTROL, MapVirtualKey(VK_LCONTROL, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_V, MapVirtualKey(VK_V, MAPVK_VK_TO_VSC), NULL, NULL);
	keybd_event(VK_V, MapVirtualKey(VK_V, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_LCONTROL, MapVirtualKey(VK_LCONTROL, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, NULL);
}


int main() {
	string foo;
	float secretcoms = 0;
	float regularcoms = 0;
	float invaildcommands = 0;
	float vaildcommands = 0;
	string clue[4] = { "A shift of three is the only key", "Vzhdwv dqg Frglq vlwwlqj lq d wuhh", "Brx ixfnlqj orvhu", "Wrr hslf iru brx" };
	string flirt[5] = { "Are you a camera? Cause everytime I look at you I smile.", "Wanna know what's the best thing in my life? The first word in the first sentence.", "Are you butt dialing? Cause I SWEAR that ass is calling me.", "That's a nice shirt! Can I talk you out of it?", "You must be a keyboard, cause you're just my type." };
	cout << "***************************************************\n*Hello and welcome to HiBot!                      *\n*I'm delighted to see you once more.              *\n*Type !tut if you're new here.                    *\n*Type !list to see the normal commands.           *\n*Type !clues to help you find secret commands.    *\n*Type !end to end the program.                    *\n*Copyright 2016 Little2Epic                       *\n***************************************************\n";
	while (getline(cin, foo)) {
		if (foo == "!hi") {
			cout << "Ayy what up! \n";
			regularcoms ++;

		}
		else if (foo == "!kys") {
			cout << "Oh okay then... :( \n";
			return 0;
		}
		else if (foo == "!about") {
			cout << "Hello, I'm HiBot. Thanks to Sweats, the creator was able to create me. I'm created to assist you during your free time. I'm fairly simple, I just do a few commands. Recommend some to L2E, maybe it'll be added! \n";
			regularcoms ++;
		}
		else if (foo == "!creator") {
			cout << "I was created by Little2Epic on his birthday, March 20, 2016. \n";
			regularcoms ++;
		}
		else if (foo == "!version" || foo == "!ver") {
			cout << "I'm currently running version 0.5.1 alpha. \n";
			regularcoms ++;
		}
		else if (foo == "!list") {
			cout << "Displaying 6 out of 24 commands. \n !hi - I say hi. \n !kys - Makes me feel bad... \n !about - Tells you a tad bit about me. \n !creator - Tells you who created me. \n !list - Displays the command list. \n !end - Ends the program. \n Type !list2 for more commands. \n";
			regularcoms ++;
		}
		else if (foo == "!flirt") {
			int pos = rand() % 5;
			cout << flirt[pos] << endl;
			regularcoms ++;
		}
		else if (foo == "!end") {
			return 0;
		}
		else if (foo == "ur a bot" || foo == "you're a bot") {
			cout << "Bitch please *hairflip* \n";
		}
		else if (foo == "!lenny") {
			cout << "r u redi 4 mi \n";
			secretcoms ++;
		}

		else if (foo == "!contactme") {
			cout << "You can contact the owner via the following: \n Twitter - @trevion_fiasco \n Kik - Little2Epic \n XDA - Little2Epic \n Snapchat - trevion_fiasco \n Instagram - @trevion_fiasco \n reddit - Little2Epic \n";
			regularcoms ++;
		}
		else if (foo == "!little2epic") {
			cout << "shhh we can't speak of him... \n";
			secretcoms ++;
		}
		else if (foo == "!sweats") {
			cout << "Without Sweats, I probably wouldn't exist. Thank him when you get the chance! \n";
			secretcoms ++;
		}
		else if (foo == "!codinbot") {
			cout << "ooo my botfriend. he makes my soft drive into a hard drive <3 \n";
			secretcoms ++;
		}
		else if (foo == "!welp") {
			cout << "I'm not a major loser! D:< \n";
			secretcoms ++;
		}
		else if (foo == "!clues") {
			int pos = rand() % 4;
			cout << clue[pos] << endl;
			regularcoms ++;
		}
		else if (foo == "!list2") {
			cout << "Displaying 12 out of 24 commands. \n !flirt - Let's get kinky tonight ;) \n !lenny - Displays a lenny faec (Not Working atm). \n !contactme - Provides ways to contact the creator \n  !clues - Provides hints in finding secret commands. \n !tut - Gives you a rundown on how I work.\n !plans - Lists the creator's future plans for HiBot \n Commands tba...";
			regularcoms ++;
		}
		else if (foo == "!tut") {
			cout << "I work by reading commands and outputing what is commanded. You have a wide variety of commands (and some phrases) that I can understand. Wanna try? Type !list. \n";
			regularcoms ++;
		}
		else if (foo == "!plans") {
			cout << "Top Priorities: \n *To be able to use your name (to greet you and stuff, nothing else). \n *To implement new games \n *Translations (at least in Español) \n *To hit 24 commands! (Twelve at the moment)\n";
			regularcoms ++;
		}
		else if (foo == "!stats") {
			cout << " Regular Commands Read:" << regularcoms << "\n Secret Commands Read:" << secretcoms << "\n Invaild Commands:" << invaildcommands << endl;
		}
		else if (foo != "!hi" || foo != "!kys" || foo != "!about" || foo != "!creator" || foo != "!version" || foo != "!list" || foo != "!end" || foo != "!flirt" || foo != "!lenny" || foo != "!contactme" || foo != "!little2epic" || foo != "!sweats" || foo != "!codinbot" || foo != "!weml" || foo != "!clues" || foo != "!list2" || foo != "!tut" || foo != "!plans" || foo != "!stats" || foo != "ur a bot" || foo != "you're a bot" ) {
			cout << "This isn't a vaild command or phrase... \n";
			invaildcommands++;
		}
		else if (foo == "!") {
			cout << "";
		}
	}
}
