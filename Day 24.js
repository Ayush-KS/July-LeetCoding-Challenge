// All Paths From Source to Target

var dfs = function(graph, paths, curr, visited, i) {
    var n = graph.length;
    if(i == n - 1) {
        var dup = curr.slice(0);
        paths.push(dup);
        return;
    }
    
    graph[i].forEach(function(val) {
        curr.push(val);
        dfs(graph, paths, curr, visited, val);
        curr.pop();
    });
}

var allPathsSourceTarget = function(graph) {
    var paths = [];
    var curr = [0];
    
    dfs(graph, paths, curr, visited, 0);
    return paths;
};