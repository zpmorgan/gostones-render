#!/usr/bin/env bash
WSEEDS=( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 )

povray stone.pov +H300 +W300 Declare=W=0 -Ob.png +UA

for i in "${WSEEDS[@]}"
do
   echo $i
   povray stone.pov +H300 +W300 Declare=Seed=${i} Declare=W=1 -Ow${i}.png +UA
done

