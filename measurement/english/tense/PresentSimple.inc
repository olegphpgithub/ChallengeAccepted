<?php

include_once('base.inc');

class PresentSimple extends Base implements Model {

    public $sentences = [];

    public function __construct($custom = NULL)
    {
        $this->question = $custom;
        $this->sentences[] = ['ru' => 'Я учучь в школе.', 'en' => 'I learn at school.'];
        $this->sentences[] = ['ru' => 'Я не учучь в школе.', 'en' => 'I do not learn at school.'];
        $this->sentences[] = ['ru' => 'Учучь ли я в школе.', 'en' => 'Do I learn at school.'];
    }

    public function ask() {
        $this->generate();
        return $this->sentences[$this->question]['ru'];
    }

    public function generate() {
        if ($this->question == NULL) {
            $this->question = rand(0, count($this->sentences) - 1);
        }
    }

    public function check($request, $response) {
        if ($this->sentences[$request]['en'] == $response) {
            return true;
        } else {
            return false;
        }
    }
}