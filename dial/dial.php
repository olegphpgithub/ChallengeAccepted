<?php

if (!array_key_exists('h', $_REQUEST) || !array_key_exists('m', $_REQUEST)) {
    exit(1);
}

$h = intval($_REQUEST['h']);
$h %= 12;
$m = intval($_REQUEST['m']);

$minute_angle = $m*6;
$hour_angle = $h*30 + (($m*30) / 60);

$dom = new DOMDocument();
$dom->validateOnParse = true;
$dom->loadXML(file_get_contents('0900.svg'));

$xpath = new DOMXPath($dom);
$xpath->registerNamespace('svg', 'http://www.w3.org/2000/svg');
$he = $xpath->query("//*[@id='h']")->item(0);
$me = $xpath->query("//*[@id='m']")->item(0);

$me->setAttribute('transform', "rotate($minute_angle 100 100)");
$he->setAttribute('transform', "rotate($hour_angle 100 100)");

$svgs = $dom->getElementsByTagName('svg');

header('Content-Type: image/svg+xml');
header('Cache-Control: no-cache');
print $dom->saveXML($svgs[0]);
