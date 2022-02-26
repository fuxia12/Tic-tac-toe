# This script is used to read the reports generated from your identification code

#!/usr/bin/env bash

if [ $# -lt 1 ] || [ $# -gt 1 ]; then
	echo "Use: ./read-report <code>" >&2
	echo "Error: number of invalid parameters" >&2
else
	if [ $1 = "-h" ]; then
		echo "Use: ./read-report <code>"
	elif [ -e reports/report-$1.txt ]; then
		clear
		cat reports/report-$1.txt
	else
		echo "[-] Invalid ID code" >&2
	fi
fi
