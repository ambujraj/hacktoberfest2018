def bubble_sort(nums):
    for i in range(len(nums)-1):
        for j in range(len(nums)-1-i):
            if nums[j]>nums[j+1]:
                swap(nums,j,j+1)
    return nums
def swap(nums,j,i):
    temp=nums[i]
    nums[i]=nums[j]
    nums[j]=temp
nums=[]
n=int(input("enter how many numbers:"))
print("enter numbers to be sorted:")
for i in range(n):
    num=int(input())
    nums.append(num)
print(bubble_sort(nums))
