#include <stdio.h>

#include <conio.h>

#include <windows.h>


int gotoxy(int x, int y)

{

	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	return 0;

}


void c_Cdwga(char cArr[][4]);

void c_Cdwgk(const char cKrr[][4]);

void c_Cdwg(void);

char c_Kch(char cKc, int nBlank);

int c_MoveCubic(char cArr[][4], char cKget, int nBlank);


int main(void)

{

	char cArr[4][4];

	char cKget, cKindx;

	int  nBlank = 15, iNtotal = 0;

	int  iNm1, iNm2, iNm3, iNmslp;

	int  bGame = 1;

	int  iRn, iRseed, iRs1 = 0, iRs2 = 0;

	const char cKrr[4][4] = { { '1','2','3','4' },{ '5','6','7','8' },

	{ '9','A','B','C' },{ 'D','E','F',' ' } };



	for (iNm1 = 0; iNm1<4; iNm1++)

		for (iNm2 = 0; iNm2<4; iNm2++)

			cArr[iNm1][iNm2] = cKrr[iNm1][iNm2];

	c_Cdwg();

	c_Cdwga(cArr);

	c_Cdwgk(cKrr);	//puzzle initialize


					// seed�Է��� ������ ������ Ű�� ���� ����

	gotoxy(0, 12);

	printf("������ ���� seed�Է��ϼ���(100~30000) : ");

	scanf_s("%d", &iRseed);

	srand(iRseed);

	iNmslp = (int)(32767 / (iRseed * 10));


	for (iNm1 = 1; iNm1 <= iRseed; iNm1++)

	{

		iRn = rand();		//������ ���� ���� ���� Ű ����

		iNm2 = iRn % 4;


		switch (iNm2)

		{

		case 0:		cKget = 'a';	break;

		case 1:		cKget = 'd';	break;

		case 2:		cKget = 'z';	break;

		case 3:		cKget = 'w';

		}



		cKindx = c_Kch(cKget, nBlank);    //������ �� �ִ� ��ġ �˻�

		if (cKindx == 'm')

		{

			nBlank = c_MoveCubic(cArr, cKget, nBlank);

			gotoxy(0, 11);

			printf("���� ����  %d", iNm1);

			cKget = ' ';

			cKindx = 'n';

			Sleep(iNmslp);

		}

	}



	gotoxy(0, 12);

	printf("                                                                                 \n");


	// Ű �Է¿� ���� ���� ���� ���� �κ�

	do

	{

		cKget = ' ';



		// do~ while touch key 'a d z w n'

		do

		{
			gotoxy(0, 12);

			printf("move(adwz)quit(n) :  ");

			cKget = _getch();

			printf("%c", cKget);



		} while ((cKget != 'a') && (cKget != 'd') && (cKget != 'w') && (cKget != 'z') && (cKget != 'n'));



		// n --> game quit

		if (cKget == 'n')

		{
			gotoxy(0, 16);

			printf("������ �׸��Ӵϴ�.\n");

			bGame = 0;

			break;

		}

		// move puzzle by key input

		else

		{

			cKindx = c_Kch(cKget, nBlank);

			if (cKindx == 'm')

			{

				nBlank = c_MoveCubic(cArr, cKget, nBlank);

				iNtotal++;    // total movement

			};

		}



		iNm3 = 0;

		for (iNm1 = 0; iNm1<4; iNm1++)

			for (iNm2 = 0; iNm2<4; iNm2++)

				if (cArr[iNm1][iNm2] == cKrr[iNm1][iNm2])   // check for complete

					iNm3++;



		gotoxy(0, 14);		// ���� �̵���Ȳ�� ǥ��

		printf("Blank��ġ : %3d\t �������� :%3d\t �̵�Ƚ�� :%6d", nBlank, iNm2, iNtotal);



		// �ϼ� ����� ���� ���� �˻� ��� ��� ������ ���� ����

		if (iNm3 == 16)

		{

			bGame = 0;

			gotoxy(0, 16);

			printf("������ ��� %dȸ �̵��Ͽ� ���߼̽��ϴ�.\n\n\n", iNtotal);

		}



	} while (bGame == 1);


	return 0;

}



