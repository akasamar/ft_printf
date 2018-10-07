<?php
	session_start();
	include("connection.php");

	$login = $_POST['login'];
	$passwd = $_POST['password'];

	if ($result = mysqli_query($link, "SELECT password, id, role FROM user WHERE
		login='$login'")) {
		$res = mysqli_fetch_assoc($result);
		if ($res['password'] === hash("whirlpool", $passwd."salt")) {
			$_SESSION['uid'] = $res['uid'];
			$_SESSION['role'] = $res['role'];
			$_SESSION['logged_in'] = 1;
			$_SESSION['incorrect_password'] = 0;
			header("Location: ../index.php");
			exit;
		}
		else {
			$_SESSION['incorrect_password'] = 1;
			header("Location: sign_in.php");
			exit;
		}
	}
	else {
		print("\n".mysqli_error($link));
	}
?>
