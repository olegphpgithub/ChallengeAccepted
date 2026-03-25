<?php

include_once('base.inc');

class Ton2Kilogram extends Kilo2One implements Model {

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
    }

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' тонн в килограммы.';
    }

    public function question()
    {
        return $this->question;
    }
}
