#!/usr/bin/env bash

input="$*"
if [[ -z $input ]]; then
    exit 0
fi

if [[ $input =~ ^[0-9]+\. ]]; then
    # Parse title string, e.g., "1143. Longest Common Subsequence"
    number=$(echo "$input" | cut -d'.' -f1)
    number=$(printf "%04d" "$number")
    name=$(echo "$input" | cut -d'.' -f2- | sed 's/^ *//; s/ *$//' | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g; s/[^a-z0-9-]//g')
    dir="${number}.${name}"
else
    dir=$input
fi

mkdir -p "$dir"
cd "$dir"

cat <<EOF > main.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  string line;
  stringstream ss;
  int x;

  for (int t = 0; t < tc; ++t) {
    auto sol = Solution();
    cout << sol << endl;
  }
}
EOF

touch input.txt
