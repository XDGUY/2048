let brd;

function check(x, y, arr){
    return arr[x][y]===0;
}

function pusharr(pushArr, n, x, y){
    pushArr[x][y]=n;
}

function ifNear(first, next){
    return first==next && first!==0;
}

function getRandomInt(max){  //cor
    return Math.floor(Math.random()*Math.floor(max));
}

function setup(){  //cor
    createCanvas(400, 400);
    brd = initialize();
    pusharr(brd, 2, 3, 0);
    pusharr(brd, 4, 2, 0);
    pusharr(brd, 5, 1, 2)
    console.table(brd);
}

function initialize(){
    return [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
      ];
}

function randomPush(times){  //cor
    let n, x, y;
    var count=0;
    while (count<times) {
        x=getRandomInt(4);
        y=getRandomInt(4);
        n=random(1);
        if(check(x, y, brd)){
            n<0.5 ? pusharr(brd, 2, x, y) : pusharr(brd, 4, x, y);
            count++;
        }
    }
    
}

function mvRl(RlArr){
    let save=0;
    let savearr=initialize();
    for(let i=0;i<=3;i++){
        for(let j=0;j<=3;j++){
            if(!check(j,i,RlArr)){
                pusharr(savearr,brd[j][i],save, i);
                console.log("save b4 is" + save)
                console.table(savearr);
                save++;
                console.log(save);
            }
        }
        save=0;
    }
    console.table(RlArr);
    console.table(savearr);
    return savearr;
}

function keyPressed(){
    if(key=='a'){
        brd=mvRl(brd);
    }
}

function drawBrd(){  //cor
    let w=100;
    for(let i=0;i<=3;i++){
        for(let j=0;j<=3;j++){
            noFill();
            strokeWeight(2);
            stroke("#34be5b");
            rect(j*w, i*w, w, w);
            let val = brd[j][i];
            if(!check(j, i, brd)){
                textAlign(CENTER, CENTER);
                textSize(64);
                fill(0);
                noStroke();
                //text(j + ',' + i, j*w+w/2, i*w+w/2);
                text(val, j*w+w/2, i*w+w/2);
            }
        }
    }
}

function draw(){  //cor
    background(255);
    drawBrd();
}