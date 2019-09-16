echo "Enter a number: "
read number
echo "Factorial is: "
res=$number
until [ $number -eq 1 ]
do
	number=$(($number-1))
	res=$(($res*$number))
done
echo $res