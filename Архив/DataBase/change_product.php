<?php
	session_start();
	include("db_connect.php");
	include("createUser.php");

	if ($_SESSION['role'] != "admin") {
		header("Location: login.php");
		exit;
	}

	if ($_POST['s'] == "submit") {
		$id = $_POST['id'];
		$title = $_POST['title'];
		$descrip = $_POST['descrip'];
		$img = $_POST['img'];
		$price = $_POST['price'];
		if ($title != "") {
			$res = mysqli_query($link, "UPDATE product SET title = '$title' WHERE id = '$id'");
			echo "lol";
		}
		if ($descrip != "")
			$res = mysqli_query($link, "UPDATE product SET description = '$descrip' WHERE id = '$id'");
		if ($img != "")
			$res = mysqli_query($link, "UPDATE product SET image = '$img' WHERE id = '$id'");
		if ($price != "")
			$res = mysqli_query($link, "UPDATE product SET price = '$price' WHERE id = '$id'");
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
		<form action="changeProd.php" method="post">
			Title: <input type="text" name="title">
			<br>
			Description: <input type="text" name="descrip">
			<br>
			img: <input type="text" name="img">
			<br>
			Price: <input type="number" name="price">
			<br>
			<input type="submit" name="s" value="submit">
			<input type="hidden" name="id" value="<?php echo $_POST['id']; ?>">
		</form>
		<a href="/product.php"><button style="margin-left: 100px;">Back</button></a>
	</body>
</html>
