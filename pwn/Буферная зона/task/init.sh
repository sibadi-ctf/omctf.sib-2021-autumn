useradd -m pwn2
passwd pwn2
cp ./pwn2 /etc/xinetd.d/pwn2
gcc -fno-stack-protector -z execstack -g source.c -o getflag
cp ./getflag /home/pwn2/getflag
chmod 777 /home/pwn2/getflag