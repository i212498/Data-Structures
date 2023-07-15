#pragma once


template <typename T>

int MedianOfThree(T* arr, int low, int high)
{
	int mid = (low + high) / 2;

	if (arr[low] == arr[mid])
	{
		if (arr[low] > arr[high])
		{
			T temp;

			temp = arr[low];

			arr[low] = arr[high];

			arr[high] = temp;

		}

		return mid;

	}

	T smallest, medium, largest;

	int indexs[3] = { low, mid, high };

	smallest = arr[low];

	largest = arr[low];

	for (int i = 0; i < 3; i++)
	{
		if (arr[indexs[i]] < smallest)
		{
			smallest = arr[indexs[i]];
		}

		if (arr[indexs[i]] > largest)
		{
			largest = arr[indexs[i]];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[indexs[i]] != smallest && arr[indexs[i]] != largest)
		{
			medium = arr[indexs[i]];
			break;
		}
	}


	arr[low] = smallest;
	arr[mid] = medium;
	arr[high] = largest;


	return mid;
}


template <typename T>

int Pivotation(T* arr, int low, int high)
{
	int pivotpos = MedianOfThree(arr, low, high);

	T temp, temp2;

	temp = arr[pivotpos];

	arr[pivotpos] = arr[high];

	arr[high] = temp;


	int toright = low, toleft = high - 1;

	while (toright <= toleft)
	{
		if (arr[toright] > temp && arr[toleft] < temp)
		{
			temp2 = arr[toright];

			arr[toright] = arr[toleft];

			arr[toleft] = temp2;

			toright++;
			toleft--;
		}
		
		
		if (arr[toright] < temp)
		{
			toright++;
		}

		if (arr[toleft] > temp)
		{
			toleft--;
		}
	}

	temp2 = arr[toright];

	arr[toright] = arr[high];

	arr[high] = temp2;


	return toright;

}




template <typename T>

void QuickSortAlgo(T* arr, int low, int high)
{
	if (low < high)
	{
		// pivot

		int pivot = Pivotation(arr, low, high);

		// recursion

		QuickSortAlgo(arr, low, pivot - 1);
		QuickSortAlgo(arr, pivot + 1, high);
	}
}

template <typename T>

void QuickSort(T* arr, int size)
{
	QuickSortAlgo(arr, 0, size - 1);

}