<?php

include_once('base.inc');

class Ton2Kilogram extends Mega2Kilo implements Model {
    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' тонн в килограммы.';
    }
}

class Kilogram2Ton extends Kilo2Mega implements Model {

    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' килограмм в тонны.';
    }
}


class Kilogram2Gram extends Mega2Kilo implements Model {
    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' килограмм в граммы.';
    }
}

class Gram2Kilogram extends Kilo2Mega implements Model {
    public function ask()
    {
        $this->generate();
        return 'Переведи '.$this->question.' грамм в килограммы.';
    }
}