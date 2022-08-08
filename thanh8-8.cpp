#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<stdlib.h>
#define max 100
using namespace std;
void merge(int a[], int l, int m, int r) {
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 2, a + r + 1);
	int i(0), j(0);
	while (i<x.size()&&j<y.size())
	{
		if (x[i] < y[j]){
			a[l] = x[i]; ++l; ++i;
		}
		else {
			a[l] = y[j]; ++l, ++j;
		}

	}while (i<x.size())
	{
		a[l] == x[i]; ++i; ++l;
	}
	while (j< y.size())
	{
		a[l] == y[j]; ++j; ++l;
	}
}
void mergesort(int a[], int l, int r) {
	if (l >= r)return;
	int m = (l + r) / 2;
	mergesort(a, l, r);
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
}

int binarySearch(int a[], int l, int r, int x) {
	if (r >= l) {
		int m = l + (r - l) / 2; 

		
		if (a[m] == x)
			return m;

		
		if (a[m] > x)
			return binarySearch(a, l, m- 1, x);

	
		return binarySearch(a, m + 1, r, x);
	}

	return -1;
}

int main() {
	int n; cout << "nhap so luong phan tu cua  mang: "; cin >> n;
	int a[max];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	mergesort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	int x; cout << "nhhap gia tri can tim"; cin >> x; 
		binarySearch(a, 0, n - 1, x);

	return 0;
}