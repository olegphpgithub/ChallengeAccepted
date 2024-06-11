<?php
    class SchoolTable
    {
        private $operator_01;
        private $operator_02;
        private $action;

        public function __construct()
        {
            $this->operator_01 = rand(501, 999);
            $this->operator_02 = rand(101, 500);
            $this->action = rand(0, 1);
        }

        public function draw()
        {
            echo '<table style="border-collapse: collapse; border: 0px none #fff;">';
            echo '    <tr>';
            echo '        <td rowspan="2">'.($this->action == 0 ? '&mdash;' : '+').'</td>';
            echo '        <td>'.$this->operator_01.'</td>';
            echo '    </tr>';
            echo '    <tr>';
            echo '        <td>'.$this->operator_02.'</td>';
            echo '    </tr>';
            echo '    <tr>';
            echo '        <td colspan="2" style="border-top: solid;">&nbsp;</td>';
            echo '    </tr>';
            echo '</table>';
        }
    };
?>
<html>
    <head>
        <style>
            td
            {
                border: 0px none #fff;
                font-size: 16pt;
                padding: 10px;
                font-family: 'Courier New', Courier, monospace;
            }
            td.answer
            {
                width: 40pt;
            }
        </style>
    </head>
    <body>
        <table style="border-collapse: collapse; border: 0px none #fff;">
        <?php
            for ($r = 0; $r<6; $r++)
            {
                echo '<tr>';
                for ($c = 0; $c<7; $c++)
                {
                    echo '<td>';
                    $st = new SchoolTable();
                    $st->draw();
                    echo '</td>';
                }
                echo '</tr>';
            }
        ?>
        </table>
    </body>
</html>