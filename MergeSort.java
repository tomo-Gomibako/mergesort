import java.util.Arrays;

public class MergeSort {
	public static Integer[] mergesort(Integer[] arr) {
		if(arr.length == 1) return arr;
		int half = (int)(arr.length / 2);
		Integer[] arr1 = Arrays.copyOfRange(arr, 0, half);
		Integer[] arr2 = Arrays.copyOfRange(arr, half, arr.length);
		if(arr1.length > 1) arr1 = mergesort(arr1);
		if(arr2.length > 1) arr2 = mergesort(arr2);
		return merge(arr1, arr2);
	}
	public static Integer[] merge(Integer[] arr1, Integer[] arr2) {
		if(arr1.length > arr2.length) {
			Integer[] mediate = Arrays.copyOfRange(arr1, 0, arr1.length);
			arr1 = Arrays.copyOfRange(arr2, 0, arr2.length);
			arr2 = Arrays.copyOfRange(mediate, 0, mediate.length);
		}
		Integer[] merged = new Integer[arr1.length + arr2.length];
		Integer[] cursor = { 0, 0, 0 };
		while(cursor[1] < arr1.length || cursor[2] < arr2.length) {
			if(cursor[2] == arr2.length || (cursor[1] < arr1.length && arr1[cursor[1]] < arr2[cursor[2]])) {
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
}