#include <iostream>
#include <conio.h>
#include "serial.h"
using namespace std;

int main(int argc, char* argv[])
{
	COMPORT* hCom;
	char key = 0;
	BYTE k = 0;
	int Count = 0, i = 0; //�J�E���g
	char data[255]; //Mbed����̃f�[�^�̓ǂݎ��
	int l;
	hCom = NULL;
	hCom = new COMPORT((char*)"\\\\.\\COM12", 230400);//�񌅂̂Ƃ���\\\\.\\COMXX�ɂ�����I

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
			if (key == '\033') { //�d���[���ɖ߂�
				break;
			}
			k = key;
			hCom->transmit(k, 1);
		}
	}
	printf("Press any key to continue...");
	return 0;
}
