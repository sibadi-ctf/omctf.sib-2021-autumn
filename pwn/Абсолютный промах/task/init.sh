apt update &
apt install python3 xinetd -y &
cp ./k.py ~/k.py
cp ./pwn1 /etc/xinetd.d/pwn1