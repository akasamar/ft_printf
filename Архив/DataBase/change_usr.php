<?php
	session_start();
	include("db_connect.php");
	include("createUser.php");

	if ($_SESSION['role'] != "admin") {
		header("Location: ../login.php");
		exit;
	}
	if ($_POST['s'] == "submit") {
		$id = $_POST['id'];
		$login = $_POST['login'];
		$name = $_POST['name'];
		$passwd = hash("whirlpool", $_POST['passwd']."sasalt");
		if ($login != "" && $name != "" && $_POST['passwd'] != "") {
			$res = mysqli_query($link, "UPDATE `users` SET login = '$login', name = '$name'
				 				, password = '$passwd' WHERE id = '$id'");
		}
		print(" <br>Changes are accepted<br>");
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Change user</title>
	</head>
	<body>
		<form action="changeUser.php" method="post">
			Login: <input type="text" name="login">
			<br>
			Name: <input type="text" name="name">
			<br>
			Password: <input type="password" name="passwd">
			<br>
			<input type="submit" name="s" value="submit">
			<input type="hidden" name="id" value="<?php echo $_POST['id']; ?>">
		</form>
		<a href="/users.php"><button style="margin-left: 100px;">Back</button></a>
	</body>
</html>
