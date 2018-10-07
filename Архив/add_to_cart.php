<?php
	session_start();
	$product_id = $_POST['id'];
	if (isset($_SESSION['cart'][$product_id]))
	{
		$_SESSION['cart'][$product_id]++;
	}
	else
	{
		$_SESSION['cart'][$product_id] = 1;
	}
	// header("Location: ".$_POST['return_url']);
	// exit();
?>
