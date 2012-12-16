# php-errno

missing errno handling for php.

````
<?php

function example()
{
    $limit = 10;
    $attempts = 0;
    
    do {
        $attempts++;
        $errno = sum_function();
        if ($errno == Errno\EWOULDBLOCK::ERRNO) {
            usleep(5000);
            continue;
        }
    } while ($attempts <= $limit);
}
````
