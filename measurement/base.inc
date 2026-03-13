<?php

interface Model {
    public function generate();
    public function ask();
    public function question();
    public function check($request, $response);
}

class Base {
    public $complexity = 1;
}

class MToCM implements Model {

    private $question = NULL;

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            $this->question = rand(1, 90);
        }
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' метров в сантиметры.';
    }

    public function question()
    {
        return $this->question;
    }

    public function check($request, $response)
    {
        $m = intval($request);
        $cm = intval($response);
        if (($m * 100) == $cm) {
            return true;
        }
        else {
            return false;
        }
    }
}

class KmToM implements Model {

    private $question = NULL;

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            $this->question = rand(50, 200);
        }
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' километры в метры.';
    }

    public function question()
    {
        return $this->question;
    }

    public function check($request, $response)
    {
        $km = intval($request);
        $m = intval($response);
        if (($km * 1000) == $m) {
            return true;
        }
        else {
            return false;
        }
    }
}

class MmToCm implements Model {

    private $question = NULL;

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            $this->question = rand(50, 500);
            $this->question -= $this->question % 10;
        }
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' миллиметров в сантиметры.';
    }

    public function question()
    {
        return $this->question;
    }

    public function check($request, $response)
    {
        $mm = intval($request);
        $cm = intval($response);
        if (($cm * 10) == $mm) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Centimeter2Meter extends Base implements Model {

    private $question = NULL;

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            if ($this->complexity == 1) {
                $this->question = rand(100, 9000);
                $this->question -= $this->question % 100;
            } else {
                $branch = rand(0, 2);
                switch ($branch) {
                case 0:
                    $this->question = rand(1, 9);
                break;
                case 1:
                    $this->question = rand(1, 999);
                break;
                case 2:
                    $this->question = rand(1, 9999);
                    $this->question -= $this->question % 10;
                break;
                }
            }
        }
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' сантиметров в метры.';
    }

    public function question()
    {
        return $this->question;
    }

    public function check($request, $response)
    {
        $str = str_replace(",", ".", $response);
        if (!is_numeric($str)) {
            return false;
        }
        $centimeter = floatval($request);
        $meter = floatval($str);
        if (round(($meter * 100), 10) == $centimeter) {
            return true;
        }
        else {
            return false;
        }
    }
}


$knowledge = [];
$knowledge[] = "MToCM";
$knowledge[] = "KmToM";
$knowledge[] = "MmToCm";
$knowledge[] = "Centimeter2Meter";