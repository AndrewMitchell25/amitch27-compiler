#!/bin/sh

for testfile in test/encode/good*.bminor
do
	if ./bminor --encode $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/encode/bad*.bminor
do
	if ./bminor --encode $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done