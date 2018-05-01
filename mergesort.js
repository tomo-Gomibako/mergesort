function mergesort(arr) {
	if(arr.length === 1) return arr
	const half = arr.length / 2 | 0
	let arr1 = arr.slice(0, half)
	let arr2 = arr.slice(half)
	if(arr1.length > 1) arr1 = mergesort(arr1)
	if(arr2.length > 1) arr2 = mergesort(arr2)
	return merge(arr1, arr2)
}

function merge(arr1, arr2) {
	console.log("merge", arr1, arr2)
	if(arr1.length > arr2.length) {
		const mediate = arr1
		arr1 = arr2
		arr2 = mediate
	}
	const merged = []
	const cursor = [0, 0]
	while(cursor[0] < arr1.length || cursor[1] < arr2.length) {
	// for(let i = 0; i < 30; i++) {
	//   console.log(cursor)
		if(arr2[cursor[1]] === undefined || arr1[cursor[0]] < arr2[cursor[1]]) {
			merged.push(arr1[cursor[0]])
			cursor[0]++
		} else {
			merged.push(arr2[cursor[1]])
			cursor[1]++
		}
	}
	return merged
}

console.log(mergesort([3, 7, 1, 6, 2, 5, 4, 0]))
