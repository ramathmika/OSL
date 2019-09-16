echo "Enter a number"
read num
sum=0
until [ $num -eq 0 ]
do
	r=`expr $num % 10`
	sum=$((($sum)+($r)))
	num=`expr $num / 10`
done
op=`expr $sum % 2` 
case $op in
	0) echo "Even"
		;;
	1) echo "Odd"
		;;
esac
