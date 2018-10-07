<?php
	function create_user($login, $name, $pw, $link, $email) {
		$pass = hash("whirlpool", $pw."sasalt");
		if ($login && $name && $pw) {
			if (!mysqli_query($link, "INSERT INTO users (login, name, password, role, email)
								VALUES ('$login', '$name', '$pass', 'user', '$email')")) {
				return mysqli_error($link);
			}
		}
		return 1;
	}
?>
