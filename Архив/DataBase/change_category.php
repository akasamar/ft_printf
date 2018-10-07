<?php
	session_start();
	include("db_connect.php");

	if ($_SESSION['role'] != "admin") {
		header("Location: login.php");
		exit;
	}

	if ($_POST['s'] == "submit") {
		$id = $_POST['id'];
		$title = $_POST['title'];
		$descrip = $_POST['descrip'];
		if ($title != "")
			mysqli_query($link, "UPDATE categories SET title = '$title' WHERE id = '$id'");
		echo(mysqli_error($link));
		if ($descrip != "")
			mysqli_query($link, "UPDATE categories SET description = '$descrip' WHERE id = '$id'");
		echo(mysqli_error($link));
		print(" <br>Changes are accepted<br>");
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Change categories</title>
	</head>
	<body>
		<form action="changeCat.php" method="post">
			Title: <input type="text" name="title">
			<br>
			Description: <input type="text" name="descrip">
			<br>
			<input type="hidden" name="id" value="<?php echo $_POST['id'] ?>">
			<input type="submit" name="s" value="submit">
		</form>
		<a href="/categors.php"><button style="margin-left: 100px;">Back</button></a>
	</body>
</html>
