#!/bin/sh
for file in $1/*.in
do
	./$2 < $file > first.out
	./$3 < $file > second.out
	correct="${file%.in}.out"
	any=0
	diff first.out $correct
	if [ $? -ne 0 ]
	then
		echo "output of $2 and correct output differ"
		any=1
	fi
	diff second.out $correct
	if [ $? -ne 0 ]
	then
		echo "output of $3 and correct output differ"
		any=1
	fi
	diff first.out second.out
	if [ $? -ne 0 ]
	then
		echo "$2 and $3 give different outputs"
		any=1
	fi
	if [ $any -ne 0 ]
	then
		echo "input file was $file"
		break
	fi
done
