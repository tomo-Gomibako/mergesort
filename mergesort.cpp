#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> array) {
	int length = array.size();
	cout << "[";
	for(int i = 0; i < length; i++) {
		cout << array[i];
		if(i != length - 1) cout << ", ";
	}
	cout << "]" << endl;
}

vector<int> slice(vector<int> array, int start, int end) {
	vector<int> ret = vector<int>(array.begin() + start, array.begin() + end);
	return ret;
}
vector<int> merge(vector<int> arr1, vector<int> arr2) {
	int arr1_size = arr1.size();
	int arr2_size = arr2.size();
	if(arr1_size > arr2_size) {
		vector<int> mediate = slice(arr1, 0, arr1_size);
		arr1 = slice(arr2, 0, arr2_size);
		arr2 = slice(mediate, 0, mediate.size());
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
vector<int> mergesort(vector<int> arr) {
	int arr_size = arr.size();
	if(arr_size == 1) return arr;
	int half = (int)(arr_size / 2) + arr_size % 2;
	vector<int> arr1 = slice(arr, 0, half);
	vector<int> arr2 = slice(arr, half, arr_size);
	int arr1_size = arr1.size();
	int arr2_size = arr2.size();
	if(arr1_size > 1) arr1 = mergesort(arr1);
	if(arr2_size > 1) arr2 = mergesort(arr2);
	return merge(arr1, arr2);
}
int main() {
	vector<int> array = { 3, 7, 1, 6, 2, 5, 4, 0 };
	print_vector(array);
	print_vector(mergesort(array));
	return 0;
}
