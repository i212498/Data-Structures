#pragma once

template <typename T>

void BubbleSort(T* arr, int size)
{
	T temp;

	bool check = true;

	for (int i = 0; i < size - 1; i++)
	{
		check = true;

		for (int j = 0; j < size - (i + 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				check = false;
				
				temp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = temp;
			}
		}

		if (check == true)
		{
			return;
		}
	}

}