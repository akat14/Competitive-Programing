cnt=1
while [ true ];
do 
  echo $cnt
  python helper.py > test
  ./thief < test > out
  java thief_font < test > ans
  if [ "$(diff out ans)" != "" ] ;
  then
    break
  fi
  let cnt=cnt+1
done
