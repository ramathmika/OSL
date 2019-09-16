# declare -a teamnames
# teamnames[0]="India"
# teamname[1]="England"
# teamnames[2]="Nepal"
# echo "There are ${#teamnames[*]} teams"
# echo "They are: ${teamnames[*]}"
# unset teamnames[1]

# echo "Enter a number: "
# read number
# if [ $number -lt 0 ]
# then
# 	echo "Negative"
# elif [ $number -eq 0 ]
# then
# 	echo "Zero"
# else
# 	echo "Positive"
# fi

# case $1 in
# [AaBbCc]) 
# pr=0
# ;;
# *) 
# pr=1
# ;;
# esac

# echo "Menu Test Program"
# stop=0
# while test $stop -eq 0
# do
# cat<<ENDOFMENU
# 1: Print the date
# 2,3: Print the current working directory
# 4: Exit
# ENDOFMENU
# echo
# echo "Your choice?"
# read reply
# echo
# case $reply in
# 	"1")echo "Date:" 
# 		date ;;
# 	"2"|"3")echo "Current Directory"
# 			pwd;;
# 	"4")stop=1;;
# 	*)echo "Illegal choice.";;
# esac
# echo
# done

#!/bin/bash
# X=0
# while [ $X -le 20 ]
# do
# 	echo $X
# 	X=$((X+1))
# done

# while test $# != 0
# do
# 	echo $1
# 	shift
# done

# x=1
# until [ $x -gt 3 ]
# do
# 	echo x=$x
# 	x=`expr $x + 1`
# done

homedir=`pwd`
for files in /*
do
	echo $files
done
cd $homedir