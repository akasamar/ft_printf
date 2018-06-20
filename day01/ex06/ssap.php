#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$mas = explode(' ', $str);
		$sortirovka = array_filter($mas);
		sort($sortirovka);
		return ($sortirovka);
	}
	if ($argc > 1)
	{
		for ($var = 1; $var <= $argc; $var++)
		{
			if ($var == 1)
				$new = ft_split($argv[$var]);
			else
				$new = array_merge($new, ft_split($argv[$var]));
		}	
			sort($new);
		for ($i = 0; $i < count($new); $i++)
			if ($i == count($new) - 1)
				echo $new[$i];
			else
				echo ("".$new[$i]."\n");
	}
?>