<?php
	session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Sign In</title>

		<?php if ($_SESSION['incorrect_password'] == 1) :?>
            <script type="text/javascript">
                alert("wrong password");
            </script>
	    <?php endif;?>
        <link rel="stylesheet" type="text/css" href="/css/table.css"/>
	</head>
	<body>
    <div>
		<form action="auth.php" method="post">
			Login: <input type="text" name="login">
			<br>
			Password: <input type="password" name="password">
			<input type="submit" name="submit" value="OK">
		</form>
    </div>
	</body>
</html>
