#!/bin/bash
#
# grep.sh
#

PATTERN=$1

grep\
 --exclude-dir=.git\
 --exclude-dir=ICED-L\
 --exclude-dir=ICED-R\
 --exclude-dir=docs\
 --exclude=*.bin\
 --exclude=*.elf\
 --exclude=*.lss\
 --exclude=*.map\
 --exclude=*.o\
 --exclude=*.sym\
 --exclude=tags\
 --recursive\
 $PATTERN ../
