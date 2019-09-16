echo "Enter n: "
read n
echo "Odd numbers till n: "
x=1
until [ $x -gt $n ]
do
	echo $x
	x=`expr $x + 2`
done