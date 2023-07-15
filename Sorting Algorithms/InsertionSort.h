#pragma once

template <typename T>

void InsertionSort(T* arr, int size)
{
	T currentval;

	int currentpos = 0;

	bool check = true;

	for (int i = 0; i < size - 1; i++)
	{
		currentpos = i + 1;

		currentval = arr[currentpos];

		check = true;

		while (currentval < arr[currentpos - 1] && currentpos > 0)
		{
			arr[currentpos] = arr[currentpos - 1];
			currentpos--;
			check = false;
		}
		
		if (check == true)
		{
			return;
		}

		arr[currentpos] = currentval;

	}







}
