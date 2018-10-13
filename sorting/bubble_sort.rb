class BubbleSorter
  def call(arr)
    for i in 0..arr.count-2
      for j in 0..arr.count-2
        if arr[j] > arr[j+1]
          temp = arr[j]
          arr[j] = arr[j+1]
          arr[j+1] = temp
        end
      end
    end
    arr
  end
end

arr1 = [5,4,3,2,1,6]
arr2 = [3,2,5,4,7,8,12,1]
arr3 = [87,12,1234,12,2,34,3,2,1,5,4,8,32,1]

sorter = BubbleSorter.new

p sorter.call(arr1)
p sorter.call(arr2)
p sorter.call(arr3)
