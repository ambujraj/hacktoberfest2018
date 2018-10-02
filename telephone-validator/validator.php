<?php

/**
** Phone number validator
** based on the JS validator regex.
** In this example, 2-123-123-1231 will return true
*/

class PhoneNumber
{
    protected $phoneNumber;

    protected $regex = '/^\d(?:-\d{3}){3}\d$/';

    /**
     * PhoneNumber constructor.
     * @param $phoneNumber
     */
    public function __construct($phoneNumber)
    {
        $this->phoneNumber = $phoneNumber;
    }

    /**
     * Validate the passed in phone number
     * using the defined regex
     * @return bool
     */
    public function validate()
    {
        preg_match($this->regex, $this->phoneNumber, $matches);
        return !empty($matches);
    }
}

// Register a new phone number
$phoneNumber = new PhoneNumber('2-123-123-1231');

// validate the phone number, returning a boolean
$phoneNumber->validate();

// return a statement (string) based on the boolean value
echo $phoneNumber->validate() ? 'Valid phone number :-)' : 'Invalid phone number :-(';

