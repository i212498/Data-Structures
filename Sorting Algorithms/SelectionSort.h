#pragma once

template <typename T>

void SelectionSort(T* arr, int size)
{
	T temp, max;

	int maxindex = 0;

	for (int i = 0; i < size - 1; i++)
	{
		max = arr[0];

		for (int j = 1; j < size - i; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				maxindex = j;
			}
		}

		temp = arr[maxindex];

		arr[maxindex] = arr[size - 1 - i];

		arr[size - 1 - i] = temp;


	}



}