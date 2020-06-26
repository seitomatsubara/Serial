#include <iostream>
#include <conio.h>
#include "serial.h"
using namespace std;

int main(int argc, char* argv[])
{
	COMPORT* hCom;
	char key = 0;
	BYTE k = 0;
	int Count = 0, i = 0; //カウント
	char data[255]; //Mbedからのデータの読み取り
	int l;
	hCom = NULL;
	hCom = new COMPORT((char*)"\\\\.\\COM12", 230400);//二桁のときは\\\\.\\COMXXにするんや！

	while (1)
	{
		l = hCom->ClearError();
		if (l > 0 && Count == 0) {
			i = 0;
			while (data[i] != NULL) {
				data[i] = NULL;
				i++;
			}
			hCom->receive(data, l);
			cout << data;
		}
		if (_kbhit()) {

			key = _getch();
			if (key == '\033') { //電流ゼロに戻す
				break;
			}
			k = key;
			hCom->transmit(k, 1);
		}
	}
	printf("Press any key to continue...");
	return 0;
}
