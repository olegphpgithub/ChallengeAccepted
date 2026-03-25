<?php

interface Model {
    public function generate();
    public function ask();
    public function question();
    public function check($request, $response);
}

class Base {
    public $complexity = 2;
    protected $question = NULL;
    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }
    public function ask() {}
    public function question()
    {
        return $this->question;
    }
}

class Mega2Kilo extends Base implements Model {
    public function generate()
    {
        if ($this->question == NULL) {
            if ($this->complexity == 1) {
                $this->question = rand(50, 200);
            }
            else {
                $branch = rand(0, 2);
                switch ($branch) {
                case 0:
                    $this->question = rand(1, 99);
                    $this->question = round($this->question / 10, 1);
                    break;
                case 1:
                    $this->question = rand(1, 999);
                    $this->question = round($this->question / 100, 2);
                    break;
                case 2:
                    $this->question = rand(1, 99);
                    $this->question = round($this->question / 1000, 3);
                    break;
                }
            }
        }
    }

    public function check($request, $response)
    {
        $str = str_replace(",", ".", $response);
        if (!is_numeric($str)) {
            return false;
        }
        $kilometer = floatval($request);
        $meter = floatval($str);
        if (round(($kilometer * 1000), 10) == $meter) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Kilo2Mega extends Base implements Model {
    public function generate()
    {
        if ($this->question == NULL) {
            if ($this->complexity == 1) {
                $this->question = rand(1000, 90000);
                $this->question -= $this->question % 1000;
            }
            elseif ($this->complexity == 2) {
                $branch = rand(0, 3);
                switch ($branch) {
                case 0:
                    $this->question = rand(1, 9);
                break;
                case 1:
                    $this->question = rand(1, 99);
                    $this->question -= $this->question % 10;
                break;
                case 2:
                    $this->question = rand(1, 999);
                break;
                case 3:
                    $this->question = rand(1, 9999);
                    $this->question -= $this->question % 10;
                break;
                }
            }
            else {
                $branch = rand(0, 2);
                switch ($branch) {
                case 0:
                    $this->question = rand(1, 99);
                    $this->question = round($this->question / 100, 2);
                    break;
                case 1:
                    $this->question = rand(1, 99);
                    $this->question = round($this->question / 1000, 3);
                    break;
                case 2:
                    $this->question = rand(1, 99);
                    $this->question = round($this->question / 10000, 4);
                    break;
                }
            }
        }
    }

    public function check($request, $response)
    {
        $str = str_replace(",", ".", $response);
        if (!is_numeric($str)) {
            return false;
        }
        $meter = floatval($request);
        $kilometer = floatval($str);
        if (round(($kilometer * 1000), 10) == $meter) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Deca2Kilo extends Base implements Model {
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

class Kilometer2Meter extends Mega2Kilo implements Model {

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' километры в метры.';
    }

    public function question()
    {
        return $this->question;
    }
}

class Millimeter2Centimeter extends Base implements Model {

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            if ($this->complexity == 1) {
                $this->question = rand(50, 500);
                $this->question -= $this->question % 10;
            }
            else {
                $branch = rand(0, 1);
                switch ($branch) {
                case 0:
                    $this->question = rand(1, 9);
                break;
                case 1:
                    $this->question = rand(1000, 9999);
                break;
                }
            }
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
        $str = str_replace(",", ".", $response);
        if (!is_numeric($str)) {
            return false;
        }
        $millimeter = floatval($request);
        $centimeter = floatval($str);
        if (round(($centimeter * 10), 10) == $millimeter) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Centimeter2Meter extends Deca2Kilo implements Model {

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
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
}

class Meter2Kilometer extends Kilo2Mega implements Model {

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' метров в километры.';
    }

    public function question()
    {
        return $this->question;
    }
}

$knowledge = [];
# $knowledge[] = "MToCM";
# $knowledge[] = "Kilometer2Meter";
// $knowledge[] = "Millimeter2Centimeter";
// $knowledge[] = "Centimeter2Meter";
// $knowledge[] = "Meter2Kilometer";

$knowledge[] = "Ton2Kilogram";
$knowledge[] = "Kilogram2Ton";
$knowledge[] = "Kilogram2Gram";
$knowledge[] = "Gram2Kilogram";
