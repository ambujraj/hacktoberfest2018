#!/usr/bin/env bash

OLD=0
NEW=1
while true; do
	echo $OLD
	HOLD=$NEW
	((NEW+=OLD))
	OLD=$HOLD
	sleep 1
done
