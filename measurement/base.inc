<?php

class CmToM {

    private $cm = NULL;

    public function __construct($question = NULL)
    {
        $this->cm = $question;
    }

    public function generate()
    {
        if ($this->cm == NULL) {
            $this->cm = rand(100, 9000);
            $this->cm -= $this->cm % 100;
        }
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->cm.' сантиметров в метры.';
    }

    public function question()
    {
        return $this->cm;
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

