// Created by Dawid Karpiński at 2025/06/29 12:11
// leetgo: dev
// https://leetcode.com/problems/merge-strings-alternately/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

func mergeAlternately(word1 string, word2 string) string {
	var result strings.Builder
	maxLen := max(len(word1), len(word2))
	for i := range maxLen {
		if i < len(word1) {
			result.WriteByte(word1[i])
		}
		if i < len(word2) {
			result.WriteByte(word2[i])
		}
	}
	return result.String()
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	word1 := Deserialize[string](ReadLine(stdin))
	word2 := Deserialize[string](ReadLine(stdin))
	ans := mergeAlternately(word1, word2)

	fmt.Println("\noutput:", Serialize(ans))
}
