#!/bin/sh
make

for testfile in test/codegen/good*.bminor
do
	if ./bminor --codegen $testfile test.s
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done
