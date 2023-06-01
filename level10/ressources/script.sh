#!/bin/sh
touch /tmp/flaglevel10

while [ 42 ]
do
	ln -sf /tmp/flaglevel10 /tmp/flaggood
	ln -sf ~/token /tmp/flaggood
done &

while [ 42 ]
do
	/home/user/level10/level10 /tmp/flaggood 127.0.0.1
done