echo "Enter a number: "
read number
# x=`expr $number % 2`
if [ `expr $number % 2` -eq 0 ]
then
	echo "Even"
else
	echo "Odd"
fi