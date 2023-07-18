#pragma once

void Merge(int *arr1, int *arr2, int size1, int size2)      // only made for ur algo, will not work for others!!
{
    int tsize = size1 + size2;      // add size of both arrays 

    int* temp = new int[tsize];     // and initilize a temp array of that size

    int i = 0, j = 0, k = 0;        // counters for arr1, arr2, temp respectively

    while ( !(i == size1 && j == size2) )
    {

        if (i == size1)                // if reach end of arr1 add remaining elements of arr2 to temp
        {
            temp[k] = arr2[j];
            k++;
            j++;
        }
        else if (j == size2)                // if reach end of arr2 add remaining elements of arr1 to temp
        {
            temp[k] = arr1[i];
            k++;
            i++;
        }

        if (i != size1)                     // if arr1 in bounds
        {
            if (arr1[i] < arr2[j])          // if arr1 element is smaller than arr2 add it to temp
            {
                temp[k] = arr1[i];
                k++;
                i++;
            }

        }
        
        if (j != size2)                     // if arr2 in bounds
        {
            if (arr2[j] < arr1[i])          // if arr2 element is smaller than arr1 add it to temp
            {
                temp[k] = arr2[j];
                k++;
                j++;
            }
        }
        
        if (i != size1 && j != size2)
        {
            if (arr1[i] == arr2[j])
            {
                temp[k] = arr1[i];
                k++;
                i++;
            }
        }

    }

    for (int i = 0; i < tsize; i++)         // Merge Sort specific code
    {
        arr1[i] = temp[i];                  // copy values of temp from start of first half
    }

    delete[] temp;

    temp = 0;
    
}

void MergeSort(int *arr, int size)
{
    if (size > 2)                       // if size > 2 then call merge sort again
    {
        int temp = 0;

        if(size % 2 == 0)               // if array of of even size e.g 2,4,6,8
        {
            temp = size / 2;            // div size by 2 and save in temp e.g 4 / 2 = 2

            MergeSort(arr, temp);       // call MergeSort again with first half e.g 2,4 

            arr = arr + temp;           // inc ptr to move to second half

            MergeSort(arr, temp);       // call with second half

            arr = arr - temp;           // decrement ptr again to move to start of first half

            Merge(arr, arr + temp, temp, temp); // merge both halves

        }
        else if (size % 2 == 1)         // if array is of odd size  e.g 2,4,6
        {
            temp = size / 2;            // div size by 2 e.g 3 / 2 = 1
            temp++;                     // inc by 1 e.g 1 + 1 = 2

            MergeSort(arr, temp);       // call merge sort again with bigger first half  

            arr = arr + temp;           // mov ptr to second smaller half

            MergeSort(arr, temp - 1);   // call merge sort again with second smaller half

            arr = arr - temp;           // mov ptr back to first array

            Merge(arr, arr + temp, temp, temp - 1); //merge both halves
        }
      
    }
    else if(size == 2)      //if size == 2 cmp and swap values
    {
        
        int temp2 = 0;

        if (*arr > *(arr + 1))      // cmp both values and swap if needed e.g 8, 4
        {
            temp2 = *arr;
            *arr = *(arr + 1);
            *(arr + 1) = temp2;

        }
    }
    else if (size == 1)
    {
        return;
    }
    
}

