#!/usr/bin/php
<?php
	function ft_is_sort($mas)
	{
		for ($i = 0; $i < count($mas) - 1; $i++)
			if (strcmp($mas[$i], $mas[$i + 1]) > 0)
				return (FALSE);
		return (TRUE);
	}
?>