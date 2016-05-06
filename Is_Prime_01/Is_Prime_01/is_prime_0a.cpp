#include <stdio.h>
#include <stdlib.h>		// atoi ����� ���� 
#include <string.h>		// memset ����� ���� 

int main(int argc, char* argv[])
{
	// ���ڰ� �־�� ��. 
	if (argc < 2) {
		printf("Usage : prime2 [integer]\n");
		return 0;
	}

	// �־��� ���ڴ� 2���� ū ������ ��. 
	int n = atoi(argv[1]);
	if (n < 2) {
		printf("Error : n must be greater than 1\n");
		return 0;
	}

	int *parray;

	// �޸��� �Ҵ� 
	parray = new int[n + 1];
	if (parray == 0) {
		printf("Error : memory allocation failed\n");
		return 0;
	}

	// �޸𸮸� 0���� �ʱ�ȭ 
	memset(parray, 0, sizeof(int)*(n + 1));

	int i, j;
	// �Ҽ� ���ϱ� ���� 
	for (i = 2; i <= n; i++) {
		if (parray[i] == 1)		// �̹� ������ �� �� �Ҽ��� �ƴϸ� �� �������� �Ѿ��. 
			continue;
		j = i;		// i�� �������� �ؼ� 
		while ((j += i) <= n) {
			parray[j] = 1;			// i�� ������� �Ҽ��� �ƴ϶�� ��ŷ��. 
		}
	}

	// �Ҽ��� ��� 
	for (i = 2; i <= n; i++) {
		if (parray[i] == 0)
			printf("%d ", i);
	}
	printf("\n");

	// �Ҵ�� �޸𸮸� ���� 
	delete[] parray;
	return 0;
}