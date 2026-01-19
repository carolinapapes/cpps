#!/bin/bash

PROG=./rpn

tests=(
  "3 4 +|7"
  "9 4 -|5"
  "6 7 *|42"
  "8 2 /|4"
  "3 4 + 2 *|14"
  "5 1 2 + 4 * + 3 -|14"
  "2 3 4 + *|14"
  "9 3 / 2 * 5 +|11"
  "4 2 5 * + 1 3 2 * + /|2"
  "7|7"
)

error_tests=(
  "+"
  "3 +"
  "4 5 + +"
  "3 4"
  "1 2 3 +"
  "3 a +"
  "4 2 &"
  "5 0 /"
)

echo "===== VALID TESTS ====="
for t in "${tests[@]}"; do
  expr="${t%%|*}"
  expected="${t##*|}"
  result=$($PROG "$expr" 2>/dev/null)

  if [ "$result" = "$expected" ]; then
    echo "[OK]   \"$expr\" -> $result"
  else
    echo "[DIFF] \"$expr\""
    echo "  Expected: $expected"
    echo "  Got:      $result"
  fi
done

echo
echo "===== ERROR TESTS ====="
for expr in "${error_tests[@]}"; do
  result=$($PROG "$expr" 2>/dev/null)

  if [ "$result" = "Error" ]; then
    echo "[OK]   \"$expr\" -> Error"
  else
    echo "[DIFF] \"$expr\""
    echo "  Expected: Error"
    echo "  Got:      $result"
  fi
done
