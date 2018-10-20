#include"Sort.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<fstream>
#include<string>
#include <sstream>
#include <time.h>
#include<conio.h>
using namespace std;
//template <class T>
//void swap(T &a, T &b)
//{
//	T x;
//	x = a;
//	a = b;
//	b = x;
//}
template <class T>
void selectionSort(T a[], int n)
{
	int i, j, min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}
template <class T>
void insertionSort(T a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
template <class T>
void binaryInsertionSort(T a[], int n)
{
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);
		while (j>=loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}
template <class T>
T binarySearch(T a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == a[mid])
		return mid + 1;
	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}
template <class T>
void interChangeSort(T a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
template <class T>
void bubleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
		}
	}
}
template <class T>
void shakerSort(T a[], int n)
{
	int l = 0;
	int r = n - 1;
	int k = n - 1;
	while (l < r)
	{
		int j = r;
		while (j > l)
		{

			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				k = j;
			}
			j--;
		}
		l = k;
		j = l;
		while (j < r)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = j;
			}
			j++;
		}
		r = k;
	}
}
template <class T>
void shellSort(T a[], int n)
{
	int i, j, k, temp;
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j <(n/2); j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				if (a[k + i] >= a[k])
				{
					break;
				}
				else
				{
					std::swap(a[k],a[k + i]);
				}
			}
		}
	}
}
template <class T>
void heapify(T a[], int n, int i)
{ 
	int largest = i;  
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 
	if (l < n && a[l] > a[largest])
	{
		largest = l;
	}
	if (r < n && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
        heapify(a, n, largest);
	}
}
template <class T>
void heapSort(T a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
template <class T>
void Merge(T a[], int left, int mid, int right)
{
	int *temp; 
	int i = left; 
	int j = mid + 1; 
    temp = new int[right - left + 1]; 
    for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++; 
		}
		else 
		{
			temp[k] = a[j];
			j++; 
		}
		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}
		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++) 
	{
		a[left + k] = temp[k];
	}
	delete temp;
}
template <class T>
void mergesort(T a[], int left, int right)
{
	if (right > left)
	{
		int mid; 
		mid = (left + right) / 2;
		mergesort(a, left, mid); 
		mergesort(a, mid + 1, right); 
		Merge(a, left, mid, right); 
	}
}
template <class T>
void quicksort(T a[], int l, int r)
{
	int i = l;
	int j = r;
	int x = a[(l + r) / 2];
	do
	{
		while (a[i] < x) {
			i++; 
		}
		while (a[j] > x) { j--; }

		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
      if (l<j)
	{
		quicksort(a, l, j);
}
	if (i < r)
	{
	quicksort(a, i, r);
	}
}
template <class T>
void countingSort(T a[])
{
	char output[strlen(a)]; 
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count)); 
	for (i = 0; a[i]; ++i)
		++count[a[i]];
	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];
	for (i = 0; a[i]; ++i)
	{
		output[count[a[i]] - 1] = a[i];
		--count[a[i]];
	} 
	for (i = 0; a[i]; ++i)
		a[i] = output[i];
}
template <class T>
int getMax(T a[], int n)
{
    int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
    return max;
}
template <class T>
void countSort(T a[], int n, int exp)
{ 
	int *output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = output[i];
	}	delete[]output;
}
template <class T>
void radixsort(T a[], int n)
{

	int exp, m;
	m = getMax(a, n);
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(a, n, exp);

	}
}
template <class T>
void flashsort(T array[], int length)
{
	if (length == 0) return;
	int m = (int)((0.2 * length) + 2);
	int min, max, maxIndex;
	min = max = array[0];
	maxIndex = 0;
    for (int i = 1; i < length - 1; i += 2)
	{
		int small;
		int big;
		int bigIndex;
		if (array[i] < array[i + 1])
		{
			small = array[i];
			big = array[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = array[i];
			bigIndex = i;
			small = array[i + 1];
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (small < min)
		{
			min = small;
		}
	}
	if (array[length - 1] < min)
	{
		min = array[length - 1];
	}
	else if (array[length - 1] > max)
	{
		max = array[length - 1];
		maxIndex = length - 1;
	}

	if (max == min)
	{
		return;
	}
	int* L = new int[m + 1];
	for (int t = 1; t <= m; t++)
	{
		L[t] = 0;
	}
	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < length; h++)
	{
		K = ((int)((array[h] - min) * c)) + 1;
		L[K] += 1;
	}
	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}
	int temp = array[maxIndex];
	array[maxIndex] = array[0];
	array[0] = temp;
	int j = 0;
	K = m;
	int numMoves = 0;
	while (numMoves < length)
	{
		while (j >= L[K])
		{
			j++;
			K = ((int)((array[j] - min) * c)) + 1;
		}
		int evicted = array[j];
		while (j < L[K])
		{
			K = ((int)((evicted - min) * c)) + 1;
			int location = L[K] - 1;
			int temp = array[location];
			array[location] = evicted;
			evicted = temp;
			L[K] -= 1;
			numMoves++;
		}
	}
	int threshold = (int)(1.25 * ((length / m) + 1));
	const int minElements = 30;
	for (K = m - 1; K >= 1; K--)
	{
		int classSize = L[K + 1] - L[K];
		if (classSize > threshold && classSize > minElements)
		{
			flashsort(&array[L[K]], classSize);
		}
		else 
		{
			if (classSize > 1)
			{
				insertionSort(&array[L[K]], classSize);
			}
		}
	}

	delete[] L;
}
void taoFile()
{
	ostringstream convert;
	time_t t;
	srand((unsigned)time(&t));
	int nhap;
	cout << "nhap n:";
	cin >> nhap;
	int *a = new int [nhap];
	for (int i = 0; i < nhap; i++)
	{
		a[i] = rand() % nhap;
	}
	string mang;
	string tenFile="nearlysorted_";
	convert << nhap;
	mang = convert.str();
	tenFile.append(mang);
	tenFile.append(".inp");
	shellSort(a, nhap);
	ofstream input;
	input.open(tenFile);
	for (int i = 0; i < nhap; i++)
	{
		input << a[i] << " ";
	}
	input.close();
	delete[]a;
}
void chaySort()
{
	string tenFileXuat;
	ifstream file;
	string mang;
	ostringstream convert;
	string tenFile;
	int  nhap1,nhap2;
	cout << "nhap so:";
	cin >> nhap1;
	convert << nhap1;
	mang = convert.str();
	cout << "nhap lua chon:" << endl;
	cout << "1.sort" << endl;
	cout << "2.reversed" << endl;
	cout << "3.random" << endl;
	cout << "4.nearlysorted" << endl;
	cin >> nhap2;
	if (nhap2 == 1)
	{
		tenFile = "sort_";
		tenFile.append(mang);
		tenFileXuat = tenFile;
		tenFile.append(".inp");
		file.open(tenFile);
	}
	else
		if (nhap2 == 2)
		{
			tenFile = "reversed_";
			tenFile.append(mang);
			tenFileXuat = tenFile;
			tenFile.append(".inp");
			file.open(tenFile);
		}else
			if (nhap2 == 3)
			{
				tenFile = "random_";
				tenFile.append(mang);
				tenFileXuat = tenFile;
				tenFile.append(".inp");
				file.open(tenFile);
			}else 
				if (nhap2 == 4)
				{
					tenFile = "nearlysorted_";
					tenFile.append(mang);
					tenFileXuat = tenFile;
					tenFile.append(".inp");
					file.open(tenFile);
				}
			int n = 0;
			int *a = new int  [nhap1];
			while (!file.eof())
			{
				if (file >> a[n])
				{
					n++;
}
			}
			clock_t start, end;
			double b[10];
			for (int i = 0; i < 10; i++)
			{
				start = clock();
				if (i == 0)
				{
					selectionSort(a, nhap1);
				}
				else
					if (i == 1)
					{
						insertionSort(a, nhap1);
					}else if (i == 2)
					{
						binaryInsertionSort(a, nhap1);
					}
					else if (i == 3)
					{
						interChangeSort(a, nhap1);
					}
					else if (i == 4)
					{
						shakerSort(a, nhap1);
					}
					else if (i == 5)
					{
						shellSort(a, nhap1);
					}
					else if (i == 6)
					{
						heapSort(a, nhap1);
					}
					else if (i == 7)
					{
						mergesort(a,0, nhap1-1);
					}
					else if (i == 8)
					{
						quicksort(a, 0,nhap1-1);
					}
					else if (i == 9)
					{
						radixsort(a, nhap1);
					}
				end = clock();
				b[i]= (double)(end - start) / CLOCKS_PER_SEC;
				if (i == 0)
				{
					cout<<"selectionSort:"<<b[i]<<endl;
				}
				else
					if (i == 1)
					{
						cout << "insertionSort" << b[i] << endl;
					}
					else if (i == 2)
					{
						cout << "binaryInsertionSort" << b[i] << endl;
						
					}
					else if (i == 3)
					{
						cout << "interChangeSort" << b[i] << endl;
						
					}
					else if (i == 4)
					{
						cout << "shakerSort" << b[i] << endl;
						
					}
					else if (i == 5)
					{
						cout << "shellSort" << b[i] << endl;
						
					}
					else if (i == 6)
					{
						cout << "heapSort" << b[i] << endl;
						
					}
					else if (i == 7)
					{
						cout << "mergesort" << b[i] << endl;
						
					}
					else if (i == 8)
					{
						cout << "quicksort" << b[i] << endl;
						
					}
					else if (i == 9)
					{
						cout << "radixsort" << b[i] << endl;
						
					}
			}
			ofstream result;
			result.open("Result.csv",ios::app);
			long pos = result.tellp();
			result.seekp(pos);
			string tinhTrang;
			if (nhap2 == 1)
			{
				tinhTrang = "sort";
			}
			else
				if (nhap2 == 2)
				{
					tinhTrang= "reversed";
				}
				else
					if (nhap2 == 3)
					{
						tinhTrang = "random";
					}
					else
						if (nhap2 == 4)
						{
							tinhTrang = "nearlysorted";
						}
			result << tinhTrang<<","<<nhap1;
			for (int i = 0; i < 10; i++)
			{
				result <<"," <<b[i];
			}
			result << "\n";
			ofstream xuatkq, xuatkq1, xuatkq2, xuatkq3, xuatkq4, xuatkq5, xuatkq6, xuatkq7, xuatkq8, xuatkq9;
			string tenSort1, tenSort2,tenSort3, tenSort4, tenSort5, tenSort6, tenSort7, tenSort8, tenSort9, tenSort10;
			for (int i = 0; i < 10; i++)
			{
				if (i == 0)
				{
					tenSort1 ="selectionSort_";
					tenSort1.append(tenFileXuat);
					tenSort1.append(".out");
					xuatkq.open(tenSort1);
					for (int i = 0; i < nhap1; i++)
					{
						xuatkq << a[i] << " ";
					}
				}
				else
					if (i == 1)
					{
					tenSort2 = "insertionSort_";
						tenSort2.append(tenFileXuat);
						tenSort2.append(".out");
						xuatkq1.open(tenSort2);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq1 << a[i] << " ";
						}
					}
					else if (i == 2)
					{
						
						tenSort3 = "binaryInsertionSort_";
						tenSort3.append(tenFileXuat);
						tenSort3.append(".out");
						xuatkq2.open(tenSort3);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq2 << a[i] << " ";
						}
					}
					else if (i == 3)
					{
						
						tenSort4 = "interChangeSort_";
						tenSort4.append(tenFileXuat);
						tenSort4.append(".out");
						xuatkq3.open(tenSort4);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq3 << a[i] << " ";
						}
					}
					else if (i == 4)
					{
						   
						tenSort5 = "shakerSort_";
						tenSort5.append(tenFileXuat);
						tenSort5.append(".out");
						xuatkq4.open(tenSort5);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq4 << a[i] << " ";
						}
					}
					else if (i == 5)
					{
						 
						tenSort6 = "shellSort_";
						tenSort6.append(tenFileXuat);
						tenSort6.append(".out");
						xuatkq5.open(tenSort6);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq5 << a[i] << " ";
						}
					}
					else if (i == 6)
					{
						 
						tenSort7 = "heapSort_";
						tenSort7.append(tenFileXuat);
						tenSort7.append(".out");
						xuatkq6.open(tenSort7);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq6 << a[i] << " ";
						}
					}
					else if (i == 7)
					{
						 
						tenSort8 = "mergesort_";
						tenSort8.append(tenFileXuat);
						tenSort8.append(".out");
						xuatkq7.open(tenSort8);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq7 << a[i] << " ";
						}
					}
					else if (i == 8)
					{
						 
						tenSort9 = "quicksort_";
						tenSort9.append(tenFileXuat);
						tenSort9.append(".out");
						xuatkq8.open(tenSort9);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq8 << a[i] << " ";
						}
					}
					else if (i == 9)
					{
					 
						tenSort10 = "radixsort_";
						tenSort10.append(tenFileXuat);
						tenSort10.append(".out");
						xuatkq9.open(tenSort10);
						for (int i = 0; i < nhap1; i++)
						{
							xuatkq9 << a[i] << " ";
						}
					}
			}
			delete[]a;
}
void fileResult()
{
	ofstream result;
	result.open("Result.csv");
	result << " ,InputState,selectionSort,insertionSort,binaryInsertionSort,interChangeSort,shakerSort,shellSort,heapSort,mergesort,quicksort,radixsort\n";
}