let brd;

function getRandomInt(max){
    return Math.floor(Math.random()*Math.floor(max));
}

function setup(){
    createCanvas(400, 400);
    brd = [
        [0,0,0,0],
        [0,0,0,0],
        [0,0,0,0],
        [0,0,0,0]
    ];
    console.table(brd);
    //randomPush();
    console.table(brd);
}

function pushbrd(n,x,y){
    brd[x][y]=n;
}

function checkbrd(x, y){
    return brd[x][y]===0;
}

function randomPush(){
    let n, x, y;
    var count=0;
    while (count!=2) {
        x=getRandomInt(4);
        y=getRandomInt(4);
        n=random(1);
        if(checkbrd(x,y)){
            n<0.5 ? pushbrd(2, x, y) : pushbrd(4, x, y);
            count++;
        }
    }
    
}

function drawBrd(){
    let w=100;
    pushbrd(2, 3, 0);
    pushbrd(4, 2, 0);
    for(let i=0;i<=3;i++){
        for(let j=0;j<=3;j++){
            noFill();
            strokeWeight(2);
            stroke("#34be5b");
            rect(j*w, i*w, w, w);
            let val = brd[j][i];
            if(!checkbrd(j,i)){
                textAlign(CENTER, CENTER);
                textSize(64);
                fill(0);
                noStroke();
                text(val, j*w+w/2, i*w+w/2);
            }
        }
    }
}

function draw(){
    background(255);
    drawBrd();
}