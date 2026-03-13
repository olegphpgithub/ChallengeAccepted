<?php

include_once('base.inc');

$h = rand(12, 23);
$m = rand(0, 59);
$style = 'white';
$answer = '';
$base = '';
$question = '';
$task_text = '&nbsp;';
$right_count = 0;

$cmToM = new CmToM();
$task_text = $cmToM->ask();
$question = $cmToM->question();

if (array_key_exists('answer', $_REQUEST)
    && array_key_exists('question', $_REQUEST)
    && array_key_exists('base', $_REQUEST))
{
    if ($cmToM->check($_REQUEST['question'], $_REQUEST['answer'])) {
        $style = 'lightgreen';
        $answer = '';
        $right_count = intval($_REQUEST['right_count']) + 1;
    } else {
        $style = 'lightcoral';
        $answer = $_REQUEST['answer'];
        $question = intval($_REQUEST['question']);
        $cmToM = new CmToM($question);
        $task_text = $cmToM->ask();
    }
}

?>
<html>
    <head>
        <style>
            body { font-size: 1.5em; }
            input { font-size: 1.5em; }
        </style>
    </head>
    <body style="background-color: <?php echo $style; ?>;">
        <p><pre><?php echo $task_text?></pre></p>
        <form>
            <input type="hidden" name="base" value="<?php echo $base; ?>" />
            <input type="hidden" name="question" value="<?php echo $question; ?>" />
            <input type="hidden" name="right_count" value="<?php echo $right_count; ?>" />
            <input type="text" value="<?php echo $right_count; ?>" disabled />
            <br/>
            <input type="text" name="answer" value="<?php echo $answer; ?>" id="user_answer" autofocus /><br/>
            <input type="submit" />
        </form>
    </body>
</html>