read -p "Where to locate xinetd log file?" xlog
chmod 777 $xlog
xinetd -dontfork -stayalive -filelog $xlog