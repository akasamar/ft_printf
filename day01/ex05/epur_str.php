#!/usr/bin/php
<?php
	if ($argc == 2)
	{
		$i = 0;
		$len = strlen($argv[1]);
		$var = trim($argv[1]);
		while ($i < $len)
			if ($var[$i] == ' ' AND $var[$i + 1] == ' ' AND ($i + 1) < $len)
			{
				$i++;
				continue;
			}
			else
				echo $var[$i++];
	}
?>