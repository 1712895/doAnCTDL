#pragma once
#ifndef _Sort 
#define _Sort
template <class T>
void selectionSort(T a[], int n);
//template <class T>
//void swap(T &a, T &b);
template <class T>
void insertionSort(T a[], int n);
template <class T>
void binaryInsertionSort(T a[], int n);
template <class T>
void binaryInsertionSort(T a[], int n);
template <class T>
void interChangeSort(T a[], int n);
template <class T>
void bubleSort(T a[], int n);
template <class T>
void shakerSort(T a[], int n);
template <class T>
void shellSort(T a[], int n);
template <class T>
void heapify(T a[], int n, int i);
template <class T>
void heapSort(T a[], int n);
template <class T>
void Merge(T a[], int left, int mid, int right);
template <class T>
void mergesort(T a[], int left, int right);
template <class T>
void quicksort(T a[], int l, int r);
template <class T>
void countingSort(T a[]);
template <class T>
void flashsort(T array[], int length);
template <class T>
void radixsort(T a[], int n);
template <class T>
void countSort(T a[], int n, int exp);
template <class T>
int getMax(T a[], int n);
void taoFile();
void chaySort();
void fileResult();
#endif