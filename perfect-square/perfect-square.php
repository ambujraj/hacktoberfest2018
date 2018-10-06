<?php

function perfect_square(int $number): bool {
    $perfect = false;
    $count = 1;
    $current = 1;

    while (!$perfect && $current < $number)
    {
        $current = $count * $count;
        $perfect = $current === $number;
        ++$count;
    }

    return $perfect;
}

$input = intval(fgets(STDIN));
printf("%s is %sa perfect square\n", $input, perfect_square($input) ? '' : 'not ');
