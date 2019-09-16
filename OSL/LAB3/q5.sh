echo "Enter two numbers: "
read n1
read n2
stop=0
while test $stop -eq 0
do
cat<<ENDOFMENU
1: Addition
2: Subtraction
3: Multiplication
4: Division
5: Exit
ENDOFMENU
echo
echo "Enter your choice: "
read reply
echo
case $reply in
	"1")echo "Result = $n1+$n2"
		;;
	"2")echo "Result = $n1-$n2"
		;;
	"3")echo "Result = $n1*$n2"
		;;
	"4")echo -e "scale=2;$n1/$n2"|bc 
		;;
	"5")stop=1;;
	*)echo "Illegal choice.";;
esac
echo
done