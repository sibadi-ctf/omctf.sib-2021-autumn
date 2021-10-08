cp ./pwn3 /etc/xinetd.d/pwn3
gcc source.c -g -o keyholder
cp ./flag /home/pwn3/flag
cp ./keyholder /home/pwn3/keyholder
chmod 777 /home/pwn3/flag
touch /home/pwn3/secret
chmod 777 /home/pwn3/secret
chmod 777 /home/pwn3/keyholder
cp ./magic.sh /home/pwn3/magic.sh