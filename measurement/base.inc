<?php

interface Model {
    public function generate();
    public function ask();
    public function question();
    public function check($request, $response);
}

class CmToM implements Model {

    private $question = NULL;

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function generate()
    {
        if ($this->question == NULL) {
            $this->question = rand(100, 9000);
            $this->question -= $this->question % 100;
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
        $cm = intval($request);
        $m = intval($response);
        if (($m * 100) == $cm) {
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

$knowledge = [];
$knowledge[] = "CmToM";
$knowledge[] = "MToCM";
$knowledge[] = "KmToM";
$knowledge[] = "MmToCm";