<html>
    <head>
        <style>
            td
            {
                border: 1px solid #ddd;
                font-size: 16pt;
                padding: 10px;
            }
            td.answer
            {
                width: 40pt;
            }
        </style>
    </head>
    <body>
        <table style="border-collapse: collapse; border: 1px solid #ddd;">
<?php
            for ($row=0; $row<20; $row++)
            {
                echo '<tr>';
                for ($col=0; $col<3; $col++)
                {
                    echo '<td>'.rand(50, 100).'</td>';
                    echo '<td>-</td>';
                    $oper2 = 0;
                    while(true)
                    {
                        $oper2 = rand(10, 49);
                        $remain = $oper2 % 10;
                        if ($remain > 5)
                            break;
                    }
                    echo '<td>'.$oper2.'</td>';
                    echo '<td>=</td>';
                    echo '<td class="answer">&nbsp;</td>';
                }
                echo '</tr>';
            }
?>
</html>