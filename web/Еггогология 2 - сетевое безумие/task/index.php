<?php

function stylishText($input_str) {
	return "<body style=\"background-color: black;\"><h6 style=\"font-family: Brush Script MT;color: #E5C601;font-size: 70px;padding: 1em;position: absolute;top: 50%;left: 50%;margin-right: -50%;transform: translate(-50%, -50%);\">".$input_str."</h6></body>";
}

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
     echo stylishText("Just get it.");
}
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
     try {
         $arr = [3,7,3,2,7,8,3,2,7,9];
	 if(intval($_POST['data']) > 9 || intval($_POST['data']) < 0)
		throw new Exception('bla bla bla, error, bla bla...');
	 $k = $arr[intval($_POST['data'])];
     } catch (Throwable $e) {
         echo stylishText('█████████████');
	 exit(0);
     }
     
     try {
         $_ = intdiv(65,intval(substr(hash("md5", $_POST['data']),0,14),16));
     } catch (Throwable $e) {
         echo stylishText('█████████████');
	 exit(0);
     }
     
     try {
	 if (strlen($_POST['data']) > 50)
             $_<<=substr($_POST['data'],50,52);
     } catch (Throwable $e) {
         echo stylishText('████████████');
	 exit(0);
     }
}
?>