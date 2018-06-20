#!/usr/bin/php
<?php
	$i = 0;
	while (++$i < $argc)
	{
		if ($i == $argc - 1)
			echo $argv[$i];
		else
			echo ("".$argv[$i]."\n");
	}
?>