#!/usr/bin/php
<?php
	while (1)
	{
		echo "Enter a number: ";
		$some = trim(fgets(STDIN));
		if (feof(STDIN))
		{
			echo "\n";
			exit();
		}
		if (is_numeric($some))
		{
			if ($some % 2 == 0)
				echo ("The number ".$some." is even\n");
			else
				echo ("The number ".$some." is odd\n");
		}
		else
			echo ("'".$some."' is not a number\n");
	}
?>