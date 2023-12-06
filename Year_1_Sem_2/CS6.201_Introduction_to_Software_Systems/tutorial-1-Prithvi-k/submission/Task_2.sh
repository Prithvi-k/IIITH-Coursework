#!/bin/bash

# 1. Create file with calender for this month
if [-f "output1.txt"] # Checks if file already exists
then
	rm output1.txt # If file exists, delete it
fi
touch output1.txt # Create file
cal March 2023 > output1.txt

# 2. Append today's date
(date +%Y-%m-%d) >> output1.txt

# 3. Appending 'ISS is cool' 100 times
count=100
while (( count != 0 ))
do
	echo "ISS is cool" >> output1.txt
	(( count-- ))
done

# 4. Display the contents of the file
cat output1.txt

# 5. Display first 3 lines
cat output1.txt | head -3 

# 6. Display lines 6 to 15
cat output1.txt | head -15 | tail +6

# 7. Display number of lines in output1.txt
cat output1.txt | wc -l

# 8. Using echo, write string "I'm UG1"
echo "I'm UG1" >> output1.txt

# 9. Print number of words in output1.txt
wc -w output1.txt | cut -d ' ' -f1

# 10. Append the line "I'm studying ISS" in the same file.
echo "I'm studying ISS" >> output1.txt

# 11. Print the 4th column of the file output1.tx
awk '{print $4}' output1.txt

# 12. Print from column number 2 to 5 (both included) of the file
awk '{print $2, $3, $4, $5}' output1.txt

# 13. Print from the 3rd column, everything till the n-5th line of the file output1.txt
awk '{print $3}' output1.txt | head -n -5

# 14. Print the second and fourth word of every row from the file output1.txt using a single command
awk '{print $2, $4}' output1.txt