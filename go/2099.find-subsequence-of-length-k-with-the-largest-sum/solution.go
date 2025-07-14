// Created by Dawid Karpiński at 2025/06/28 19:07
// leetgo: dev
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

package main

import (
	"bufio"
	"fmt"
	"os"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

func perm(k int, arr []int) []int {
	if k == 1 {
		return arr
	}

	for idx := range k - 1 {
		perm(k-1, arr)

		if k%2 == 0 {
			arr[idx], arr[k-1] = arr[k-1], arr[idx]
		} else {
			arr[0], arr[k-1] = arr[k-1], arr[0]
		}
	}

	return arr
}

func maxSubsequence(nums []int, k int) (ans []int) {
	return perm(k, nums)
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	nums := Deserialize[[]int](ReadLine(stdin))
	k := Deserialize[int](ReadLine(stdin))
	ans := maxSubsequence(nums, k)

	fmt.Println("\noutput:", Serialize(ans))
}
