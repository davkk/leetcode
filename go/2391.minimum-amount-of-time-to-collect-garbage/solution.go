// Created by Dawid Karpiński at 2025/06/29 12:31
// leetgo: dev
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

package main

import (
	"bufio"
	"fmt"
	"os"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

func garbageCollection(garbage []string, travel []int) (ans int) {

	return
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	garbage := Deserialize[[]string](ReadLine(stdin))
	travel := Deserialize[[]int](ReadLine(stdin))
	ans := garbageCollection(garbage, travel)

	fmt.Println("\noutput:", Serialize(ans))
}
