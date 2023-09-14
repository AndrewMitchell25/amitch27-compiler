#!/bin/sh

for testfile in test/scanner/good*.bminor
do
	if ./bminor --scan $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/scanner/bad*.bminor
do
	if ./bminor --scan $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done