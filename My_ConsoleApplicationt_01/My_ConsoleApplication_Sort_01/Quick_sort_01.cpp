#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

//
//입력받은 icount수 만큼의 값을 차례로 입력받아
//올림차순으로 정렬
//그러나 아직은 100개

void quicksort(int *a, int low, int high, int *swap_Count);
int partition(int *a, int low, int high, int *swap_Count);
void swap(int *a, int left, int right);
int goto_Cursor_xy(short x, short y);
void put_Cursor_xy(int x, int y, int xyvalue);

#define SORTNUMBER 800

int main(void)
{
	const int icount = SORTNUMBER;
	int my_Sort[SORTNUMBER] = { 0 };
	int arr_Count[SORTNUMBER] = { 0 };
	const int output_Width = 4;
	const int offset_Y = 1;
	const int num_X = 20;
	int num_Y;
	num_Y = sizeof(my_Sort) / 4 / num_X;
	int swap_Count = 0;

	srand((unsigned)time(NULL));

	printf("배열배치  섞는중입니다\n");
	int iRandom = 0;
	for (int i = 1; i <= icount; i++)
	{
		my_Sort[i - 1] = i;
		arr_Count[i - 1] = i;
	}
	for (int i = icount; i>0; i--)
	{
		iRandom = rand() % i;
		my_Sort[i - 1] = arr_Count[iRandom];
		for (int j = iRandom; j < (i - 1); j++)
			arr_Count[j] = arr_Count[j + 1];
	}
	
	for (int i = 0; i < icount; i++)
	{
		//		my_Sort[i] = rand() % 900;		//배열에 램덤수를 대입
		printf("%4d", my_Sort[i]);
	}

	Sleep(3000);

	goto_Cursor_xy(0, offset_Y-1);
	printf("오름차순 정렬입니다");


	quicksort(my_Sort, 0, icount - 1, &swap_Count);

	goto_Cursor_xy(0, 42);

	return 0;
}


int goto_Cursor_xy(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return 0;
}

void put_Cursor_xy(int x, int y, int xyvalue)
{
 	Sleep(1);

	goto_Cursor_xy(x, y);
	printf("%4d", xyvalue);
}

void swap(int *quick_Sort, int left, int right)
{
	int temp;
	int x, y;
	const int offset_Y = 1;
	const int output_Width = 4;
	const int num_X = 20;
	int num_Y;
	num_Y = sizeof(*quick_Sort) / 4 / num_X;

	temp = quick_Sort[left];
	quick_Sort[left] = quick_Sort[right];
	quick_Sort[right] = temp;

	x = (left % num_X) * output_Width;
	y = offset_Y + (left / num_X);
	put_Cursor_xy(x, y, quick_Sort[left]);

	x = (right % num_X) * output_Width;
	y = offset_Y + (right / num_X);
	put_Cursor_xy(x, y, quick_Sort[right]);

}//end swap

void quicksort(int *quick_Sort, int low, int high, int *swap_Count)
{
	int pivot;
	// Termination condition! 
	if (high > low)
	{
		pivot = partition(quick_Sort, low, high, swap_Count);
		quicksort(quick_Sort, low, pivot - 1, swap_Count);
		quicksort(quick_Sort, pivot + 1, high, swap_Count);
	}

} //end quicksort

int partition(int *quick_Sort, int low, int high, int *swap_Count)
{
	int left, right;
	int pivot_item;
	int pivot;
	left = low;
	right = high;
	pivot = low;
	pivot_item = quick_Sort[low];

	const int offset_Y = 1;
	goto_Cursor_xy(23, offset_Y-1);
	printf("Pivot ( %4d )", pivot_item);

	while (left < right)
	{
		// Move left while item < pivot 
		while (quick_Sort[left] <= pivot_item)
			left++;
		// Move right while item > pivot 
		while (quick_Sort[right] > pivot_item)
			right--;
		if (left < right)
		{
			swap(quick_Sort, left, right);
			*swap_Count = (*swap_Count) + 1;
			goto_Cursor_xy(40, offset_Y - 1);
			printf("swap_Count ( %4d )", *swap_Count);

		}
	}

	// right is final position for the pivot 
	quick_Sort[low] = quick_Sort[right];
	quick_Sort[right] = pivot_item;

	int x, y;
	const int output_Width = 4;
	const int num_X = 20;
	int num_Y;
	
	num_Y = sizeof(*quick_Sort) / output_Width / 20;
	x = (low % num_X) * output_Width;
	y = offset_Y + (low / num_X);
	put_Cursor_xy(x, y, quick_Sort[low]);

	num_Y = sizeof(*quick_Sort) / output_Width / 20;
	x = (right % num_X) * output_Width;
	y = offset_Y + (right / num_X);
	put_Cursor_xy(x, y, quick_Sort[right]);

	return right;
}//end partition

