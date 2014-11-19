#include "stdafx.h"
#include <iostream>
using namespace std;
int* merge(int* arr1, int*arr2, int n1, int n2,int* res)
{
	int* result = new int[n1 + n2];
	//i,j и k са съответно индексите на двата масива,които ще сравняваме и резултатния
	for (int i = 0, j = 0, k = 0; i < n1 || j < n2;){
		//Сравняваме елементите на двата масива,когато индексите са по-малки от размера на масивите
		if (arr1[i] < arr2[j] && i < n1 && j < n2)
		{
			result[k] = arr1[i];
			k++;
			i++;
		}
		//Сравняваме двата масива, когато първият масив е по-малък и елементите на втория са свършили
		else if (i < n1 && j >= n2)
		{
			result[k] = arr1[i];
			k++;
			i++;
		}
		//Сравняваме двата масива, когато вторият масив е по-малък
		else
		{
			result[k] = arr2[j];
			k++;
			j++;
		}
		return result;
	}
}
int n1, n2;
int* res;
int* MergeSort(int* arr, int n)
{
	if (n == 1){
		//result = new int[1];
		//result[0] = arr[0];
		return arr;
	}
	// Заделяне на памет на масивите зададени динамично
	int* arr1, *arr2;
	arr1 = new int[n1];
	arr2 = new int[n2];
	// Merge sort на масива с елементи до половината
	MergeSort(arr, n / 2);
	// Merge sort на масива с елементи от втората половина
	MergeSort(arr + n / 2, n - n / 2);
	return merge(arr1, arr2, n / 2, n - n / 2,res);
}
