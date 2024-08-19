func reverse(nums []int, i, j int) {
	for i < j {
		aux := nums[i]
		nums[i] = nums[j]
		nums[j] = aux
		i++
		j--
	}
}

func rotate(nums []int, k int) {
	n := len(nums)
	mod := k % n
	i := n - mod
	j := len(nums) - 1
	reverse(nums, i, j)

	i = 0
	j = n - mod - 1
	reverse(nums, i, j)

	i = 0
	j = n - 1
	reverse(nums, i, j)
}