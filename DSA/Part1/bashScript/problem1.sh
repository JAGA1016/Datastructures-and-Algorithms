#!/bin/bash
mkdir d1 #creating directory
cd d1    #opening directory
mkdir subd #creating another directory in d1
for a in {1..10}
do 
   touch file$a  #making empty files in the directory d1
done
for FILENAME in * #changing file names in the d1 using move command
do
	mv "$FILENAME" new_"$FILENAME"

done

mv new_file{1..10} new_subd #moving all files to  directory


