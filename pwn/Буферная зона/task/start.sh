gcc -fno-stack-protector -z execstack -g source.c -o getflag
cp ./getflag /home/pwn2/getflag