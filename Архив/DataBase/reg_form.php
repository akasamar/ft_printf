<?php
	session_start();
	include("connection.php");
	include("create_usr.php");

	$_SESSION['login_free'] = 1;
	$_SESSION['repeat_pswd'] = 1;
	$_SESSION['create_usr'] = 0;
	if (isset($_POST['submit']) && !empty($_POST['submit'])) {
		$login = $_POST['login'];
		$pswd = $_POST['password'];
		$repeat_pswd = $_POST['repeat_pswd'];
		$name = $_POST['name'];
		$email = $_POST['email'];
		$result = mysqli_query($link, "SELECT id FROM users WHERE login = '$login'");
		$res = mysqli_fetch_assoc($result);
		if (!$res) {
			if ($pswd == $repeat_pswd) {
				$_SESSION['create_usr'] = create_user($login, $name, $pw, $link, $email);
			}
			else {
				$_SESSION['repeat_pswd'] = 0;
			}
		}
		else {
			$_SESSION['login_free'] = 0;
		}
	}
	if ($_SESSION['create_usr'] == 1) {
		header("Location: ../index.php");
	}
 ?>

 <html>
 	<head>
 		<meta charset="utf-8">
 		<title>Registration</title>
        <link rel="stylesheet" type="text/css" href="nav.css"/>
 	</head>
 	<body>
        <div class="wrapper">
		<?php include "../parts/header.php"; ?>
 		<form action="reg_form.php" method="post" >
 			Login: <input type="text" name="login" required>
			<span style="color: red;">
				<?php
					if ($_SESSION['login_free'] == 0){
						echo "<br>Login has already been taken";
				 	}
				?>
			</span>
 			<br>
			Name: <input type="text" name="name" required>
			<br>
 			Password: <input type="password" name="password" required>
			<span style="color: red;">
				<?php
					if ($_SESSION['repeat_pass'] == 0){
						echo "<br> The passwords are different";
					}
				?>
			</span>
 			<br>
 			Repeat password: <input type="password" name="repeat_pswd" required><br>
			Email: <input type=text name="email" required>
 			<input type="submit" class="button" name="submit" value="Send">
 		</form>
        </div>
 	</body>
 </html>
