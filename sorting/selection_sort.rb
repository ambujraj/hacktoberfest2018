class Main
  def self.run
    arr = [93, 2, 47, 1, 902]
    puts selection_sort(arr)
  end

  def self.selection_sort(arr)
     (0).upto((arr.length - 2) ).each do |i|
        min_index = i
        (i+1).upto((arr.length - 1)).each do |j|
          min_index = j if arr[j] < arr[min_index]
        end
        arr[i], arr[min_index] = arr[min_index], arr[i] if arr[min_index] != i
     end
     arr
  end
end


Main.run