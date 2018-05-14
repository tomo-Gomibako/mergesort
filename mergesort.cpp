#include <iostream>
#include <vector>
using namespace std;

vector<int> mergesort(vector<int> arr) {
	int arr_size = arr.size();
	if(arr_size == 1) return arr;
	int half = (int)(arr_size / 2) + arr_size % 2;
	vector<int> arr1(arr.begin(), arr.begin() + half);
	vector<int> arr2(arr.begin() + half, arr.begin() + arr_size);
	int arr1_size = arr1.size();
	int arr2_size = arr2.size();
	if(arr1_size > 1) arr1 = mergesort(arr1);
	if(arr2_size > 1) arr2 = mergesort(arr2);

	if(arr1_size > arr2_size) {
		vector<int> mediate(arr1.begin(), arr1.begin() + arr1_size);
		vector<int> arr1(arr2.begin(), arr2.begin() + arr2_size);
		vector<int> arr2(mediate.begin(), mediate.begin() + mediate.size());
	}
	vector<int> merged(arr1_size + arr2_size);
	int cursor[] = { 0, 0, 0 };
	while(cursor[1] < arr1_size || cursor[2] < arr2_size) {
		if(cursor[2] == arr2_size || (cursor[1] < arr1_size && arr1[cursor[1]] < arr2[cursor[2]])) {
			merged[cursor[0]] = arr1[cursor[1]];
			cursor[0]++;
			cursor[1]++;
		} else {
			merged[cursor[0]] = arr2[cursor[2]];
			cursor[0]++;
			cursor[2]++;
		}
	}
	return merged;
}
