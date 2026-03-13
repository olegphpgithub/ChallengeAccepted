<?php

$h = rand(12, 23);
$m = rand(0, 59);
$style = 'white';
$user_answer = '';
$right_count = 0;


if (array_key_exists('user_answer', $_REQUEST)
    && array_key_exists('right_answer', $_REQUEST))
{
    if ($_REQUEST['user_answer'] == $_REQUEST['right_answer']) {
        $style = 'lightgreen';
        $user_answer = '';
        $right_count = intval($_REQUEST['right_count']) + 1;
    } else {
        $style = 'lightcoral';
        $user_answer = $_REQUEST['user_answer'];
        $right_count = intval($_REQUEST['right_count']);
        if (preg_match('/(\d{2}):(\d{2})/', $_REQUEST['right_answer'], $matches)) {
            $h = $matches[1];
            $m = $matches[2];
        }
    }
}

$url = 'http://192.168.11.143/dial/dial.php?h='.$h.'&m='.$m;
$right_answer = sprintf('%02d:%02d', $h, $m);

?>
<html>
    <head>
        <style>
            body { font-size: 1.5em; }
            input { font-size: 1.5em; }
        </style>
    </head>
    <body style="background-color: <?php echo $style; ?>;">
        <img src="<?php echo $url; ?>" />33
        <form>
            <input type="hidden" name="right_answer" value="<?php echo $right_answer; ?>" />
            <input type="hidden" name="right_count" value="<?php echo $right_count; ?>" />
            <input type="text" value="<?php echo $right_count; ?>" disabled />
            <br/>
            <input type="text" name="user_answer" value="<?php echo $user_answer; ?>" id="user_answer" autofocus /><br/>
            <input type="submit">
        </form>
    </body>
</html>