func removeDuplicates(nums []int) int {
    i := 0
    j := 1
    for j < len(nums) {
        if nums[i] != nums[j] && j != i+1 {
            nums[i+1] = nums[j]
            i++
            j++
        } else if nums[i] != nums[j] {
            i++
            j++
        } else {
            j++
        }
    }

    return i+1
}