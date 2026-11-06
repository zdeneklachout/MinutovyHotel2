#!/bin/bash

for vstup in sample/basic/CZE/0000_in.txt
do
    muj_Out="${vstup/_in.txt/_muj_out.txt}"
    spravny_Out="${vstup/_in.txt/_out.txt}"

    ./program < "$vstup" > "$muj_Out"

    diff "$muj_Out" "$spravny_Out"

done



