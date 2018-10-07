<?php
	include("db_conf.php");

	$link = mysqli_connect($host, $name, $passwd, $database, $db_port);

	if (!$link) {
		print("Error connection\n");
	}
?>
