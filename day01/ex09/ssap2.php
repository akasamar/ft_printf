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
		for ($var = 1; $var <= $argc; $var++)
		{
			if ($var == 1)
				$new = ft_split($argv[$var]);
			else
				$new = array_merge($new, ft_split($argv[$var]));
		}	
	$i = 0;
	function ft_what($c)
	{
		if (($c >= 65 AND $c <= 90) OR ($c >= 97 AND $c <= 122))
			return (1);
		if ($c >= 47 AND $c <= 57)
			return (2);
		else
			return (3);
	}

	function ft_compare($str1, $str2)
	{
		$len1 = strlen($str1);
		$len2 = strlen($str2);
		if ($len1 > $len2)
			$len = $len2;
		else if ($len1 < $len2)
			$len = $len1;
		else if ($len == $len2)
			$len = $len1;
		$i = -1;
		while (++$i < $len)
		{
			if (ft_what($str1[$i]) == ft_what($str2[$i]))
				continue;
			if (ft_what($str1[$i]) > ft_what($str2[$i]))
				return ($str2);
			if (ft_what($str1[$i]) < ft_what($str2[$i]))
				return ($str1);
		}
		if ($len1 < $len2)
			return ($str1);
		else if ($len1 > $len2)
			return ($str2);
		else
			return ($str1);
	}
	$i = -1;
	while (++$i < count($new) - 1)
	{
		 if (strcmp($new[$i], ft_compare($new[$i], $new[$i + 1])) != 0)
		 {
		 	$change = $new[$i];
		 	$new[$i] = $new[$i + 1];
		 	$new[$i + 1] = $change;
		 	$i = -1;
		 	continue;
		 }
	}
	foreach ($new as $xyu)
	{
		echo "$xyu\n";
	}
?>