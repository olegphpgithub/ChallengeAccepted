<?php

set_include_path(get_include_path().PATH_SEPARATOR.dirname(__FILE__));

include_once('base.inc');
include_once('weight.inc');
include_once('english/tense/PresentSimple.inc');

$style = 'white';
$answer = '';
$base = '';
$question = '';
$task_index = NULL;
$task_text = '&nbsp;';
$right_count = array_key_exists('right_count', $_REQUEST) ? $_REQUEST['right_count'] : 0;

$task_instance = NULL;

if (array_key_exists('answer', $_REQUEST)
    && array_key_exists('question', $_REQUEST)
    && array_key_exists('task_index', $_REQUEST))
{

    if (filter_var($_REQUEST['question'], FILTER_VALIDATE_INT) !== false) {
        $question = intval($_REQUEST['question']);
    } elseif (filter_var($_REQUEST['question'], FILTER_VALIDATE_FLOAT) !== false) {
        $question = floatval($_REQUEST['question']);
    }

    $task_index = $_REQUEST['task_index'];
    if (array_key_exists($task_index, $knowledge)) {
        $task_instance = new $knowledge[$task_index]($question);
        if ($task_instance->check($_REQUEST['question'], $_REQUEST['answer'])) {
            $style = 'lightgreen';
            $answer = '';
            $right_count++;
            $task_instance = NULL;
        } else {
            $style = 'lightcoral';
            $answer = $_REQUEST['answer'];
        }
    }
}

if ($task_instance == NULL) {
    $task_index = rand(0, sizeof($knowledge) - 1);
    $task_instance = new $knowledge[$task_index];
}

$task_text = $task_instance->ask();
$question = $task_instance->question();

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
            <input type="hidden" name="task_index" value="<?php echo $task_index; ?>" />
            <input type="hidden" name="question" value="<?php echo $question; ?>" />
            <input type="hidden" name="right_count" value="<?php echo $right_count; ?>" />
            <input type="text" value="<?php echo $right_count; ?>" disabled />
            <br/>
            <input type="text" name="answer" value="<?php echo $answer; ?>" autofocus /><br/>
            <input type="submit" />
        </form>
    </body>
</html>