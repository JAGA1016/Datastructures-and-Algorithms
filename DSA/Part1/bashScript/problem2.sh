#! /bin/bash
cd net										#opening directory
mkdir net2									#making subdirectory
cd net2
for a in 1 2 3 4 5
do
	touch file$a.txt							#creating 5 files
done
for b in 1 2 3 4 5
do
	for c in {1..10}
	do
		x=$((10*($b-1) +$c))						#storing no. to print in x
		printf "$x " >> file$b.txt					#printing no. in file
	if [ "$c" -eq 5 ]
		then
			printf "\n" >> file$b.txt				#new line command
		fi
	done
done
