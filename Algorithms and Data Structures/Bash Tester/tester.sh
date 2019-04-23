name=$1
brtest=$2
test=1
while [ $test -le $brtest ] ;
do
	if [ $test -lt 10 ] ;
	then
		cp $name.0$test.in inn
		cp $name.0$test.sol sol
	else
		cp $name.$test.in inn
		cp $name.$test.sol sol
	fi
	time ./$name < inn > out
	if [ "$(diff out sol -b)" != "" ] ;
	then
		echo 'WA on test '$test':'
		echo inn
		echo 'Expected: '
		cat sol
		echo 'Received: '
		cat out
		break
	fi
	let test=test+1
done

