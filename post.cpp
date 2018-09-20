#include<string>
#include"prerequisite.h"
#include<fstream>
#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	//向本机Web目录下面的welcome.php页面发送发送
	std::string httppost;
	
	string temp;
	int counterpart=0;
	int num = 0;
	while (true) {

		fstream fin("C:/Users/Paul Xia/Desktop/ReadByPost.txt");
		Sleep(2000);
		while (getline(fin, temp))
		{
			httppost = temp;
			++num;
		}


		if (num != counterpart) {
			PostHttpPage("localhost", "/api/abc", httppost);
			counterpart = num;
		}
	}
}



	//if (fin.is_open()) {
	//	fin.seekg(-1, ios_base::end);                // go to one spot before the EOF

	//	bool keepLooping = true;
	//	while (keepLooping) {
	//		char ch;
	//		fin.get(ch);                            // Get current byte's data

	//		if ((int)fin.tellg() <= 2) {             // If the data was at or before the 0th byte
	//			fin.seekg(0);                       // The first line is the last line
	//			keepLooping = false;                // So stop there
	//		}
	//		else if (ch == '\n') {                   // If the data was a newline
	//			keepLooping = false;                // Stop at the current position.
	//		}
	//		else {                                  // If the data was neither a newline nor at the 0 byte
	//			fin.seekg(-2, ios_base::cur);        // Move to the front of that data, then to the front of the data before it
	//		}
	//	}

	//	string lastLine;
	//	getline(fin, lastLine);                      // Read the current line
	//	cout << "Result: " << lastLine << '\n';     // Display it

	//	fin.close();
	//}

	

		//while (true)
		//{
		//	Sleep(2000);
		//	PostHttpPage("localhost", "api.js", a);
		//}
