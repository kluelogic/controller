#!/bin/bash
#
# diff.sh
#


OPTS='--ignore-tab-expansion --new-file --ignore-all-space --unified --recursive'
LOG=diff.log
DIRS="Scan kll/kll/layouts"

# use meld

for DIR in $DIRS
do
    meld ~/sandbox/controller/$DIR ~/washroom/controller/$DIR
done
exit

# This is alternative way using kompare...

echo "Make sure to click 'Next File' to traverse all diffs."
echo "" > $LOG
for DIR in $DIRS
do
    diff $OPTS ~/sandbox/controller/$DIR ~/washroom/controller/$DIR >> $LOG
done
cat $LOG | kompare -o -
