// Add Digits

var addDigits = function(num) {
    if(!num)
        return 0;
    if(num % 9 == 0)
        return 9;
    return num % 9;
};