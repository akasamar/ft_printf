#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$mas = explode(' ', $str);
		$sortirovka = array_filter($mas);
		return ($sortirovka);
	}
	if ($argc > 1)
	{
		$mas = ft_split($argv[1]);
		$count = count($mas);
		if (count($mas) > 1)
		{
			for ($i = 1; $i < count($mas); $i++)
					echo "".$mas[$i]." ";
			echo $mas[0];
		}
		else
			echo $mas[0];
	}
?>