// Task Scheduler

var leastInterval = function(tasks, n) {
    var freq = new Array(26);
    var lastUsed = new Array(26);
    lastUsed.fill(-1000);
    freq.fill(0);
    
    var size = tasks.length;
    
    tasks.forEach(function(val) {
        freq[val.charCodeAt(0) - 65]++;
    });
    
    var t = 1;
    while(size--) {
        var nextChar = -1;
        freq.forEach(function(val, i) {
            if(val > 0) {
                if(nextChar == -1) {
                    nextChar = i;
                } else {
                    var t1 = t - lastUsed[nextChar];
                    var t2 = t - lastUsed[i];
                    if((t1 <= n && t2 <= n) || (t1 > n && t2 > n)) {
                        if(freq[i] > freq[nextChar]) {
                            nextChar = i;
                        }
                    } else if(t1 < t2) {
                        nextChar = i;
                    }
                }
            }
        });
        freq[nextChar]--;
        if(lastUsed[nextChar] == Number.MIN_VALUE) {
            lastUsed[nextChar] = t;
        } else {
            if(t <= (lastUsed[nextChar] + n)) {
                t = lastUsed[nextChar] + n + 1;
            }
            lastUsed[nextChar] = t;
        }
        t++;
    }
    return t - 1;
};