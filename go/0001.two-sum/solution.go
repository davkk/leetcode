// Created by Dawid Karpiński at 2025/06/28 18:32
// leetgo: dev
// https://leetcode.com/problems/two-sum/

package main

import (
	"bufio"
	"fmt"
	"os"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

// func twoSum(nums []int, target int) (ans []int) {
// 	for i := range len(nums) {
// 		for j := i + 1; j < len(nums); j++ {
// 			if nums[i]+nums[j] == target {
// 				return []int{i, j}
// 			}
// 		}
// 	}
// 	return []int{0, 1}
// }

func twoSum(nums []int, target int) (ans []int) {
	seen := make(map[int]int)

	for idx, num := range nums {
		diff := target - num
		compl, exists := seen[diff]
		if exists {
			return []int{idx, compl}
		}
		seen[num] = idx
	}

	return
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	nums := Deserialize[[]int](ReadLine(stdin))
	target := Deserialize[int](ReadLine(stdin))
	ans := twoSum(nums, target)

	fmt.Println("\noutput:", Serialize(ans))
}
