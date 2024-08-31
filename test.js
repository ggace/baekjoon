const readline = require("readline");

const rl = readline.createInterface({
  // 모듈을 이용해 입출력을 위한 인터페이스 객체 생성
  input: process.stdin,
  output: process.stdout,
});

var m, n, r;

rl.on("line", (line) => { 
    m = parseInt(line);
    
    rl.close();
});
rl.on("line", (line) => { 
    n = parseInt(line);
    
    rl.close();
});
rl.on("line", (line) => { 
    r = parseInt(line);
    
    rl.close();
});

console.log(m, n, r);