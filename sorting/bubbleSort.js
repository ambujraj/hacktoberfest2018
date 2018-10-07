const bubbleSort = arr => {
 for(let i = 0; i < arr.length-1; i++) {
   for(let j = 0; j < arr.length-1; j++) {
     if(arr[j] > arr[j+1]) {
       let temp = arr[j]
       arr[j] = arr[j+1]
       arr[j+1] = temp
     }
   }
 }
 return arr
}

const arr1 = [5,4,3,2,1]
const arr2 = [3,2,5,4,7,8,12,1]
const arr3 = [87,12,1234,12,2,34,3,2,1,5,4,8,32,1]

;[arr1, arr2, arr3].forEach(arr => console.log(bubbleSort(arr)))

