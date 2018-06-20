#!/usr/bin/php
<?php
	if ($argc != 4)
	{
		echo "Incorrect Parameters";
		exit();
	}
	$rez = 0;
	$var1 = (int)$argv[1];
	$var3 = (int)$argv[3];
	$znak = trim($argv[2]);
	if ($znak == '*')
		$rez = $var1 * $var3;
	else if ($znak == '/')
		$rez = $var1 / $var3;
	else if ($znak == '-')
		$rez = $var1 - $var3;
	else if ($znak == '+')
		$rez = $var1 + $var3;
	else if ($znak == '%')
		$rez = $var1 % $var3;
	echo $rez;
?>