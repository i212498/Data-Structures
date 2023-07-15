#pragma once

template <typename T>

int BinarySearch(T tosearch, T* arr, int size)
{
	int first = 0, last = size - 1;

	int mid = 0;
	
	while(first <= last)
	{
		mid = (first + last) / 2;

		if (arr[mid] == tosearch)
		{
			return mid;
		}
		else if (tosearch < arr[mid])
		{
			last = mid - 1;
			continue;
		}
		else if (tosearch > arr[mid])
		{
			first = mid + 1;
			continue;
		}

	}
	
	
	return -1;

}