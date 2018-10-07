<!-- Our landing page -->

<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
	
	session_start();
	include("DataBase/connection.php");
?>


<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Minishop</title>
		<link rel='shortcut icon' type='image/x-icon' href='resources/Sessel-coloured.png'/>
		<link rel="stylesheet" type="text/css" href="nav.css"/>
		<link rel="stylesheet" type="text/css" href="/css/table.css"/>
	</head>
	<body>
		<div class="header">
			<img src="resources/image1.jpg">
			<img src="resources/logo1.png">
			<img src="resources/image3.jpg">
		</div>
		<div class="menu">
			<a href="index.html" class="brand"><img src="resources/logo.png"></a>
			<nav>
				<ul>
                    <?php if ($_SESSION['role'] == 1): ?>
                        <li><a href="#">Admin</a></li>
                    <?php endif; ?>
					<li><a href="users.php">Users</a></li>
				 	<li><a href="categories.php">Categories</a>
						<ul>
							<li><a href="index.php?cat=1">Living room</a></li>
							<li><a href="index.php?cat=2">Dining room</a></li>
							<li><a href="index.php?cat=3">Bedroom</a></li>
							<li><a href="index.php?cat=4">Bathroom</a></li>
							<li><a href="index.php?cat=5">Kitchen</a></li>
							<li><a href="index.php?cat=6">Patio</a></li>
						</ul>
					</li>
                    <?php if ($_SESSION['logged_in'] == 1): ?>
                        <li><a href="DataBase/logout.php">logout</a></li>
                    <?php else: ?>
                    <li><a href="DataBase/auth.php">SIGN IN</a></li>
					<?php endif; ?>
                    <li><class="brand"><a href="index.php?cat=777" ><img src="resources/basket.png"></a></a></li>
				</ul>
			</nav>
		</div>
	<div class="undermenu">

	<?php

	if ($_GET['cat'])
	{
		$result_cat = mysqli_query($link, "SELECT * FROM `categories` WHERE `id` = '".$_GET['cat']."'");
		$cat_count	= mysqli_num_rows($result_cat);
		if ($cat_count != 0)
		{
			$result_prod = mysqli_query($link, "SELECT * FROM `items` WHERE `cat` = '".$_GET['cat']."'");
			while ($object = mysqli_fetch_assoc($result_prod))
			{
				?>
				<?php if ($_GET['cat'] == $object['cat']): ?>
				<div class="ds" style="font-size: 10pt;">
					<img src ="<?php echo $object['img'];?>" width="100">
					<p><?php echo "Название: " . $object['name']; ?></p>
					<p><?php echo "Описание: "	. $object['description'];?></p>
					<p><?php echo "Цена " . $object['price'] . " y.e." . "\n"; ?></p>
					<a href="index.php?cat=777&num=<?php echo $object['id']; ?>">Купить</a>
					<hr>
				</div>
				<?php endif; ?>
				<?php
			}
		}
	}
	?>
	<?php
	if ($GET['num'])
		$mas = $GET['num'];
	if ($GET['cat'] == 777)
		echo $mas;
	?>
	</div>
	</body>
	<div = id="footer">
    	<hr/> 2018 &copy; knikanor & akasamar
	</div>
</html>

<!-- 
if (!isset($_GET['cat']) || $_GET['cat'] == '') -->