echo "Enter the coefficients of quadratic equation: "
read a
read b
read c
D=`expr $b \* $b - 4 \* $a \* $c`
# echo -e "sqrt($D)"|bc
# echo -e "0.5*(-($b)+sqrt($D)/($a)"|bc
# echo "Roots are: "
if [ $D -eq 0 ]
then
	echo "$(((-($b))/(2*($a))))"
elif [ $D -gt 0 ]
then
	echo -e "0.5*((-($b)+sqrt($D))/($a))"|bc
	echo -e "0.5*((-($b)-sqrt($D))/($a))"|bc
else
	echo -e 
fi


