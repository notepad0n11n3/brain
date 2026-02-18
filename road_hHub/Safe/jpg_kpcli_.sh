#!/bin/bash

for i in *.JPG
	do
		echo bullshit | kpcli --kdb MyPasswords.kdbx --key ${i} --command quit >/dev/null 2>&1
		if [[ $? -eq 0 ]]
			then
				echo "Key: $i"
				break
			fi
	done
