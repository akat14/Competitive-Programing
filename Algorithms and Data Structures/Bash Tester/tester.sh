name=$1
brtest=$2
test=1
while [ $test -le $brtest ] ;
do
	if [ $test -lt 10 ] ;
	then
		time ./$name < $name.0$test.in > out
		cp $name.0$test.sol sol
	else
		time ./$name < $name.$test.in > out
		cp $name.$test.sol sol
	fi
	if [ "$(diff out sol -b)" != "" ] ;
	then
		echo 'WA on test '$test':'
		if [ $test -lt 10 ] ;
		then
			cat $name.0$test.in
		else
			cat $name.$test.in
		fi
		echo 'Expected: '
		cat sol
		echo 'Received: '
		cat out
		break
	fi
	let test=test+1
done

