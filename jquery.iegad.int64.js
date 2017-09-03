jQuery.toInt64 = function(buff) {
    if (buff.length !== 8) {
        return NaN;
    }

    var num = 0;
    
    for (var i = 0; i < 8; i++) {
        if (buff[i] > 255 || buff[i] < 0) {
            return NaN;
        }
        num += buff[i] << (8 * (8 - i - 1));
    }

    return num;
}