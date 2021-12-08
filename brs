#! /bin/bash 
mway=( drop debug/  inc/  release/  src/  ../ ) 
select mw in ${mway[@]} 
do 
 case $mw in 
drop) pwd ;; 
debug/ ) alias mycd='cd debug/ ';; 
inc/ ) alias mycd='cd inc/ ';; 
release/ ) alias mycd='cd release/ ';; 
src/ ) alias mycd='cd src/ ';; 
../) alias mycd='cd ../';; 
*) break;; 
esac 
break 
done 
mycd 
pwd