void c_Cdwga(char cArr[][4])

{

	// cArr ���� ���� �׸���



	int i = 0, j = 0, x = 0, y = 0;

	gotoxy(29, 1);

	for (i = 0; i<4; i++)

		for (j = 0; j<4; j++)

		{

			x = 2 + 4 * j;

			y = 1 + 2 * i;

			gotoxy(x, y);

			printf("%c", cArr[i][j]);

		}

}


void c_Cdwgk(const char cKrr[][4])

{	// draw complete puzzle

	int i = 0, j = 0, x = 0, y = 0;

	gotoxy(29, 1);

	for (i = 0; i<4; i++)

		for (j = 0; j<4; j++)

		{

			x = 29 + 4 * i;

			y = 1 + 2 * j;

			gotoxy(x, y);

			printf("%c", cKrr[j][i]);

		}


}


void c_Cdwg(void)

{	// draw boundary

	gotoxy(0, 0);

	printf("+---+---+---+---+          +---+---+---+---+\n");

	printf("|   |   |   |   |          |   |   |   |   |\n");

	printf("+---+---+---+---+          +---+---+---+---+\n");

	printf("|   |   |   |   |          |   |   |   |   |\n");

	printf("+---+---+---+---+          +---+---+---+---+\n");

	printf("|   |   |   |   |          |   |   |   |   |\n");

	printf("+---+---+---+---+          +---+---+---+---+\n");

	printf("|   |   |   |   |          |   |   |   |   |\n");

	printf("+---+---+---+---+          +---+---+---+---+\n");

	printf("  parted Puzzle             Complete Puzzle \n");


}


int c_MoveCubic(char cArr[][4], char cKget, int nBlank)

{	// �̵��� ���� ť�� ���� ���� �Լ�

	int i, j, x = 0, y = 0;

	i = nBlank / 4;

	j = nBlank % 4;


	switch (cKget)

	{

	case 'a':

		cArr[i][j] = cArr[i][j + 1];

		x = 2 + 4 * j;

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", cArr[i][j]);



		cArr[i][j + 1] = ' ';

		x = 2 + 4 * (j + 1);

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", ' ');


		nBlank += 1;

		break;

	case 'd':

		cArr[i][j] = cArr[i][j - 1];

		x = 2 + 4 * j;

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", cArr[i][j]);



		cArr[i][j - 1] = ' ';

		x = 2 + 4 * (j - 1);

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", ' ');


		nBlank -= 1;

		break;

	case 'z':

		cArr[i][j] = cArr[i - 1][j];

		x = 2 + 4 * j;

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", cArr[i][j]);



		cArr[i - 1][j] = ' ';

		x = 2 + 4 * j;

		y = 1 + 2 * (i - 1);

		gotoxy(x, y);

		printf("%c", ' ');

		nBlank -= 4;

		break;

	default:

		cArr[i][j] = cArr[i + 1][j];

		x = 2 + 4 * j;

		y = 1 + 2 * i;

		gotoxy(x, y);

		printf("%c", cArr[i][j]);



		cArr[i + 1][j] = ' ';

		x = 2 + 4 * j;

		y = 1 + 2 * (i + 1);

		gotoxy(x, y);

		printf("%c", ' ');

		nBlank += 4;

	}



	cKget = ' ';

	return nBlank;

}


char c_Kch(char cKc, int nBlank)

{	// �����ϼ� ���� Ű �Է� �˻�

	char cKindx;


	if (cKc == 'z' && nBlank <= 3)

		cKindx = 'n';

	else if (cKc == 'w' && nBlank >= 12)

		cKindx = 'n';

	else if ((cKc == 'd') && ((nBlank == 0) || (nBlank == 4) || (nBlank == 8) || (nBlank == 12)))

		cKindx = 'n';

	else if ((cKc == 'a') && ((nBlank == 3) || (nBlank == 7) || (nBlank == 11) || (nBlank == 15)))

		cKindx = 'n';

	else

		cKindx = 'm';


	return cKindx;

}
