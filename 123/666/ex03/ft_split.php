#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$mas = explode(' ', $str);
		$sortirovka = array_filter($mas);
		sort($sortirovka);
		return ($sortirovka);
	}
?>