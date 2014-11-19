#include<iostream>
using namespace std;

/* Програмата реализира алгоритъм за сортиране Quick Sort */

/* Помощна рекурсивна функция за сортиране на интервал от масива
с аргументи масив от числа, лява граница и дясна граница на интервала */
void IntervalSort(int* myArray, int leftBound, int rightBound)
{
	/* Итератори, които се инициализират с лявата и дясната граница на интервала
	и служат за обхождане на масива от ляво на дясно(leftIndex) и от дясно на ляво(rightIndex) */
	int leftIndex = leftBound;
	int rightIndex = rightBound;

	/* Променлива, която съхранява pivot, а именно случайно избрано от интервала число, спрямо което
	числата от интервала се разделят на два нови интервала: 
		- числа по-малки или равни на pivot 
		- числа по-малки или равни на pivot 
	В примера на всяка стъпка се избира първият елемент на масива. */
	int pivot = myArray[leftBound];

	/* Дъно на рекурсията:
	ако лявата граница и дясната граница на интервала са равни,
	то интервала се състои от едно единствено число, което само по себе си е сортирано. */
	if(leftIndex != rightIndex)
	{
		/* Цикъл който продължава докато итераторите leftIndex и rightIndex 
		не се разминат, т.е. leftIndex > rightIndex */
		while(leftIndex <= rightIndex)
		{
			// Обхождане на интервала от ляво на дясно до достигане на по-голямо или равно на pivot число 
			while(pivot > myArray[leftIndex])
			{
				leftIndex++;
			}

			// Обхождане на интервала от ляво на дясно до достигане на по-малко или равно на pivot число 
			while(pivot < myArray[rightIndex])
			{
				rightIndex--;
			}

			// Проверка дали индексите все още не са се разминали
			if(leftIndex <= rightIndex)
			{
				/* Ако елемента, който сочи левият индекс не е равен на елемента,
				който сочи десният, то двата елемента разменят стойностите си */
				if(myArray[leftIndex] != myArray[rightIndex])
                    swap(myArray[leftIndex], myArray[rightIndex]);

				// Итераторите се променят за да продължи обхождането до тяхното разминаване
				leftIndex++;
				rightIndex--;
			}
		}
		/* Рекурсивни извиквания за новополучените подинтервали:
		При разминаване на  rightIndex и leftIndex са възможни два случая:
			- между тях да няма други индекси на интервала(ако преди последната им промяна leftIndex < rightIndex)
			- между тях има един индекс(ако при последната им промяна leftIndex = rightIndex)
		Поради тази причина първият подинтервал е с дясна граница десния индекс,който сочи последното по-малко или равно на pivot число в интервала
		увеличен с едно, зa да включи индекса във втория случай на разминаване. Лява граница на първия първия подинтервал е лявата граница на обходения масив.
		Лява граница на втория е индекса, койо сочи първото по-голямо или равно на pivot число в интервала. В първичт случаи на разминаване ще се случи така, че един елемент да 
		бъде част и от двата интервала, но тъй като се обхожда първо левия подинтервал този елемент вече ще бъде сортиран и неговото повторно обхождане няма да повлияе на алгоритъма.
		Дясната граница на втория подинтервал е дясната граница на обходения интервал. */
		IntervalSort(myArray, leftBound, rightIndex+1);
		IntervalSort(myArray, leftIndex, rightBound);
	}
	else return;
}

// Функция, която извиква рекурсивната IntervalSort за интервал от началото на масива до края му
void QuickSort(int* myArray, int size)
{
	int leftBound = 0;
	int rightBound = size-1;
	IntervalSort(myArray, leftBound, rightBound);
}
int main()
{
	int* myArray;
	int size, counter = 0;
	cout<<"Enter array size: ";
	cin>>size;
	myArray = new int[size];
	for(int counter = 0; counter < size; counter++)
	{
		cout<<"Enter "<<counter+1<<" number: ";
		cin>>myArray[counter];
		cout<<endl;
	}
	QuickSort(myArray,size);
	cout<<"The sorted array is: "<<endl;
	for(counter = 0; counter < size; counter++)
	{
		cout<<myArray[counter]<<" ";
	}
	cout<<endl;
	delete [] myArray;
	return 0;
}
